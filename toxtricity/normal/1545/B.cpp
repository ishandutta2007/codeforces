#include <bits/stdc++.h>

const int N = 200010;
const int moder = 998244353;
using pii = std::pair <int, int>;

char s[N];
int fac[N], inv[N], invf[N];

int comb(int n, int m){
    if (n < m || m < 0) return 0;
    return 1ll * fac[n] * invf[n - m] % moder * invf[m] % moder;
}

void solve(){
    int n;
    scanf("%d%s", &n, s);
    int pre = -1, even = 0, zero = 0;
    for (int i = 0; i < n; ++ i){
        if (i == n - 1 || s[i] != s[i + 1]){
            if (s[i] == '1'){
                even += (i - pre) / 2;
            }
            else{
                zero += i - pre;
            }
            pre = i;
        }
    }
    printf("%d\n", comb(zero + even, zero));
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