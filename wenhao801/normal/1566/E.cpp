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

const int MAXN = 200200; int n, leaf;
vector <int> E[MAXN];

int f[MAXN], g[MAXN];
int ans = 0;
void dfs (int x, int fa) {
    if (x != 1 && E[x].size() == 1) return;
    for (auto i: E[x]) if (i != fa) {
        dfs(i, x);
        if (!f[i]) ++f[x];
    }
    if (f[x]) ans += f[x] - 1;
}

void calc (int x, int fa, int cur) {
    if (x != 1 && E[x].size() == 1) ans = max(ans, cur); //, printf("leaf %d, cur = %d\n", x, cur);
    for (auto i: E[x]) if (i != fa) cur += g[i];
    for (auto i: E[x]) if (i != fa) calc(i, x, cur - g[i]);
}

int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j; leaf = ans = 0;
        for (i = 1; i < n; i++) {
            int u = read(), v = read();
            E[u].push_back(v), E[v].push_back(u);
        }
        for (i = 2; i <= n; i++) if (E[i].size() == 1) ++leaf;
        ans = 0; dfs(1, 0);
        printf("%d\n", ans + 1);
        for (i = 1; i <= n; i++) E[i].clear(), f[i] = g[i] = 0;
    }
    return 0;
}