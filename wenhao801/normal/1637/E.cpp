#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define size(v) (int(v.size()))
using pii = pair <int, int>;
#define fr first
#define se second

const int MAXN = 300300;
int n, m, a[MAXN];
map <int, int> vis;
map <pii, bool> sp;
vector <int> b[MAXN], hav;

using ll = long long;

map <pair <pii, pii>, bool> sp2;
ll get(int u, int i, int v, int j) {
    if (i < 0 || j < 0 || sp2.count({{u, i}, {v, j}})) return -1;
    sp2[{{u, i}, {v, j}}] = 1;
    if (!sp.count({b[u][i], b[v][j]})) return 1ll * (u + v) * (b[u][i] + b[v][j]);
    return max(get(u, i - 1, v, j), get(u, i, v, j - 1));
}

map <pii, bool> sp3;
ll get2(int u, int i, int j) {
    if (j < 0 || sp3.count({i, j})) return -1;
    sp3[{i, j}] = 1;
    if (!sp.count({b[u][i], b[u][j]})) return 1ll * (u + u) * (b[u][i] + b[u][j]);
    return max(get2(u, i - 1, j - 1), get2(u, i, j - 1));
}

int main() {
    int T = read(); while (T--) {
        n = read(), m = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read(), ++vis[a[i]];
        for (auto j: vis) b[j.second].push_back(j.first);
        for (i = 1; i <= n; i++) if (size(b[i])) hav.push_back(i);
        for (i = 1; i <= m; i++) {
            int u = read(), v = read();
            sp[{u, v}] = sp[{v, u}] = 1;
        }
        sp2.clear(); ll ans = -1;
        for (i = 0; i < size(hav); i++) for (j = 0; j < i; j++)
            ans = max(ans, get(hav[i], size(b[hav[i]]) - 1, hav[j], size(b[hav[j]]) - 1));
        for (i = 0; i < size(hav); i++) {
            sp3.clear();
            ans = max(ans, get2(hav[i], size(b[hav[i]]) - 1, size(b[hav[i]]) - 2));
        }
        printf("%lld\n", ans);

        sp.clear(); vis.clear();
        for (auto i: hav) b[i].clear();
        hav.clear();
    }
    return 0;
}