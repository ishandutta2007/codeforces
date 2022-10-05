#include <bits/stdc++.h>

const int N = 5010;

bool dp[N][N];
int p[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= 2 * n + 5; ++ i){
        memset(dp[i], 0, sizeof(dp[i]));
    }
    for (int i = 1; i <= 2 * n; ++ i){
        scanf("%d", &p[i]);
    }
    dp[1][1] = true;
    int prev = p[1];
    for (int i = 2; i <= 2 * n; ++ i){
        bool big = p[i] > prev;
        if (p[i] > prev){
            prev = p[i];
        }
        for (int j = 0; j <= 2 * n; ++ j){
            if (!dp[i - 1][j]){
                continue;
            }
            dp[i][j + 1] = true;
            if (big){
                dp[i][i - j] = true;
            }
        }
    }
    puts(dp[2 * n][n] ? "YES" : "NO");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}