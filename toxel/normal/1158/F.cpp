#include <bits/stdc++.h>

const int N = 3010;
const int moder = 998244353;
const int MAX = 12;
typedef unsigned long long ll;
const ll INF = (ll) 1.6e19;

ll dp[N][N];
int trans[N][N], cnt[N];
int ans[N];
int power[N], inv[N];
int a[N];
int dp1[N][1 << MAX];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int main(){
    power[0] = 0;
    for (int i = 1; i < N; ++ i){
        power[i] = (2 * power[i - 1] + 1) % moder;
        inv[i] = powermod(power[i], moder - 2);
    }
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int num = n / c;
    if (c > MAX){
        for (int i = 0; i < n; ++ i){
            memset(cnt, 0, sizeof(cnt));
            int undone = c;
            int mult = 1;
            for (int j = i; j < n; ++ j){
                if (!cnt[a[j]]){
                    -- undone;
                }
                ++ cnt[a[j]];
                if (undone == 0){
                    if (cnt[a[j]] == 1){
                        for (int k = 1; k <= c; ++ k){
                            mult = 1ll * mult * power[cnt[k]] % moder;
                        }
                    }
                    else{
                        mult = 1ll * mult * power[cnt[a[j]]] % moder * inv[cnt[a[j]] - 1] % moder;
                    }
                    trans[j][i] = mult;
                }
            }
            for (int j = n - 1; j > i; -- j){
                trans[j][i] = (trans[j][i] - 2ll * trans[j - 1][i]) % moder;
                trans[j][i] += trans[j][i] < 0 ? moder : 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= num; ++ j){
                for (int k = 0; k < i; ++ k){
                    dp[j][i] += dp[j - 1][k] * trans[i - 1][k];
                    if (dp[j][i] > INF){
                        dp[j][i] %= moder;
                    }
                }
                dp[j][i] %= moder;
            }
        }
        for (int i = 0; i <= n; ++ i){
            for (int j = 0; j <= num; ++ j){
                ans[j] = (ans[j] + 1ll * dp[j][i] * (power[n - i] + 1)) % moder;
            }
        }
        for (int i = 0; i < num; ++ i){
            ans[i] -= ans[i + 1];
            ans[i] += ans[i] < 0 ? moder : 0;
        }
        for (int i = 0; i <= n; ++ i){
            if (i == 0){
                -- ans[i];
                ans[i] += ans[i] < 0 ? moder : 0;
            }
            printf("%d%c", ans[i], " \n"[i == n]);
        }
        return 0;
    }
    dp1[0][0] = 1;
    for (int i = 0; i < n; ++ i){
        int bit = 1 << (a[i] - 1);
        for (int j = num; j >= 0; -- j){
            for (int k = (1 << c) - 2; k >= 0; -- k){
                int &u = dp1[j][k | bit];
                u += dp1[j][k];
                u -= u >= moder ? moder : 0;
            }
            dp1[j + 1][0] += dp1[j][(1 << c) - 1];
            dp1[j + 1][0] -= dp1[j + 1][0] >= moder ? moder : 0;
            dp1[j][(1 << c) - 1] = 0;
        }
    }
    for (int i = 0; i <= n; ++ i){
        int ret = 0;
        for (int j = 0; j < (1 << c) - 1; ++ j){
            ret += dp1[i][j];
            ret -= ret >= moder ? moder : 0;
        }
        if (i == 0){
            -- ret;
            ret += ret < 0 ? moder : 0;
        }
        printf("%d%c", ret, " \n"[i == n]);
    }
    return 0;
}