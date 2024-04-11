#include<bits/stdc++.h>

const int N = 1010;
const int moder = 998244353;

int dp[N][N << 1][4];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    dp[0][1][0] = dp[0][2][1] = dp[0][2][2] = dp[0][1][3] = 1;
    for (int i = 1; i < n; ++ i){
        for (int j = 0; j < N << 1; ++ j){
            for (int k = 0; k < 4; ++ k){
                if (!dp[i - 1][j][k]) continue;
                for (int u = 0; u < 4; ++ u){
                    int add = __builtin_popcount(k ^ u);
                    if ((u == 0 || u == 3) && add){
                        -- add;
                    }
                    dp[i][j + add][u] += dp[i - 1][j][k];
                    dp[i][j + add][u] -= dp[i][j + add][u] >= moder ? moder : 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; ++ i){
        ans += dp[n - 1][k][i];
        ans -= ans >= moder ? moder : 0;
    }
    printf("%d\n", ans);
    return 0;
}