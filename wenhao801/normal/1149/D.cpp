#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
#define pii pair <int, int>
#define fr first
#define se second

const int MAXN = 77;
const ll inf = 1e15;
int n, m, a, b; vector <int> A[MAXN], B[MAXN];
int fa[MAXN], siz[MAXN], id[MAXN], top;
inline int gf (int x) { return fa[x] == x ? x : (fa[x] = gf(fa[x])); }

ll f[MAXN][1 << 18];
queue <pii> qa, qb;

int main () {
    n = read(), m = read(), a = read(), b = read();
    int i, j;
    for (i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        if (w == a) {
            A[u].emplace_back(v); A[v].emplace_back(u);
            if (gf(u) != gf(v)) siz[gf(v)] += siz[gf(u)], fa[gf(u)] = gf(v);
        }
        else B[u].emplace_back(v), B[v].emplace_back(u);
    }
    for (i = 1; i <= n; i++) if (gf(i) == i && siz[i] >= 4) id[i] = ++top;
    for (i = 1; i <= n; i++) for (j = 0; j < (1 << top); j++) f[i][j] = inf;
    f[1][0] = 0; qa.push({1, 0});
    while (!qa.empty() || !qb.empty()) {
        pii x; 
        if ((!qa.empty() && !qb.empty() && f[qa.front().fr][qa.front().se] < f[qb.front().fr][qb.front().se]) || qb.empty())
            x = qa.front(), qa.pop();
        else x = qb.front(), qb.pop();
        int nex = x.se | (id[gf(x.fr)] ? (1 << (id[gf(x.fr)] - 1)) : 0);
        for (auto i: A[x.fr]) {
            if (f[i][x.se] > f[x.fr][x.se] + a) {
                f[i][x.se] = f[x.fr][x.se] + a;
                qa.push({i, x.se});
            }
        }
        for (auto i: B[x.fr]) {
            if (gf(x.fr) != gf(i) && (!id[gf(i)] || !((x.se >> (id[gf(i)] - 1)) & 1)) && f[i][nex] > f[x.fr][x.se] + b) {
                f[i][nex] = f[x.fr][x.se] + b;
                qb.push({i, nex});
            }
        }
    }
    for (i = 1; i <= n; i++) printf("%lld ", f[i][min_element(f[i], f[i] + (1 << top)) - f[i]]);
    return 0;
}