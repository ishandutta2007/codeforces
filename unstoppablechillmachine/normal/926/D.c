#include<stdio.h>

char arr[10][10];
int f[10][10];

int main() {
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 7; j++) {
            scanf("%c", &arr[i][j]);
        }
        scanf("%c\n", &arr[i][8]);
    }    
    f[1][1] = 3;
    f[3][1] = 2;
    f[5][1] = 1;
    f[1][4] = 4;
    f[3][4] = 3;
    f[5][4] = 2;
    f[1][7] = 3;
    f[3][7] = 2;
    f[5][7] = 1;
    int best = 0, ans1, ans2;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 8; j++) {
            if (j == 3 || j == 6) {
                continue;
            }
            int ii = i, jj = j;
            if (ii % 2 == 0) ii--;
            if (jj == 2 || jj == 5 || jj == 8) jj--;
            if (arr[i][j] == '.' && f[ii][jj] > best) {
                best = f[ii][jj];
                ans1 = i;
                ans2 = j;
            }
        }
    }
    arr[ans1][ans2] = 'P';
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 8; j++) {
            printf("%c", arr[i][j]);
        }
        printf("%c", '\n');
    }
}