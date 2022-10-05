#include <bits/stdc++.h>

const int N = 4000010;
const int moder = 998244353;

int fac[N], inv[N], invf[N];

int comb(int n, int m){
    if (m < 0 || n < m) return 0;
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
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
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        int prob = 1ll * m * inv[m + i] % moder;
        prob = powermod(1 - prob, moder - 2);
        prob += prob < 0 ? moder : 0;
        ans = (ans + (i & 1 ? 1ll : -1ll) * prob * comb(n, i)) % moder;
    }
    int coe = 1;
    int tmp = powermod(comb(n + m, m), moder - 2);
    for (int i = 1; i <= n + m; ++ i){
        coe = (coe + 1ll * comb(n + m - i, m) * tmp) % moder;
    }
    ans = 1ll * ans * coe % moder;
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}