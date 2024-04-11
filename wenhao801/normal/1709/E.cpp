#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
int n, a[MAXN], p[MAXN]; vector <int> E[MAXN];

map <int, bool> vis[MAXN];
int ans = 0;

void dfs(int x, int fa) {
    p[x] = a[x] ^ p[fa];
    bool del = 0;
    vis[x][p[x]] = 1;
    for (auto i: E[x]) if (i != fa) {
        dfs(i, x);
        if (del) { vis[i].clear(); continue; }
        if (vis[x].size() < vis[i].size()) swap(vis[x], vis[i]);
        for (auto k: vis[i]) {
            if (vis[x].count(k.first ^ a[x])) {
                del = 1, ++ans, vis[x].clear(), vis[i].clear();
                break;
            }
        }
        for (auto k: vis[i]) vis[x][k.first] = 1;
        vis[i].clear();
    }
}

int main() {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}