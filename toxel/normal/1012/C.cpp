#include<bits/stdc++.h>

const int N = 5010;
const int INF = 0x7f7f7f7f;

int dp[N][N >> 1][4];
int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; ++ i){
        for (int j = 0; j < N >> 1; ++ j){
            if (dp[i - 1][j][0] != INF){
                dp[i][j][0] = std::min(dp[i][j][0], dp[i - 1][j][0]);
                dp[i][j + 1][1] = std::min(dp[i][j + 1][1], dp[i - 1][j][0] + std::max(0, a[i - 1] - (a[i] - 1)));
            }
            if (dp[i - 1][j][1] != INF){
                dp[i][j][2] = std::min(dp[i][j][2], dp[i - 1][j][1] + std::max(0, a[i] - (a[i - 1] - 1)));
            }
            if (dp[i - 1][j][2] != INF){
                dp[i][j][0] = std::min(dp[i][j][0], dp[i - 1][j][2]);
                dp[i][j + 1][1] = std::min(dp[i][j + 1][1], dp[i - 1][j][2] - std::max(0, a[i - 1] - (a[i - 2] - 1)) + std::max(0, a[i - 1] - (std::min(a[i - 2], a[i]) - 1)));
            }
        }
    }
    for (int i = 1; i <= n + 1 >> 1; ++ i){
        int min = INT_MAX;
        for (int j = 0; j < 3; ++ j){
            min = std::min(min, dp[n][i][j]);
        }
        printf("%d%c", min, " \n"[i == (n + 1 >> 1)]);
    }
    return 0;
}