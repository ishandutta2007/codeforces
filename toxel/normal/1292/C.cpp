#include <bits/stdc++.h>

const int N = 3010;
using ll = long long;

std::vector <int> e[N];
ll dp[N][N];
int next[N][N], sz[N][N];
int n;

void pre(int u, int fa, int rt){
    sz[rt][u] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        next[v][rt] = u;
        pre(v, u, rt);
        sz[rt][u] += sz[rt][v];
    }
}

ll dfs(int u, int v){
    if (dp[u][v] != -1){
        return dp[u][v];
    }
    int nextu = next[u][v], nextv = next[v][u];
    ll value1 = dfs(nextu, v) + sz[v][u] * (n - sz[v][nextv]);
    ll value2 = dfs(u, nextv) + sz[u][v] * (n - sz[u][nextu]);
    dp[u][v] = std::max(value1, value2);
    return dp[u][v];
}

int main(){
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++ i){
        pre(i, 0, i);
        dp[i][i] = 0;
    }
    ll max = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            dfs(i, j);
        }
    }
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            max = std::max(max, dp[i][j]);
        }
    }
    printf("%lld\n", max);
    return 0;
}