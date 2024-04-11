#include <bits/stdc++.h>

using ll = long long;
const int N = 40;

ll dp[N][2][2][2];

void solve(){
    memset(dp, 0, sizeof(dp));
    int l, r;
    scanf("%d%d", &l, &r);
    dp[31][0][0][0] = 1;
    for (int i = 30; i >= 0; -- i){
        int lbit = l >> i & 1, rbit = r >> i & 1;
        for (int j = 0; j < 2; ++ j){
            for (int k = 0; k < 2; ++ k){
                for (int two = 0; two < 2; ++ two){
                    for (int u = 0; u < 2; ++ u){
                        for (int v = 0; v < 2; ++ v){
                            if (u == 1 && v == 1){
                                continue;
                            }
                            if (j == 0 && u < lbit){
                                continue;
                            }
                            if (k == 0 && v > rbit){
                                continue;
                            }
                            if (two == 0 && u > v){
                                continue;
                            }
                            int nj = std::max(j, int(u > lbit));
                            int nk = std::max(k, int(v < rbit));
                            int ntwo = std::max(two, int(u < v));
                            dp[i][nj][nk][ntwo] += dp[i + 1][j][k][two];
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 2; ++ i){
        for (int j = 0; j < 2; ++ j){
            for (int k = 0; k < 2; ++ k){
                ans += dp[0][i][j][k];
            }
        }
    }
    ans *= 2;
    if (l == 0){
        -- ans;
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