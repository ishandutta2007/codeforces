#include <bits/stdc++.h>

using ll = long long;
const int moder = 998244353;
const int N = 200010;
const int BIT = 20;
const int BIT1 = 16;
const int BBIT = 36;

int dp[BBIT][1 << BIT1][BBIT];
int ans[N];

void add(int &a, int b){a += b; a -= a >= moder ? moder : 0;}

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

void print(int n, int m, int now){
    for (int i = 0; i <= m; ++ i){
        ans[i] = 1ll * ans[i] * powermod(2, n - now) % moder;
        printf("%d%c", ans[i], " \n"[i == m]);
    }
}

ll a[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    int now = 0;
    std::set <int> main_set;
    for (int i = 0; i < m; ++ i){
        for (int j = now; j < n; ++ j){
            if (a[j] >> i & 1){
                std::swap(a[now], a[j]);
                break;
            }
        }
        if (!(a[now] >> i & 1)){
            continue;
        }
        main_set.insert(i);
        for (int j = 0; j < n; ++ j){
            if (j == now){
                continue;
            }
            if (a[j] >> i & 1){
                a[j] ^= a[now];
            }
        }
        ++ now;
    }
    if (now <= BIT){
        for (int i = 0; i < 1 << now; ++ i){
            ll sum = 0;
            for (int j = 0; j < now; ++ j){
                if (i >> j & 1){
                    sum ^= a[j];
                }
            }
            ++ ans[__builtin_popcountll(sum)];
        }
        print(n, m, now);
        return 0;
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < now; ++ i){
        int value = 0;
        for (int j = 0; j < m; ++ j){
            if (!main_set.count(j)){
                value = (value << 1) | (a[i] >> j & 1);
            }
        }
        for (int j = 0; j < 1 << BIT1; ++ j){
            for (int k = 0; k <= now; ++ k){
                if (!dp[i][j][k]){
                    continue;
                }
                add(dp[i + 1][j][k], dp[i][j][k]);
                add(dp[i + 1][j ^ value][k + 1], dp[i][j][k]);
            }
        }
    }
    for (int i = 0; i < 1 << BIT1; ++ i){
        for (int j = 0; j < BBIT; ++ j){
            add(ans[j + __builtin_popcount(i)], dp[now][i][j]);
        }
    }
    print(n, m, now);
    return 0;
}