#include<bits/stdc++.h>

const int N = 1000010;
const int moder = (int) 1e9 + 7;

int min[N], phi[N], cnt[N];
std::vector <int> prime, fact[N];
int fac[N], inv[N], invf[N];

void init(){
    phi[1] = 1;
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            phi[i] = i - 1;
            prime.push_back(i);
        }
        for (auto u : prime){
            int k = i * u;
            if (k >= N) break;
            min[k] = u;
            if (i % u == 0){
                phi[k] = phi[i] * u;
                break;
            }
            phi[k] = phi[i] * (u - 1);
        }
    }
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    for (int i = 1; i < N; ++ i){
        for (int j = i; j < N; j += i){
            fact[j].push_back(i);
        }
    }
}

int comb(int n, int m){
    if (n < m || m < 0) return 0;
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

int main(){
    init();
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        for (auto v : fact[x]){
            ++ cnt[v];
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++ i){
        ans = (ans + 1ll * comb(cnt[i], k) * phi[i]) % moder;
    }
    while (q --){
        int x;
        scanf("%d", &x);
        for (auto v : fact[x]){
            ans = (ans - 1ll * comb(cnt[v], k) * phi[v]) % moder;
            ++ cnt[v];
            ans = (ans + 1ll * comb(cnt[v], k) * phi[v]) % moder;
        }
        ans += ans < 0 ? moder : 0;
        printf("%d\n", ans);
    }
    return 0;
}