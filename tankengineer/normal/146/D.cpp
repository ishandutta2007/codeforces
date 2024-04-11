#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int c4, c7, c47, c74;
    scanf("%d%d%d%d", &c4, &c7, &c47, &c74);
    //4-7-4-7
    if (c47 == c74 + 1) {
        int b4 = c47, b7 = c47;
        if (c4 >= b4 && c7 >= b7) {
            for (int i = 0; i <= c4 - b4; ++i) {
                printf("4");
            }
            for (int i = 0; i < c74; ++i) {
                printf("74");
            }
            for (int i = 0; i <= c7 - b7; ++i) {
                printf("7");
            }
            printf("\n");
            return 0;
        }
    }
    //4-7-4
    if (c47 == c74) {
        int b4 = c47 + 1, b7 = c74;
        if (c4 >= b4 && c7 >= b7) {
            for (int i = 0; i <= c4 - b4; ++i) {
                printf("4");
            }
            for (int i = 0; i < c74 - 1; ++i) {
                printf("74");
            }
            for (int i = 0; i <= c7 - b7; ++i) {
                printf("7");
            }
            printf("4\n");
            return 0;
        }
    }
    //7-4-7
    if (c47 == c74) {
        int b4 = c47, b7 = c74 + 1;
        if (c4 >= b4 && c7 >= b7) {
            printf("7");
            --c74, --c7, --b7;
            for (int i = 0; i <= c4 - b4; ++i) {
                printf("4");
            }
            for (int i = 0; i < c74; ++i) {
                printf("74");
            }
            for (int i = 0; i <= c7 - b7; ++i) {
                printf("7");
            }
            printf("\n");
            return 0;
        }
    }
    //7-4-7-4
    if (c74 == c47 + 1) {
        int b4 = c47 + 1, b7 = c74;
        if (c4 >= b4 && c7 >= b7) {
            printf("7");
            --c74, --c7, --b7;
            for (int i = 0; i <= c4 - b4; ++i) {
                printf("4");
            }
            for (int i = 0; i < c74 - 1; ++i) {
                printf("74");
            }
            for (int i = 0; i <= c7 - b7; ++i) {
                printf("7");
            }
            printf("4\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}