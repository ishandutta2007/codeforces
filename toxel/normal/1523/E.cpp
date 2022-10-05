#include <bits/stdc++.h>

const int moder = int(1e9) + 7;
const int N = 100010;

int fac[N], inv[N], invf[N];

int comb(int n, int m){
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 1;
    for (int i = 1; ; ++ i){
        int x = n - (k - 1) * (i - 1);
        if (x < i){
            break;
        }
        ans = (ans + 1ll * comb(x, i) * fac[i] % moder * fac[n - i] % moder * invf[n]) % moder;
    }
    printf("%d\n", ans);
}

int main(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}