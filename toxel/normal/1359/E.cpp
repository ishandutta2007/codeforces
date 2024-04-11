#include <bits/stdc++.h>

const int N = 500010;
const int moder = 998244353;

std::vector <int> fac, inv, invf;

void init() {
    fac.resize(N);
    inv.resize(N);
    invf.resize(N);
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
}

int main(){
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        int x = n / i - 1, y = k - 1;
        if (x >= y){
            ans = (ans + 1ll * fac[x] * invf[y] % moder * invf[x - y]) % moder;
        }
        else{
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}