#include<bits/stdc++.h>

const int N = 1000010;

int cnt[N];
int dp[N][3][3];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        ++ cnt[x];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= m; ++ i){
        for (int j = 0; j < 3; ++ j){
            for (int k = 0; k < 3; ++ k){
                if (dp[i - 1][j][k] == -1) continue;
                for (int u = 0; u <= j; ++ u){
                    for (int v = 0; v <= k; ++ v){
                        for (int r = 0; r < 3; ++ r){
                            if (u + v + r > cnt[i]) continue;
                            int &w = dp[i][r][u];
                            w = std::max(w, dp[i - 1][j][k] + v + (cnt[i] - u - v - r) / 3);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; ++ i){
        for (int j = 0; j < 3; ++ j){
            ans = std::max(ans, dp[m][i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}