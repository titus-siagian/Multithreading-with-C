#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printMessage(void *arg) {
    char *message = (char *)arg;
    printf("%s\n", message);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    char *message1 = "Thread 1: Hello from thread 1!";
    char *message2 = "Thread 2: Hello from thread 2!";

    // Membuat thread pertama
    if (pthread_create(&thread1, NULL, printMessage, (void *)message1)) {
        printf("Error creating thread 1!\n");
        return 1;
    }

    // Membuat thread kedua
    if (pthread_create(&thread2, NULL, printMessage, (void *)message2)) {
        printf("Error creating thread 2!\n");
        return 1;
    }

    // Menunggu kedua thread selesai
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Program selesai.\n");
    return 0;
}
