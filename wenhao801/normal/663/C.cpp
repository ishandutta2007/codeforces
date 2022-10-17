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

const int MAXN = 200200;
int fa[MAXN];
int gf (int x) { return fa[x] == x ? x : (fa[x] = gf(fa[x])); }

#define pii pair <int, int>
#define fr first
#define se second

int n, m;
vector <pii> e[2];
vector <int> ans;

vector <int> E[MAXN], vec, way;
int vis[MAXN];

void dfs (int x, int cur) {
    if (!vis[x]) {
        vis[x] = cur;
        if (x <= n) vec.push_back(x);
        if (gf(x) != x) dfs(gf(x), cur);
        else {
            for (auto i: E[x]) dfs(i, cur);
        }
        dfs(x > n ? (x - n) : (x + n), cur ^ 1);
    }
}

void solve () {
    int i, j; way.clear();
    for (i = 1; i <= n * 2; i++) fa[i] = i, E[i].clear(), vis[i] = 0;
    for (auto i: e[0]) {
        const int u = i.fr, v = i.se;
        fa[gf(u)] = gf(v), fa[gf(u + n)] = gf(v + n);
    }
    for (auto i: e[1]) {
        const int u = i.fr, v = i.se;
        fa[gf(u)] = gf(v + n), fa[gf(u + n)] = gf(v);
    }
    for (i = 1; i <= n; i++) if (gf(i) == gf(i + n)) return;
    for (i = 1; i <= 2 * n; i++) E[gf(i)].push_back(i);
    for (i = 1; i <= 2 * n; i++) if (!vis[i]) {
        vec.clear();
        dfs(i, 2);
        j = 0;
        for (auto k: vec) j += vis[k] == 2;
        if (j < int(vec.size()) - j) j = 2; else j = 3;
        for (auto k: vec) if (vis[k] == j) way.push_back(k);
    }
    if (way.size() < ans.size()) ans = way;
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read(); char ch[3]; scanf("%s", ch);
        e[ch[0] == 'B'].push_back({u, v});
    }
    ans.resize(n + 1);
    solve(); swap(e[0], e[1]); solve();
    if (int(ans.size()) > n) { puts("-1"); return 0; }
    printf("%d\n", int(ans.size()));
    for (auto i: ans) printf("%d ", i);
    putchar('\n');
    return 0;
}