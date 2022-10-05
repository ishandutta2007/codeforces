#include<bits/stdc++.h>

const int N = 160;
const int M = N * N;

int dp[N][M];
int q[N];

int main(){
    int n, k, s;
    scanf("%d%d%d", &n, &k, &s);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1, x; i <= n; ++ i){
        scanf("%d", &x);
        for (int j = i - 1; j >= 0; -- j){
            for (int kk = 0; kk < M; ++ kk){
                if (dp[j][kk] == -1) continue;
                int &u = dp[j + 1][kk + i];
                if (u == -1 || u > dp[j][kk] + x){
                    u = dp[j][kk] + x;
                }
            }
        }
    }
    int min = INT_MAX;
    for (int i = 0; i < M; ++ i){
        if (dp[k][i] == -1) continue;
        if (i - k * (k + 1) / 2 > s) break;
        min = std::min(min, dp[k][i]);
    }
    printf("%d\n", min);
    return 0;
}