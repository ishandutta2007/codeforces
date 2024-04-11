#include <bits/stdc++.h>

const int N = 1010;

char s[N][N];
int dp[N];

void solve(){
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    dp[0] = 0, dp[1] = x;
    for (int i = 2; i < N; ++ i){
        dp[i] = std::min(dp[i - 1] + x, dp[i - 2] + y);
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
        int pre = -1;
        for (int j = 0; j <= m; ++ j){
            if (s[i][j] == '*' || j == m){
                ans += dp[j - pre - 1];
                pre = j;
            }
        }
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}