#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

#define size(v) (int(v.size()))
#define pii pair <int, int>
#define fr first
#define se second

const int MAXN = 500500;
int fa[MAXN], siz[MAXN], n, m, q;
inline int gf (int x) { return fa[x] == x ? x : gf(fa[x]); }

struct edge { int u, v, id; } e[MAXN]; vector <edge> E[MAXN];
bool ans[MAXN];
struct qry { int k, id; }; vector <qry> Q[MAXN];

int main () {
    n = read(), m = read();
    int i, j;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        e[i] = {u, v, w};
        E[w].push_back({u, v, i});
    }
    q = read();
    for (i = 1; i <= q; i++) {
        ans[i] = 1; int num = read();
        while (num--) { int k = read(); Q[e[k].id].push_back({k, i}); }
    }
    for (i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    for (i = 1; i <= 500000; i++) if (!E[i].empty()) {
        sort(Q[i].begin(), Q[i].end(), [](qry u, qry v) { return u.id < v.id; });
        for (int l = 0, r; l < size(Q[i]); l = r + 1) {
            for (r = l; r < size(Q[i]) && Q[i][r].id == Q[i][l].id; r++);
            --r;
            vector <pii> ops;
            for (int j = l; j <= r; j++) {
                int u = gf(e[Q[i][j].k].u), v = gf(e[Q[i][j].k].v);
                if (u == v) { ans[Q[i][j].id] = 0; break; }
                if (siz[u] > siz[v]) swap(u, v);
                siz[v] += siz[u]; fa[u] = v; ops.emplace_back(u, v);
            }
            for (int j = size(ops) - 1; j >= 0; j--) {
                int u = ops[j].fr, v = ops[j].se;
                siz[v] -= siz[u], fa[u] = u;
            }
            ops.clear();
        }
        for (auto j: E[i]) if (gf(j.u) != gf(j.v)) {
            int u = gf(j.u), v = gf(j.v);
            if (siz[u] > siz[v]) swap(u, v);
            siz[v] += siz[u], fa[u] = v;
        }
    }
    for (i = 1; i <= q; i++) puts(ans[i] ? "YES" : "NO");
    return 0;
}