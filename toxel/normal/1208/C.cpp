#include <bits/stdc++.h>

const int N = 1010;

int ans[N][N];

int main(){
    int n;
    scanf("%d", &n);
    int now = 0;
    for (int i = 0; i < n / 2; ++ i){
        for (int j = 0; j < n / 2; ++ j){
            for (int u = 0; u < 2; ++ u){
                for (int v = 0; v < 2; ++ v){
                    ans[i * 2 + u][j * 2 + v] = now ++;
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            printf("%d%c", ans[i][j], " \n"[j == n - 1]);
        }
    }
    return 0;
}