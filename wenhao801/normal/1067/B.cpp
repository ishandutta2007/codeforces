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

const int MAXN = 101000;
int n, m; vector <int> E[MAXN];

int dep[MAXN], fa[MAXN];
void dfs (int x, int f) {
    dep[x] = dep[f] + 1; fa[x] = f;
    for (auto i: E[x]) if (i != f) dfs(i, x);
}

bool judge (int x, int f) {
    int deg = E[x].size() - (bool(f));
    dep[x] = dep[f] + 1;
    if (deg == 0 && dep[x] - 1 != m) return 0;
    if (deg != 0 && deg < 3) return 0;
    for (auto i: E[x]) if (i != f) {
        if (!judge(i, x)) return 0;
    }
    return 1;
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs(1, 0);
    for (i = 1, j = 1; i <= n; i++) if (dep[i] > dep[j]) j = i;
    dfs(j, 0);
    for (i = 1, j = 1; i <= n; i++) if (dep[i] > dep[j]) j = i;
    if (dep[j] - 1 != m * 2) { puts("No"); return 0; }
    for (i = 1; i <= m; i++) j = fa[j];
    if (judge(j, 0)) puts("Yes"); else puts("No");
    return 0;
}