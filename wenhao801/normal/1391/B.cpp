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

char a[222][222];

int main () {
    int T = read();
    while (T--) {
        int n = read(), m = read();
        int i, j;
        for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
        int ans = 0;
        for (i = 1; i < n; i++) if (a[i][m] == 'R') ++ans;
        for (i = 1; i < m; ++i) if (a[n][i] == 'D') ++ans;
        printf("%d\n", ans);
    }
    return 0;
}