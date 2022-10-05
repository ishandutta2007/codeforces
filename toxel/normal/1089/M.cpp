#include<bits/stdc++.h>

const int MAX = 100;

char s[MAX + 10][MAX + 10][MAX + 10];
int mat[MAX][MAX];

int main(){
    int x = MAX, y = MAX, z = 5;
    for (int i = 0; i < x; ++ i){
        for (int j = 0; j < y; ++ j){
            for (int k = 0; k < z; ++ k){
                s[i][j][k] = '.';
            }
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < n; ++ i){
        s[4 * i][MAX - 1][0] = '1' + i;
    }
    for (int i = 0; i < n - 1; ++ i){
        for (int j = 0; j < MAX; ++ j){
            for (int k = 0; k < 2; ++ k){
                s[4 * i + 3][j][k] = '#';
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 1; j <= 3; ++ j){
            s[4 * i + 1][4 * i + j][3 - j] = '#';
        }
        for (int j = 0; j < MAX; ++ j){
            s[j][4 * i + 1][2] = '#';
            s[j][4 * i][3] = s[j][4 * i][4] = '#';
            s[j][4 * i + 2][3] = s[j][4 * i + 2][4] = '#';
        }
        for (int j = 0; j < n; ++ j){
            if (i == j || mat[i][j]){
                s[4 * j + 1][4 * i + 2][3] = s[4 * j + 1][4 * i + 2][4] = '.';
            }
        }
    }
    printf("%d %d %d\n", x, y, z);
    for (int k = z - 1; k >= 0; -- k){
        for (int i = 0; i < x; ++ i){
            for (int j = 0; j < y; ++ j){
                putchar(s[i][j][k]);
            }
            puts("");
        }
        puts("");
    }
    return 0;
}