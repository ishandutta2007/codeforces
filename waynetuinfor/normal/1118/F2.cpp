#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int mod = 998244353;
vector<int> g[maxn], ps[maxn], f[maxn];
int a[maxn], fa[20][maxn], dep[maxn], rev[maxn];
int fw[maxn], tin[maxn], tout[maxn];
int color[maxn], uncolor[maxn], rep[maxn];
int dp[2][maxn];

void dfs(int x, int p) {
    static int tk = 0;
    rev[tin[x] = tk++] = x;
    dep[x] = ~p ? dep[p] + 1 : 0;
    fa[0][x] = p;
    for (int i = 1; (1 << i) <= dep[x]; ++i)
        fa[i][x] = fa[i - 1][fa[i - 1][x]];
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (u == p) continue;
        dfs(u, x);
    }
    tout[x] = tk;
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 0; i < 20; ++i) {
        if ((dep[y] - dep[x]) >> i & 1)
            y = fa[i][y];
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; --i) {
        if (fa[i][x] == fa[i][y]) continue;
        x = fa[i][x];
        y = fa[i][y];
    }
    return fa[0][x];
}

void add(int p, int v) {
    for (int i = p + 1; i < maxn; i += i & -i)
        fw[i] += v;
}

int query(int p) {
    int res = 0;
    for (int i = p + 1; i > 0; i -= i & -i)
        res += fw[i];
    return res;
}

void dfs3(int x, int p, int t) {
    uncolor[x] = t;
    if (color[x] != -1) t = x;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (u == p) continue;
        dfs3(u, x, t);
    }
}

void dfs4(int x, int c) {
    if (color[x] != -1) {
        puts("0");
        exit(0);
    }
    color[x] = c;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        int u = g[x][i];
        if (u == fa[0][x]) continue;
        if (query(tout[u] - 1) - query(tin[u] - 1) == 0) continue;
        dfs4(u, c);
    }
}

void dfs3(int x, int p) {
    if (color[x] != -1) dp[1][x] = 1;
    else dp[0][x] = 1;
    for (int i = 0; i < (int)f[x].size(); ++i) {
        int u = f[x][i];
        if (u == p) continue;
        dfs3(u, x);
        if (color[x] == -1) {
            int t = dp[0][x];
            dp[0][x] = dp[0][x] * 1ll * (dp[0][u] + dp[1][u]) % mod;
            dp[1][x] = (dp[1][x] * 1ll * (dp[0][u] + dp[1][u]) + t * 1ll * dp[1][u]) % mod;
        } else {
            dp[1][x] = dp[1][x] * 1ll * (dp[0][u] + dp[1][u]) % mod;
        }
    }
}

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), --a[i];
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int root = 0;
    while (a[root] == -1) ++root;
    dfs(root, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0)
            ps[a[i]].push_back(tin[i]);
    }
    memset(color, -1, sizeof(color));
    for (int i = 0; i < k; ++i) sort(ps[i].begin(), ps[i].end());
    for (int i = 0; i < k; ++i) {
        int x = lca(rev[ps[i].front()], rev[ps[i].back()]);
        rep[i] = x;
        for (int j = 0; j < (int)ps[i].size(); ++j) 
            add(ps[i][j], 1);
        dfs4(x, i);
        for (int j = 0; j < (int)ps[i].size(); ++j) 
            add(ps[i][j], -1);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)g[i].size(); ++j) {
            int u = g[i][j];
            if (color[i] == color[u] && color[i] >= 0) continue;
            int x = color[i] == -1 ? i : rep[color[i]];
            int y = color[u] == -1 ? u : rep[color[u]];
            f[x].push_back(y);
            f[y].push_back(x);
        }
    }    
    for (int i = 0; i < n; ++i) {
        sort(f[i].begin(), f[i].end());
        f[i].resize(unique(f[i].begin(), f[i].end()) - f[i].begin());
    }
    dfs3(root, -1);
    printf("%d\n", dp[1][root]);
    return 0;
}