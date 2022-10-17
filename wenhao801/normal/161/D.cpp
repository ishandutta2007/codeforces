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

const int MAXN = 50500, MAXK = 505;

struct Edge { int nex, to; } edge[MAXN << 1];
int head[MAXN], cnt = 0;

void add (int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].nex = head[u];
    head[u] = cnt;
}

int n, k, root, sall;
int siz[MAXN], tans[MAXN];
bool vis[MAXN];

void getroot (int x, int f) {
    siz[x] = 1, tans[x] = 0;
    for (int i = head[x]; i; i = edge[i].nex) {
        int j = edge[i].to;
        if (j == f || vis[j]) continue;
        getroot(j, x);
        siz[x] += siz[j], tans[x] = max(tans[x], siz[j]);
    }
    tans[x] = max(tans[x], sall - siz[x]);
    if (tans[x] < tans[root]) root = x;
}

ll buc[MAXN], ans = 0;
int tmp[MAXN], ttop = 0;

void dfs (int x, int d, int f) {
    if (d > k) return;
    tmp[++ttop] = d;
    for (int i = head[x]; i; i = edge[i].nex)
        if (!vis[edge[i].to] && edge[i].to != f) dfs(edge[i].to, d + 1, x);
}

void calc (int x) {
    int i, j;
    buc[0] = 1;
    for (i = 1; i <= k; i++) buc[i] = 0;
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (vis[j]) continue;
        ttop = 0; dfs(j, 1, x);
        for (j = 1; j <= ttop; j++) {
            if (tmp[j] > k) continue;
            ans += buc[k - tmp[j]];
        }
        for (j = 1; j <= ttop; j++) if (tmp[j] <= k) ++buc[tmp[j]];
    }
}

void solve (int x) {
    int i, j;
    vis[x] = true; calc(x);
    for (i = head[x]; i; i = edge[i].nex) {
        j = edge[i].to;
        if (vis[j]) continue;
        root = 0, sall = siz[j]; getroot(j, 0);
        solve(root);
    }
}

signed main () {
    n = read(), k = read();
    int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v), add(v, u);
    }
    tans[root] = 1e9;
    sall = n; getroot(1, 0);
    solve(root);
    printf("%lld\n", ans);
    return 0;
}