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

const int MAXN = 600600;
int fa[MAXN], ans[MAXN];
vector <int> E[MAXN];
int gf (int x) { if (fa[x] == x) return x; return fa[x] = gf(fa[x]); }

int n, m, q;

int dis[MAXN], tmp[MAXN];
void pre (int x, int f) {
    for (auto i: E[x]) if (i != f) dis[i] = dis[x] + 1, pre(i, x);
}
int C (int x) { return (x + 1) >> 1; }

int main () {
    n = read(), m = read(), q = read();
    int i, j;
    for (i = 1; i <= n; i++) fa[i] = i;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
        if (gf(u) != gf(v)) fa[gf(u)] = gf(v);
    }
    for (i = 1; i <= n; i++) dis[i] = 0;
    for (i = 1; i <= n; i++) {
        if (!dis[gf(i)]) dis[gf(i)] = 1, pre(gf(i), 0);
        if (dis[tmp[gf(i)]] < dis[i]) tmp[gf(i)] = i;
    }
    for (i = 1; i <= n; i++) dis[i] = 0;
    for (i = 1; i <= n; i++) {
        if (!dis[gf(i)]) dis[tmp[gf(i)]] = 1, pre(tmp[gf(i)], 0);
        if (dis[i] > ans[gf(i)]) ans[gf(i)] = dis[i] - 1;
    }
    while (q--) {
        int t = read();
        if (t == 1) {
            int x = read();
            printf("%d\n", ans[gf(x)]);
        }
        else {
            int u = read(), v = read();
            int fu = gf(u), fv = gf(v);
            if (fu == fv) continue;
            fa[fu] = fv;
            ans[fv] = max(max(ans[fu], ans[fv]), C(ans[fu]) + C(ans[fv]) + 1);
        }
    }
    return 0;
}