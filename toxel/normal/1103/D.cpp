#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <ll, ll> pii;

const int N = 1000010;
const ll INF = 0x7f7f7f7f7f7f7f7fll;
const int M = 20;
const int K = 12;

ll a[N], e[N];
ll dp[2][M][1 << K];
std::vector <int> pre[1 << K];
std::vector <pii> small[1 << K];
std::vector <int> able[N];

int main(){
    int n;
    ll max;
    scanf("%d%lld", &n, &max);
    ll gcd = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
        gcd = std::__gcd(gcd, a[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &e[i]);
        a[i] /= gcd;
    }
    if (gcd == 1){
        puts("0");
        return 0;
    }
    std::vector <ll> prime;
    std::vector <ll> gfact;
    for (ll i = 2; i * i <= gcd; ++ i){
        if (gcd % i == 0){
            prime.push_back(i);
            ll prod = 1;
            while (gcd % i == 0){
                gcd /= i;
                prod *= i;
            }
            gfact.push_back(prod);
        }
    }
    if (gcd > 1){
        prime.push_back(gcd);
        gfact.push_back(gcd);
    }
    std::vector <pii> vec;
    for (int i = 0; i < n; ++ i){
        ll prod = 1;
        for (auto u : prime){
            while (a[i] % u == 0){
                a[i] /= u;
                prod *= u;
            }
            if (a[i] == 1) break;
        }
        vec.push_back({prod, e[i]});
    }
    std::sort(vec.begin(), vec.end());
    int now = 0;
    int sz = prime.size();
    int cnt = 0;
    for (int i = 0; i < 1 << sz; ++ i){
        for (int j = 0; j < 1 << sz; ++ j){
            if ((i & j) == 0){
                pre[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        if (i && vec[i].first != vec[i - 1].first) cnt = 0;
        ++ cnt;
        if (cnt > sz) continue;
        std::vector <ll> fact = gfact;
        ll a = vec[i].first, e = vec[i].second;
        for (int j = 0; j < sz; ++ j){
            while (a % prime[j] == 0){
                fact[j] *= prime[j];
                a /= prime[j];
            }
            if (a == 1) break;
        }
        for (int j = 1; j < 1 << sz; ++ j){
            ll prod = 1;
            for (int k = 0; k < sz; ++ k){
                if (j >> k & 1){
                    prod *= fact[k];
                }
            }
            if (prod > max){
                continue;
            }
            small[j].push_back({e, i});
        }
    }
    for (int i = 0; i < 1 << sz; ++ i){
        std::sort(small[i].begin(), small[i].end());
        int ssz = std::min(sz, (int) small[i].size());
        for (int j = 0; j < ssz; ++ j){
            able[small[i][j].second].push_back(i);
        }
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++ i){
        if (able[i].empty()) continue;
        memcpy(dp[now ^ 1], dp[now], sizeof(dp[now]));
        for (auto j : able[i]){
            for (auto v : pre[j]){
                for (int u = 0; u <= sz; ++ u){
                    if (dp[now][u][v] == INF) continue;
                    ll &w = dp[now ^ 1][u + 1][v | j];
                    w = std::min(w, dp[now][u][v] + vec[i].second);
                }
            }
        }
        now ^= 1;
    }
    ll ans = INF;
    for (int i = 1; i <= sz; ++ i){
        ll x = dp[now][i][(1 << sz) - 1];
        if (x == INF) continue;
        ans = std::min(ans, i * x);
    }
    printf("%lld\n", ans == INF ? -1ll : ans);
    return 0;
}