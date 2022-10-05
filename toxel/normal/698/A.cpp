#include<bits/stdc++.h>

const int N = 110;

int a[N];
int n;
int dp[N][3];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    memset(dp, -1, sizeof(dp));
    dp[0][2] = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < 2; ++ j){
            if (a[i] >> j & 1){
                if (dp[i - 1][j ^ 1] != -1){
                    dp[i][j] = std::max(dp[i - 1][j ^ 1] + 1, dp[i][j]);
                }
                if (dp[i - 1][2] != -1){
                    dp[i][j] = std::max(dp[i - 1][2] + 1, dp[i][j]);
                }
            }
        }
        for (int j = 0; j <= 2; ++ j){
            dp[i][2] = std::max(dp[i - 1][j], dp[i][2]);
        }
    }
    int max = -1;
    for (int j = 0; j <= 2; ++ j){
        max = std::max(max, dp[n][j]);
    }
    printf("%d\n", n - max);
    return 0;
}