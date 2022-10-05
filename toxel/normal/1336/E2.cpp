#include <bits/stdc++.h>

const int N = 200010;
const int M = 110;
using ll = long long;
const int moder = 998244353;
const int BIT = 26;

ll a[N], b[N];
int ans[N], cnt[N];
bool base[N];
int mat[M][M];
ll s[1 << (BIT - 1)];
int power[N];
int comb[M][M];

void count(ll *a, int len){
    if (len == 0){
        cnt[0] = 1;
        return;
    }
    for (int i = len - 2; i >= 0; -- i){
        for (int j = 0; j < 1 << (len - 1); j += 1 << (i + 1)){
            s[j ^ (1 << i)] = s[j] ^ a[i];
        }
    }
    for (int i = 0; i < 1 << (len - 1); ++ i){
        ++ cnt[__builtin_popcountll(s[i])];
        ++ cnt[__builtin_popcountll(s[i] ^ a[len - 1])];
    }
}

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
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 2 * power[i - 1] % moder;
    }
    for (int i = 0; i < M; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
        }
    }
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    int now = 0;
    for (int i = 0; i < m; ++ i){
        for (int j = now; j < n; ++ j){
            if (a[j] >> i & 1){
                std::swap(a[j], a[now]);
            }
        }
        if (!(a[now] >> i & 1)){
            continue;
        }
        base[i] = true;
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
    for (int i = 0; i < now; ++ i){
        ll tmp = 0;
        for (int j = m - 1; j >= 0; -- j){
            if (!base[j]){
                tmp = tmp << 1 | (a[i] >> j & 1);
            }
        }
        for (int j = m - 1; j >= 0; -- j){
            if (base[j]){
                tmp = tmp << 1 | (a[i] >> j & 1);
            }
        }
        a[i] = tmp;
        for (int j = 0; j < m; ++ j){
            mat[i][j] = a[i] >> j & 1;
        }
    }
    for (int i = now; i < m; ++ i){
        mat[i][i] = 1;
    }
    for (int i = 0; i < now; ++ i){
        for (int j = now; j < m; ++ j){
            mat[j][i] = mat[i][j];
        }
    }
    for (int i = now; i < m; ++ i){
        for (int j = m - 1; j >= 0; -- j){
            b[i] = b[i] << 1 | mat[i][j];
        }
    }
    if (now <= BIT){
        count(a, now);
        for (int i = 0; i <= m; ++ i){
            ans[i] = cnt[i];
        }
    }
    else{
        count(b + now, m - now);
        for (int i = 0; i <= m; ++ i){
            for (int j = 0; j <= m; ++ j){
                for (int k = 0; k <= j; ++ k){
                    if (0 <= i - k && i - k <= m - j){
                        int coe = 1ll * comb[j][k] * comb[m - j][i - k] % moder;
                        ans[i] = (ans[i] + (k & 1 ? -1ll : 1ll) * coe * cnt[j]) % moder;
                    }
                }
            }
        }
        for (int i = 0; i <= m; ++ i){
            ans[i] += ans[i] < 0 ? moder : 0;
            ans[i] = 1ll * powermod(power[m - now], moder - 2) * ans[i] % moder;
        }
    }
    for (int i = 0; i <= m; ++ i){
        ans[i] = 1ll * ans[i] * power[n - now] % moder;
        printf("%d%c", ans[i], " \n"[i == m]);
    }
}