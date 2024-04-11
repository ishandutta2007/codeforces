#include<bits/stdc++.h>

const int N = 1010;

int mat[N][N];

int main(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (n == 1){
        if (a != 1 || b != 1){
            puts("NO");
            return 0;
        }
        puts("YES");
        puts("0");
        return 0;
    }
    if (a != 1 && b != 1){
        puts("NO");
        return 0;
    }
    if (a == 1 && b == 1){
        if (n == 2 || n == 3){
            puts("NO");
            return 0;
        }
        for (int i = 0; i < n - 1; ++ i){
            mat[i][i + 1] = mat[i + 1][i] = 1;
        }
    }
    else{
        int max = std::max(a, b);
        for (int i = max - 1; i < n; ++ i){
            for (int j = max - 1; j < n; ++ j){
                if (i != j) mat[i][j] = 1;
            }
        }
        if (a == 1){
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < n; ++ j){
                    if (i != j) mat[i][j] = !mat[i][j];
                }
            }
        }
    }
    puts("YES");
    for (int i= 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            putchar('0' + mat[i][j]);
        }
        putchar('\n');
    }
    return 0;
}