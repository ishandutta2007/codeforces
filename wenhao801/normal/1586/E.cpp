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

#define pii pair<int, int>
const int MAXN = 300300;
int n, m, q, d[MAXN]; bool vis[MAXN]; pii a[MAXN];
vector <int> E[MAXN], T[MAXN];

void pre (int x) {
    vis[x] = 1;
    for (auto i: E[x]) if (!vis[i]) {
        T[x].push_back(i);
        pre(i);
    }
}
int fa[MAXN], dep[MAXN];
void dfs (int x, int f) {
    fa[x] = f, dep[x] = dep[f] + 1;
    for (auto i: T[x]) dfs(i, x);
}

vector <int> pr, sf;
void proc (int u, int v) {
    pr.clear(), sf.clear();
    while (dep[u] > dep[v]) pr.push_back(u), u = fa[u];
    while (dep[u] < dep[v]) sf.push_back(v), v = fa[v];
    while (u != v) pr.push_back(u), sf.push_back(v), u = fa[u], v = fa[v];
    pr.push_back(u); reverse(sf.begin(), sf.end());
    printf("%d\n", pr.size() + sf.size());
    for (auto i: pr) cout << i << ' '; for (auto i: sf) cout << i << ' '; cout << endl;
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    pre(1); dfs(1, 0);
    int q = read();
    for (i = 1; i <= q; i++) {
        a[i].first = read(), a[i].second = read();
        ++d[a[i].first], ++d[a[i].second];
    }
    for (i = 1, j = 0; i <= n; i++) j += d[i] & 1;
    if (j) { printf("NO\n%d\n", j >> 1); return 0; }
    puts("YES");
    for (i = 1; i <= q; i++) {
        proc(a[i].first, a[i].second);
    }
    return 0;
}