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

int n;
int a[505];
int dp[505][505];
int f[505][505];

int main () {
    n = read();
    int i, j, k;
    for (i = 1; i <= n; i++) a[i] = read(), dp[i][i] = a[i], f[i][i] = 1;
    for (i = 2; i <= n; i++) for (j = 1; j <= n - i + 1; j++) {
        int L = j, R = j + i - 1;
        for (k = L; k <= R; k++) if (dp[L][k] == dp[k + 1][R] && dp[L][k] != 0) dp[L][R] = max(dp[L][R], dp[L][k] + 1);
        if (dp[L][R]) f[L][R] = 1;
        else f[L][R] = 1e9 + 7;
        //printf("%d %d %d\n", L, R, dp[L][R]);
    }
    for (i = 1; i <= n; i++) for (j = i; j <= n; j++) for (k = j; k <= n; k++) {
        if (f[i][k] > f[i][j] + f[j + 1][k]) f[i][k] = f[i][j] + f[j + 1][k];//, printf("%d %d %d\n", i, j, k);
    }
    printf("%d\n", f[1][n]);
    return 0;
}