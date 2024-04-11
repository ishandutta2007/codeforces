#include <bits/stdc++.h>

const int N = 100010;
const int BIT = 21;
using ll = long long;

ll dp[N][BIT];
std::vector <int> fact[N];
ll cnt[N];
ll precalc[N];

int calc(int l, int r){
    int ans = 0;
    for (int i = l; i <= r; ++ i){
        for (int j = i + 1; j <= r; ++ j){
            if (std::gcd(i, j) >= l){
                ++ ans;
            }
        }
    }
    return ans;
}

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    if (k >= BIT){
        printf("%d\n", n);
        return;
    }
    printf("%lld\n", dp[n][k] + n);
    /*if (k == 2){
        int ans = INT_MAX, pos = -1;
        for (int i = 1; i < n; ++ i){
            int val = calc(1, i) + calc(i + 1, n);
            if (val < ans){
                ans = val;
                pos = i;
            }
        }
        printf("%d %d\n", ans, pos);
    }*/
}

ll lup(ll prev, int l, int r){
    int x = r / l;
    return prev - precalc[x];
}

ll rdown(ll prev, int l, int r){
    int sz = fact[r].size();
    int begin = -1;
    for (int i = sz - 1; i >= 0; -- i){
        if (fact[r][i] >= l){
            begin = i;
        }
    }
    for (int i = begin; i < sz; ++ i){
        int val = fact[r][i];
        prev -= 1ll * (1 - cnt[val]) * ((r - 1) / val - (l - 1) / val);
        for (auto j : fact[r / val]){
            if (j == 1){
                continue;
            }
            cnt[j * val] += 1 - cnt[val];
        }
    }
    for (int i = begin; i < sz; ++ i){
        int val = fact[r][i];
        cnt[val] = 0;
    }
    return prev;
}

void dfs(int l, int r, int k_l, int k_r, ll prew, int dep){
    int mid = (l + r) / 2, k = k_l;
    ll value1 = prew;
    for (int i = r; i > mid; -- i){
        value1 = rdown(value1, k_l + 1, i);
    }
    ll min = LLONG_MAX;
    ll value2 = value1;
    for (int i = k_l; i <= std::min(k_r, mid - 1); ++ i){
        ll value = dp[i][dep - 1] + value2;
        if (value < min){
            min = value;
            k = i;
        }
        value2 = lup(value2, i + 1, mid);
    }
    dp[mid][dep] = min;
    if (l < mid){
        value1 = rdown(value1, k_l + 1, mid);
        dfs(l, mid - 1, k_l, k, value1, dep);
    }
    if (r > mid){
        for (int i = k_l; i < k; ++ i){
            prew = lup(prew, i + 1, r);
        }
        dfs(mid + 1, r, k, k_r, prew, dep);
    }
}

int main(){
    for (int i = 1; i < N; ++ i){
        for (int j = i; j < N; j += i){
            fact[j].emplace_back(i);
        }
    }
    for (int r = 2; r < N; ++ r){
        int sz = fact[r].size();
        for (int i = 1; i < sz; ++ i){
            int val = fact[r][i];
            precalc[r] += 1ll * (1 - cnt[val]) * ((r - 1) / val);
            for (auto j : fact[r / val]){
                if (j == 1){
                    continue;
                }
                cnt[j * val] += 1 - cnt[val];
            }
        }
        for (int i = 1; i < sz; ++ i){
            int val = fact[r][i];
            cnt[val] = 0;
        }
        precalc[r] = r - 1 - precalc[r];
        precalc[r] += precalc[r - 1];
    }
    for (int i = 1; i < N; ++ i){
        dp[i][1] = 1ll * i * (i - 1) / 2;
    }
    for (int i = 2; i < BIT; ++ i){
        dfs(1, N - 1, 0, N - 1, 1ll * (N - 1) * (N - 2) / 2, i);
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}