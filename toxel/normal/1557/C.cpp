#include <bits/stdc++.h>

const int moder = int(1e9) + 7;

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * a * ret % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

const int N = 200010;

int dp[N][3];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    if (k == 0){
        puts("1");
        return;
    }
    int cnt[2][2];
    cnt[1][0] = 1 - (n & 1);
    cnt[1][1] = n & 1;
    cnt[0][0] = powermod(2, n - 1) - cnt[1][0];
    cnt[0][1] = powermod(2, n - 1) - cnt[1][1];
    memset(dp, 0, sizeof(dp));
    dp[k][1] = 1;
    for (int i = k - 1; i >= 0; -- i){
        for (int j = 0; j < 3; ++ j){
            for (int u = 0; u < 2; ++ u){
                for (int v = 0; v < 2; ++ v){
                    int nj = j == 1 ? (u == v ? 1 : u > v ? 2 : 0) : j;
                    dp[i][nj] = (dp[i][nj] + 1ll * dp[i + 1][j] * cnt[u][v]) % moder;
                }
            }
        }
    }
    int ans = (dp[0][1] + dp[0][2]) % moder;
    ans += ans < 0 ? moder : 0;
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