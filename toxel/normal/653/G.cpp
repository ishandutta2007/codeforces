#include<bits/stdc++.h>

const int N = 300010;
const int moder = (int) 1e9 + 7;

int min[N];
std::vector <int> prime;
std::vector <int> vec[N];
int power[N];
int fac[N], inv[N], invf[N];

void init(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (int j = 0, sz = prime.size(); j < sz && i * prime[j] < N; ++ j){
            min[i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                break;
            }
        }
    }
    power[0] = 1;
    for (int i = 1; i < N; ++ i){
        power[i] = 2 * power[i - 1] % moder;
    }
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        fac[i] = 1ll * fac[i - 1] * i % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
}

int comb(int n, int m){
    if (m < 0 || n < m) return 0;
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

int main(){
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        while (x > 1){
            int cnt = 0, tmp = min[x];
            while (x % tmp == 0){
                ++ cnt;
                x /= min[x];
            }
            vec[tmp].push_back(cnt);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++ i){
        if (vec[i].empty()) continue;
        std::sort(vec[i].begin(), vec[i].end());
        int sum = 0;
        for (auto u : vec[i]){
            sum += u;
        }
        ans = (ans + 1ll * sum * power[n - 1]) % moder;
        int l = n - vec[i].size(), r = n - 1 - l;
        int lsum = 0, rsum = sum;
        for (int j = 0, sz = vec[i].size(); j < sz; ++ j){
            int v = vec[i][j];
            rsum -= v;
            ans = (ans - 1ll * comb(l + r - 1, l - 1) * (r * v)) % moder;
            ans = (ans + 1ll * comb(l + r - 1, l) * (l * v - 2 * lsum)) % moder;
            ans = (ans - 1ll * comb(l + r - 1, l) * (r * v)) % moder;
            ans = (ans + 1ll * comb(l + r - 1, l + 1) * (l * v - 2 * lsum)) % moder;
            ans = (ans - 1ll * (comb(l + r, l) + comb(l + r, l + 1)) * v) % moder;
            ++ l, -- r;
            lsum += v;
        }
    }
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}