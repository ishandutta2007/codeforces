#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100010;

int n;

struct Edge {
    int nex;
    int to;
} edge[MAXN << 1];
int head[MAXN] = {}, cnt = 0;

void add (int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].nex = head[u];
    head[u] = cnt;
}

int fa[MAXN][22] = {};
int dep[MAXN] = {};

void dfs (int x, int f) {
    fa[x][0] = f;
    dep[x] = dep[f] + 1;
    int i, j;
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (j != f) dfs(j, x);
    }
}

int lca (int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int i, j;
    for (i = 20; i >= 0; i--) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (i = 20; i >= 0; i--) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int len (int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

int main () {
    n = read();
    int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v), add(v, u);
    }
    dfs(1, 0);
    for (i = 1; i <= 20; i++) for (j = 1; j <= n; j++)
        fa[j][i] = fa[fa[j][i - 1]][i - 1];
    int q = read();
    while (q--) {
        int x = read(), y = read(), a = read(), b = read();
        int res1 = len(a, b);
        int res2 = len(a, x) + 1 + len(y, b);
        int res3 = len(a, y) + 1 + len(b, x);
        int k = read();
        if (k % 2 == res1 % 2 && k >= res1) { puts("YES"); }
        else if (k % 2 == res2 % 2 && k >= res2) { puts("YES"); }
        else if (k % 2 == res3 % 2 && k >= res3) { puts("YES"); }
        else puts("NO");
    }
    return 0;
}