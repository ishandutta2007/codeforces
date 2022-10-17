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

const int inf = 1e9 + 7;
int n, m, K, r[505][505], c[505][505], a[504][505][22];
#define ll long long

int main () {
    n = read(), m = read(), K = read(); int i, j;
    if (K & 1) {
        for (i = 1; i <= n; i++) { for (j = 1; j <= m; j++) printf("-1 "); puts(""); }
        return 0;
    }
    for (i = 1; i <= n; i++) for (j = 1; j < m; j++) r[i][j] = read();
    for (i = 1; i < n; i++) for (j = 1; j <= m; j++) c[i][j] = read();
    // for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) a[i][j][0] = 0;
    for (int k = 1; k <= (K >> 1); k++) {
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            int ans = inf;
            if (j != 1) ans = min(ans, r[i][j - 1] + a[i][j - 1][k - 1]);
            if (j != m) ans = min(ans, r[i][j] + a[i][j + 1][k - 1]);
            if (i != 1) ans = min(ans, c[i - 1][j] + a[i - 1][j][k - 1]);
            if (i != n) ans = min(ans, c[i][j] + a[i + 1][j][k - 1]);
            a[i][j][k] = ans;
        }
    }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a[i][j][K >> 1] == inf) cout << -1 << ' ';
            else cout << 2 * a[i][j][K >> 1] << ' ';
        }
        cout << endl;
    }
    return 0;
}