#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN= 200200;

int n, p, k;
int a[MAXN] = {};
int dp[MAXN] = {};

int main () {
    int T = read();
    while (T-- ) {
        n = read(), p = read(), k = read();
        int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        sort(a + 1, a + n + 1);
        for (i = 1; i < k; i++) dp[i] = a[i] + dp[i - 1];
        for (i = k; i <= n; i++) dp[i] = dp[i - k] + a[i];
        int ans = 0;
        for (i = 1; i <= n; i++) if (dp[i] <= p) ans = i;
        printf("%d\n", ans);
    }
    return 0;
}