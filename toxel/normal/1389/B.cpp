#include <bits/stdc++.h>

using ll = long long;
const int N = 100010;
const int M = 6;

ll dp[N][M][2];
int a[N];

void solve(){
    int n, k, z;
    scanf("%d%d%d", &n, &k, &z);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; ++ i){
        memset(dp[i], 0, sizeof(dp[i]));
    }
    dp[0][0][0] = a[0];
    for (int i = 0; i <= z; ++ i){
         for (int j = 0; j < n - 1; ++ j){
             dp[j + 1][i][0] = std::max(dp[j + 1][i][0], dp[j][i][0] + a[j + 1]);
             dp[j + 1][i][0] = std::max(dp[j + 1][i][0], dp[j][i][1] + a[j + 1]);
         }
         if (i < z){
             for (int j = 0; j < n - 1; ++ j){
                 dp[j][i + 1][1] = dp[j + 1][i][0] + a[j];
             }
         }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j <= z; ++ j){
            if (i + 2 * j == k){
                ans = std::max(dp[i][j][0], ans);
                ans = std::max(dp[i][j][1], ans);
            }
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}