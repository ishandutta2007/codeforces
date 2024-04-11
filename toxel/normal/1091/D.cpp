#include<bits/stdc++.h>

const int moder = 998244353;
const int N = 1000010;

int fac[N], inv[N], invf[N];

void init(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
}

int comb(int n, int m){
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

int coe[N];

int main(){
    init();
    int n;
    scanf("%d", &n);
    int ans = fac[n];
    for (int i = 1; i <= n; ++ i){
        coe[i] = 1ll * comb(n, i) * fac[n - i] % moder;
    }
    for (int i = 1; i <= n; ++ i){
        coe[i] -= coe[i + 1];
        coe[i] += coe[i] < 0 ? moder : 0;
    }
    for (int i = 1; i < n; ++ i){
        ans = (ans + 1ll * coe[i] * (n - i - 1)) % moder;
    }
    printf("%d\n", ans);
    return 0;
}