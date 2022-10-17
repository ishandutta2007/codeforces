#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 300300;
int n; vector <int> E[MAXN], b[MAXN];
int fa[MAXN][22], dep[MAXN];

void pre (int x, int f) {
    fa[x][0] = f; dep[x] = dep[f] + 1, b[dep[x]].push_back(x);
    for (int i = 1; i <= 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (auto i: E[x]) if (i != f) pre(i, x);
}
int lca (int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 20; i >= 0; i--) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (int i = 20; i >= 0; i--) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
int ans[MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j;
        for (i = 1; i < n; i++) {
            int u = read(), v = read();
            E[u].push_back(v), E[v].push_back(u);
        }
        pre(1, 0);
        int now = 0, mxdep = 0;
        for (i = 1; i <= n; i++) mxdep = max(mxdep, dep[i]);
        for (i = 1; i <= n; i++) ans[i] = mxdep - 1;
        for (i = mxdep; i >= 1; i--) {
            for (auto x: b[i]) {
                if (!now) { now = x; continue; }
                int tmp = lca(now, x);
                while (dep[now] + dep[x] - 2 * dep[tmp] > mxdep - dep[now]) now = fa[now][0];
            }
            if (i - 2 - (mxdep - dep[now]) >= 1) ans[i - 2 - (mxdep - dep[now])] = i - 2;
        }
        for (i = n - 1; i >= 1; i--) ans[i] = min(ans[i], ans[i + 1]);
        for (i = 1; i <= n; i++) printf("%d ", ans[i]);
        putchar('\n');
        for (i = 1; i <= n; i++) {
            E[i].clear(), b[i].clear();
            dep[i] = ans[i] = 0;
            for (j = 0; j <= 20; j++) fa[i][j] = 0;
        }
    }
    return 0;
}