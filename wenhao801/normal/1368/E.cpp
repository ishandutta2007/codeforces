#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
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
int n, m; vector <int> E[MAXN];
int dep[MAXN];

int main() {
    int T = read(); while (T--) {
        n = read(), m = read(); int i, j;
        for (i = 1; i <= m; i++) {
            int u = read(), v = read();
            E[u].push_back(v);
        }
        vector <int> ans;
        for (i = 1; i <= n; i++) {
            if (dep[i] == 2) { ans.push_back(i); continue; }
            for (auto v: E[i]) dep[v] = max(dep[v], dep[i] + 1);
        }
        printf("%d\n", ans.size());
        for (auto i: ans) printf("%d ", i);
        putchar('\n');
        for (i = 1; i <= n; i++) dep[i] = 0, E[i].clear();
    }
    return 0;
}