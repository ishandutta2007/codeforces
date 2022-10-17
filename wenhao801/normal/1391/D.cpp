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

char a[4][1000100];
int dp[1001000][2];
int f[1001000][2][2];
bool b[1001000], c[1001000][2];

int main () {
    int n = read(), m = read();
    if (min(n, m) >= 4) { puts("-1"); return 0; }
    if (min(n, m) == 1) { puts("0"); return 0; }
    int i, j, k;
    for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    if (n == 2) {
        swap(n, m);
        for (i = 1; i < n; i++) b[i] = (a[1][i] + a[2][i] + a[1][i + 1] + a[2][i + 1] - 4 * '0') & 1;
        dp[1][0] = b[1], dp[1][1] = !b[1];
        for (i = 2; i < n; i++) {
            if (!b[i]) {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = dp[i - 1][0] + 1;
            }
            else {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1];
            }
        }
        printf("%d\n", min(dp[n - 1][0] + 1, dp[n - 1][1]));
    }
    else {
        swap(n, m);
        for (i = 1; i < n; i++) c[i][0] = (a[1][i] + a[2][i] + a[1][i + 1] + a[2][i + 1] - 4 * '0') & 1, c[i][1] = (a[2][i] + a[3][i] + a[2][i + 1] + a[3][i + 1] - 4 * '0') & 1;
        // for (i = 1; i < n; i++) printf("%d %d\n", c[i][0], c[i][1]);
        f[1][0][0] = ((!c[1][0] && !c[1][1]) ? 0 : 1);
        f[1][0][1] = ((!c[1][0] && c[1][1]) ? 0 : 1);
        f[1][1][0] = ((c[1][0] && !c[1][1]) ? 0 : 1);
        f[1][1][1] = ((c[1][0] && c[1][1]) ? 0 : 1);
        for (i = 2; i < n; i++) {
            if (!c[i][0] && !c[i][1]) {
                f[i][0][0] = f[i - 1][1][1];
                f[i][1][0] = f[i - 1][0][1] + 1;
                f[i][0][1] = f[i - 1][1][0] + 1;
                f[i][1][1] = f[i - 1][0][0] + 1;
            }
            else if (!c[i][0] && c[i][1]) {
                f[i][0][0] = f[i - 1][1][0] + 1;
                f[i][1][0] = f[i - 1][0][0] + 1;
                f[i][0][1] = f[i - 1][1][1];
                f[i][1][1] = f[i - 1][0][1] + 1;
            }
            else if (c[i][0] && !c[i][1]) {
                f[i][0][0] = f[i - 1][0][1] + 1;
                f[i][1][0] = f[i - 1][1][1];
                f[i][0][1] = f[i - 1][0][0] + 1;
                f[i][1][1] = f[i - 1][1][0] + 1;
            }
            else {
                f[i][0][0] = f[i - 1][0][0] + 1;
                f[i][1][0] = f[i - 1][1][0] + 1;
                f[i][0][1] = f[i - 1][0][1] + 1;
                f[i][1][1] = f[i - 1][1][1];
            }
            // printf("%d %d %d %d\n", f[i][0][0], f[i][0][1], f[i][1][0], f[i][1][1]);
        }
        i = n - 1;
        printf("%d\n", min(f[i][1][1], min(min(f[i][1][0], f[i][0][1]), f[i][0][0]) + 1));
    }
    return 0;
}