#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 3030;
int n;
struct Edge { int nex, to; } edge[MAXN << 1];
int head[MAXN], cnt = 0;
void addEdge (int u, int v) {
    edge[++cnt].to = v; edge[cnt].nex = head[u];
    head[u] = cnt;
}
int fa[MAXN][MAXN], siz[MAXN][MAXN];
void dfs (int x, int f) {
    fa[1][x] = f, siz[1][x] = 1;
    for (int i = head[x]; i; i = edge[i].nex) if (edge[i].to != f)
        dfs(edge[i].to, x), siz[1][x] += siz[1][edge[i].to];
}
void dfs2 (int x, int f) {
    for (int i = head[x]; i; i = edge[i].nex) {
        int j = edge[i].to; if (j == f) continue;
        for (int k = 1; k <= n; k++) fa[j][k] = fa[x][k], siz[j][k] = siz[x][k];
        fa[j][x] = j, fa[j][j] = 0; siz[j][j] = n, siz[j][x] = n - siz[x][j];
        dfs2(j, x);
    }
}
ll f[MAXN][MAXN];
ll dfs3 (int u, int v) {
    if (u == v) return 0;
    if (f[u][v]) return f[u][v];
    return f[u][v] = max(dfs3(fa[v][u], v), dfs3(u, fa[u][v])) + 1ll * siz[u][v] * siz[v][u];
}

int main () {
    n = read(); int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        addEdge(u, v), addEdge(v, u);
    }
    dfs(1, 0); dfs2(1, 0);
    ll ans = 0;
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) ans = max(ans, dfs3(i, j));
    printf("%lld\n", ans);
    return 0;
}