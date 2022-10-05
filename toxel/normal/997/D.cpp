#include<bits/stdc++.h>

const int N = 4010;
const int moder = 998244353;
const int M = 100;

int comb[M][M];
std::vector <int> e[N];
int ans[N], ans1[N], ans2[N];
int sz[N], max[N];
bool vis[N];
int K;

void add(int &a, int b){
    a += b;
    a -= a >= moder ? moder : 0;
}

int f[M][N], g[M][N];

void dfs(int u, int fa){
    sz[u] = 1;
    max[u] = 0;
    for (auto v : e[u]){
        if (v == fa || vis[v]) continue;
        dfs(v, u);
        sz[u] += sz[v];
        max[u] = std::max(max[u], sz[v]);
    }
}

int dfs1(int root, int u, int fa){
    max[u] = std::max(max[u], sz[root] - sz[u]);
    int sit = u;
    for (auto v : e[u]){
        if (v == fa || vis[v]) continue;
        int _sit = dfs1(root, v, u);
        if (max[_sit] < max[sit]){
            sit = _sit;
        }
    }
    return sit;
}

void clear(int u, int fa){
    for (int i = 0; i < M; ++ i){
        f[i][u] = g[i][u] = 0;
    }
    for (auto v : e[u]){
        if (vis[v] || v == fa) continue;
        clear(v, u);
    }
}

void calc(int u, int fa, int root, int now){
    if (fa != root){
        add(f[now + 1][fa], f[now][u]);
    }
    add(g[now + 1][fa], g[now][u]);
    for (auto v : e[u]){
        if (vis[v] || v == fa) continue;
        calc(v, u, root, now);
        add(f[now + 1][v], f[now][u]);
        add(g[now + 1][v], g[now][u]);
    }
}

void calc(int u, int fa){
    for (int i = 0; i <= K; ++ i){
        for (int j = 0; i + j <= K; ++ j){
            ans[i + j] = (ans[i + j] + 1ll * f[i][u] * g[j][u]) % moder;
        }
    }
    for (auto v : e[u]){
        if (vis[v] || v == fa) continue;
        calc(v, u);
    }
}

void solve(int u){
    dfs(u, 0);
    int root = dfs1(u, u, 0);
    clear(root, 0);
    f[0][root] = g[0][root] = 1;
    for (int i = 1; i <= K; ++ i){
        calc(root, 0, root, i - 1);
    }
    calc(root, 0);
    vis[root] = true;
    for (auto v : e[root]){
        if (!vis[v]){
            solve(v);
        }
    }
}

int main(){
    for (int i = 0; i < M; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            comb[i][j] -= comb[i][j] >= moder ? moder : 0;
        }
    }
    int n1, n2;
    scanf("%d%d%d", &n1, &n2, &K);
    for (int i = 0, u, v; i < n1 - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve(1);
    memcpy(ans1, ans, sizeof(ans));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < N; ++ i){
        e[i].clear();
    }
    for (int i = 0, u, v; i < n2 - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    solve(1);
    memcpy(ans2, ans, sizeof(ans));
    int ans = 0;
    for (int i = 0; i <= K; i += 2){
        ans = (ans + 1ll * comb[K][i] * ans1[i] % moder * ans2[K - i]) % moder;
    }
    printf("%d\n", ans);
    return 0;
}