#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

std::vector <int> e[N];
int l[N], r[N];
ll dp[N][2];

void dfs(int u, int fa){
    dp[u][0] = dp[u][1] = 0;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        for (int s = 0; s < 2; ++ s){
            ll max = 0;
            for (int t = 0; t < 2; ++ t){
                ll x = s == 0 ? l[u] : r[u];
                ll y = t == 0 ? l[v] : r[v];
                max = std::max(max, std::abs(x - y) + dp[v][t]);
            }
            dp[u][s] += max;
        }
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++ i){
        e[i].clear();
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d", &l[i], &r[i]);
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    printf("%lld\n", std::max(dp[1][0], dp[1][1]));
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}