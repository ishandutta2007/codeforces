#include <bits/stdc++.h>

const int moder = 998244353;
const int N = 200010;

int fac[N], inv[N], invf[N];

int main(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 2){
        puts("0");
        return 0;
    }
    int ans = 1ll * fac[m] * invf[n - 1] % moder * invf[m - n + 1] % moder;
    ans = 1ll * (n - 2) * ans % moder;
    for (int i = 0; i < n - 3; ++ i){
        ans = 2 * ans % moder;
    }
    printf("%d\n", ans);
    return 0;
}