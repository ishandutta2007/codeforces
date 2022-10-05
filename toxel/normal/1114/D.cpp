#include<bits/stdc++.h>

const int N = 5010;

int c[N];
int dp[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &c[i]);
        if (i && c[i] == c[i - 1]){
            -- i;
            -- n;
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        for (int j = 0; j < n; ++ j){
            dp[i][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j]);
            if (c[i] == c[j]){
                dp[i][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        ans = std::max(ans, dp[i + 1][i]);
    }
    printf("%d\n", n - ans - 1);
    return 0;
}