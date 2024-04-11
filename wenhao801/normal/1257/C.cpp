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

const int MAXN = 200200;

int a[MAXN] = {};
int las[MAXN] = {};
int dis[MAXN] = {};

int main () {
    int T = read();
    while (T--) {
        int i, j;
        int n = read();
        int ans = n + 1;
        for (i = 1; i <= n; i++) a[i] = read();
        for (i = 1; i <= n; i++) las[i] = -n;
        if (n == 1) { puts("-1"); continue; }
        for (i = 1; i <= n; i++) {
            dis[a[i]] = i - las[a[i]] + 1;
            ans = min(ans, dis[a[i]]);
            las[a[i]] = i;
        }
        if (ans != n + 1)
        printf("%d\n", ans);
        else puts("-1");
    }
    return 0;
}