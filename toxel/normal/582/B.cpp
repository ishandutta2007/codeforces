#include<bits/stdc++.h>

const int N = 110;
const int M = 310;

int a[N];
int dp[M][M], ans[M][M];
int tmp[M][M];

void mult(int (*a)[M], int (*b)[M]){
    for (int i = 0; i < M; ++ i){
        for (int j = i; j < M; ++ j){
            tmp[i][j] = 0;
            for (int k = i; k <= j; ++ k){
                tmp[i][j] = std::max(tmp[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    for (int i = 0; i < M; ++ i){
        for (int j = i; j < M; ++ j){
            a[i][j] = tmp[i][j];
        }
    }
}

int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < M; ++ i){
        for (int j = 0; j < n; ++ j){
            int max = 0;
            for (int k = i; k <= a[j]; ++ k){
                max = std::max(max, dp[i][k]);
            }
            dp[i][a[j]] = max + 1;
        }
    }
    for ( ; t > 0; t >>= 1){
        if (t & 1){
            mult(ans, dp);
        }
        mult(dp, dp);
    }
    int max = 0;
    for (int i = 0; i < M; ++ i){
        max = std::max(max, ans[0][i]);
    }
    printf("%d\n", max);
    return 0;
}