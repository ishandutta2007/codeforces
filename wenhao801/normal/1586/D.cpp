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

const int MAXN = 111;
int n, mn, ans[MAXN];
vector <int> E[MAXN];
void dfs (int x, int now, int las = 0) { ans[x] = now; for (auto i: E[x]) if (i != las) dfs(i, now + 1, x); }

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) {
        printf("?"); for (j = 1; j <= n; j++) printf(" %d", i == j ? 1 : 2); puts(""); fflush(stdout);
        int x = read();
        if (!x) mn = i;
        if (x && i != x) E[x].push_back(i), E[i].push_back(x);
    }
    for (i = 1; i <= n; i++) {
        printf("?"); for (j = 1; j <= n; j++) printf(" %d", i == j ? 2 : 1); puts(""); fflush(stdout);
        int x = read();
        if (x && i != x) E[x].push_back(i), E[i].push_back(x);
    }
    dfs(mn, 1); putchar('!'); for (i = 1; i <= n; i++) printf(" %d", ans[i]);
    return 0;
}