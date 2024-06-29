#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void open_file();
void edit_file();
void save_file();

char temp[MAX_SIZE];
char current[200];

int main() {
    int c;

    while (1) {
        printf("\n>>>>>> MAIN MENU <<<<<<\n");
        printf("1. Open the File\n");
        printf("2. Edit the File\n");
        printf("3. Save the File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        getchar();
        

        switch (c) {
            case 1:
                open_file();
                break;
            case 2:
                edit_file();
                break;
            case 3:
                save_file();
                break;
            case 4:
                printf("Exiting the text editor......\n");
                return 0;
            default:
                printf("Invalid choice!!!\n");
        }
    }

    return 0;
}


void open_file() {
    FILE *fp;
    printf("Enter file name to open: ");
    if (fgets(current, sizeof(current), stdin) == NULL) {
        printf("Error reading the file name....\n");
        return;
    }
    current[strcspn(current, "\n")] = '\0';  // Remove the trailing newline

    fp = fopen(current, "r");
    if (fp == NULL) {
        printf("Error opening the file %s....\n", current);
        return;
    }

    size_t no = fread(temp, 1, MAX_SIZE - 1, fp);
    if (ferror(fp)) {
        printf("Error reading file %s....\n", current);
        fclose(fp);
        return;
    }
    temp[no] = '\0';

    fclose(fp);
    printf("File opened successfully.\n");
    printf("Content of the file:\n%s\n", temp);
}

void save_file() {
    FILE *fp;

    if (strlen(current) == 0) {
        printf("Error...\n");
        return;
    }

    fp = fopen(current, "w");
    if (fp == NULL) {
        printf("Error opening the file.....\n", current);
        return;
    }

    fwrite(temp, 1, strlen(temp), fp);
    fclose(fp);
    printf("File successfully saved.\n", current);
}



void edit_file() {
    printf("Enter content to the file:\n");
    fgets(temp , MAX_SIZE  , stdin);
}

