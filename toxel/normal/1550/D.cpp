#include <bits/stdc++.h>

const int moder = int(1e9) + 7;
const int N = 200010;
using pii = std::pair <int, int>;

int fac[N], inv[N], invf[N];

int comb(int n, int m){
    if (n < m || m < 0) return 0;
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

pii inter(pii p1, pii p2){
    return {std::max(p1.first, p2.first), std::min(p1.second, p2.second)};
}

int get_sz(pii p){
    return std::max(0, p.second - p.first + 1);
}

void addmult(int &u, int v, int w){
    u = (u + 1ll * v * w) % moder;
}

void solve(){
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    std::vector <int> vec;
    for (int i = 1; i <= n; ++ i){
        for (int j = -1; j <= 1; ++ j){
            vec.emplace_back(l - i + j);
            vec.emplace_back(r - i + j);
            vec.emplace_back(-(l - i) + j);
            vec.emplace_back(-(r - i) + j);
        }
    }
    vec.emplace_back(1);
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    int sz = vec.size();
    int ans = 0;
    for (int i = 0; i < sz - 1; ++ i){
        if (vec[i] <= 0){
            continue;
        }
        int num = vec[i + 1] - vec[i];
        pii p_up = {l - vec[i], r - vec[i]};
        p_up = inter(p_up, {1, n});
        pii p_down = {l + vec[i], r + vec[i]};
        p_down = inter(p_down, {1, n});
        pii both = inter(p_up, p_down);
        int sz1 = get_sz(p_up);
        int sz2 = get_sz(p_down);
        int sz = get_sz(both);
        sz1 -= sz, sz2 -= sz;
        if (sz1 + sz2 + sz < n){
            continue;
        }
        addmult(ans, comb(sz, n / 2 - sz1), num);
        if (n % 2 == 1){
            addmult(ans, comb(sz, n / 2 + 1 - sz1), num);
        }
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