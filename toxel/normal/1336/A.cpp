#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

std::vector <int> e[N];
int dep[N], sz[N];

void dfs(int u, int fa){
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++ i){
        dep[i] -= sz[i] - 1;
    }
    std::sort(dep + 1, dep + n + 1, std::greater <int>());
    ll ans = 0;
    for (int i = 1; i <= k; ++ i){
        ans += dep[i];
    }
    printf("%lld\n", ans);
    return 0;
}