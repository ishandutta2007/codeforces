#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
int n, m; bool vis[MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(), m = read(); int i, j;
        for (i = 1; i <= n; i++) vis[i] = 0;
        while (m--) {
            int x = read(), y = read(), z = read();
            vis[y] = 1;
        }
        for (i = 1; i <= n; i++) if (!vis[i]) {
            for (j = 1; j <= n; j++) if (i != j) printf("%d %d\n", i, j);
            break;
        }
    }
    return 0;
}