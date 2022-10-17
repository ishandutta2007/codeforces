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
const int MAXN = 1001000;
int n, m, K; vector <int> E[MAXN];
bool vis[MAXN];

int dfs (int x) {
    int ret = 1; vis[x] = 1;
    for (auto i: E[x]) if (!vis[i]) ret += dfs(i);
    return ret;
}

int main () {
    n = read(), m = read(), K = read();
    while (m--) { int u = read(), v = read(); E[u].push_back(v), E[v].push_back(u); }
    if (K == 1) {
        int s = 0; for (int i = 1; i <= n; i++) if (!vis[i]) ++s, dfs(i);
        printf("%d\n", max(0, s - 2));
        return 0;
    }
    int s = 2;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int j = dfs(i);
        if (j >= 2) s += min(j, K) - 2;
        else --s;
    }
    printf("%d\n", max(0, (-s + 1) / 2));
    return 0;
}