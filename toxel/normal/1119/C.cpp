#include <bits/stdc++.h>

const int N = 510;

int a[N][N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            int x;
            scanf("%d", &x);
            a[i][j] ^= x;
        }
    }
    for (int i = 0; i < n; ++ i){
        int sum = 0;
        for (int j = 0; j < m; ++ j){
            sum ^= a[i][j];
        }
        if (sum){
            puts("No");
            return 0;
        }
    }
    for (int j = 0; j < m; ++ j){
        int sum = 0;
        for (int i = 0; i < n; ++ i){
            sum ^= a[i][j];
        }
        if (sum){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}