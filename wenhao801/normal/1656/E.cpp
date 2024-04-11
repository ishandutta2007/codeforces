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

#define size(v) (int(v.size()))
const int MAXN = 100100;
int n; vector <int> E[MAXN];

int dep[MAXN], f[MAXN];
void dfs (int x, int fa) {
    dep[x] = dep[fa] + 1;
    for (auto i: E[x]) if (i != fa) dfs(i, x);
    if (dep[x] == 1) f[x] = -size(E[x]);
    else if (dep[x] & 1) f[x] = -size(E[x]);
    else f[x] = size(E[x]);
}

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 1; i < n; i++) {
            int u = read(), v = read();
            E[u].push_back(v), E[v].push_back(u);
        }
        dfs(1, 0);
        for (i = 1; i <= n; i++) printf("%d ", f[i]), E[i].clear();
        putchar('\n');
    }
    return 0;
}