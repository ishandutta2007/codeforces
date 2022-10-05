#include <bits/stdc++.h>

const int N = 1000010;
const int moder = 998244353;

int fac[N], inv[N], invf[N];
int a[N];

int comb(int n, int m){
    if (n < m || m < 0){
        return 0;
    }
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

int cata(int n){
    return 1ll * comb(n, n / 2) % moder;
}

int main(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * i * fac[i - 1] % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + 2 * n);
    int ans = 0;
    for (int i = 0; i < 2 * n; ++ i){
        if (i < n){
            ans = (ans - 1ll * comb(2 * n, n) * a[i]) % moder;
        }
        else{
            ans = (ans + 1ll * comb(2 * n, n) * a[i]) % moder;
        }
    }
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}