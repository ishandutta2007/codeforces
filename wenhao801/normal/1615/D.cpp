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

const int MAXN = 400400;
vector <int> E[MAXN];
int n, m, fa[MAXN];
inline int gf (int x) { return x == fa[x] ? x : (fa[x] = gf(fa[x])); }
inline bool pc (int x) { if (!x) return 0; return __builtin_popcount(x) & 1; }

bool vis[MAXN], ans[MAXN], out[MAXN]; int pre[MAXN], ff[MAXN];
void predo (int x, int fa) { ff[x] = fa; for (auto i: E[x]) if (fa != i) predo(i, x); } 
void claim (int x, int fa) {
    out[x] = ans[gf(x)];
    for (auto i: E[x]) if (i != fa) claim(i, x);
    out[x] ^= out[fa];
    if (fa) printf("%d %d %d\n", x, fa, pre[x] == -1 ? out[x] : pre[x]);
}
void clear () {
    for (int i = 1; i <= n * 2; i++) fa[i] = 0, vis[i] = 0, ans[i] = 0, out[i] = 0, pre[i] = -1;
    for (int i = 1; i <= n; i++) E[i].clear();
}

struct ee { int u, v, w; } e[MAXN];

int main () {
    int T = read(); while (T--) {
        n = read(), m = read(); int i, j;
        for (i = 1; i <= n * 2; i++) fa[i] = i;
        for (i = 1; i < n + m; i++) {
            int u = read(), v = read(), k = read();
            if (k != -1) {
                if (pc(k)) fa[gf(u)] = gf(v + n), fa[gf(u + n)] = gf(v);
                else fa[gf(u)] = gf(v), fa[gf(u + n)] = gf(v + n);
            }
            if (i < n) E[u].push_back(v), E[v].push_back(u), e[i] = {u, v, k};
        }
        for (i = 1; i <= n; i++) if (gf(i) == gf(i + n)) { puts("NO"); break; }
        if (i <= n) { clear(); continue; }
        puts("YES");
        predo(1, 0);
        for (i = 1; i < n; i++) {
            if (ff[e[i].u] == e[i].v) pre[e[i].u] = e[i].w;
            else pre[e[i].v] = e[i].w;
        }
        for (i = 1; i <= n; i++) {
            if (!vis[gf(i)] && !vis[gf(i + n)]) vis[gf(i)] = vis[gf(i + n)] = 1, ans[gf(i)] = 0, ans[gf(i + n)] = 1;
            else if (vis[gf(i)]) vis[gf(i + n)] = 1, ans[gf(i + n)] = 1 ^ ans[gf(i)]; else vis[gf(i)] = 1, ans[gf(i)] = 1 ^ ans[gf(i + n)];
        }
        claim(1, 0); clear();
    }
    return 0;
}