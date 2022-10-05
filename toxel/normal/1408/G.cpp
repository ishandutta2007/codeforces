#include <bits/stdc++.h>

const int N = 3010;
const int moder = 998244353;
using pii = std::pair <int, int>;

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

int fa[N], sz[N], sz1[N], rt[N];
int a[N][N];
pii p[N * N];
std::vector<int> e[N];
bool valid[N];
int dp[N][N];
int tmp[N];
int sz2[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (sz[u] > sz[v]){
        std::swap(u, v);
    }
    sz[v] += sz[u];
    sz1[v] += sz1[u];
    rt[v] = std::max(rt[v], rt[u]);
    fa[u] = v;
}

void dfs(int u){
    if (!e[u].empty()){
        dp[u][0] = 1;
    }
    sz2[u] = 1;
    for (auto v : e[u]){
        dfs(v);
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i <= sz2[u]; ++ i){
            for (int j = 0; j <= sz2[v]; ++ j){
                tmp[i + j] = (tmp[i + j] + 1ll * dp[u][i] * dp[v][j]) % moder;
            }
        }
        memcpy(dp[u], tmp, sizeof(tmp));
        sz2[u] += sz2[v];
    }
    if (valid[u]){
        add(dp[u][1], 1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            scanf("%d", &a[i][j]);
            if (i < j){
                p[a[i][j]] = {i, j};
            }
        }
    }
    for (int i = 1; i < N; ++ i){
        fa[i] = rt[i] = i;
    }
    for (int i = 1; i <= n; ++ i){
        sz[i] = 1;
        valid[i] = true;
    }
    int pcnt = n;
    for (int i = 1; i <= n * (n - 1) / 2; ++ i){
        if (find(p[i].first) == find(p[i].second)){
        }
        else{
            ++ pcnt;
            e[pcnt].emplace_back(rt[find(p[i].first)]);
            e[pcnt].emplace_back(rt[find(p[i].second)]);
            unite(pcnt, p[i].first);
            unite(pcnt, p[i].second);
        }
        int x = find(p[i].first);
        ++ sz1[x];
        if (sz1[x] == sz[x] * (sz[x] - 1) / 2){
            valid[rt[x]] = true;
        }
    }
    dfs(pcnt);
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", dp[pcnt][i], " \n"[i == n]);
    }
    return 0;
}