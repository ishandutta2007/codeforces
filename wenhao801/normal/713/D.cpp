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

const int MAXN = 1002;
int n, m; bool a[MAXN][MAXN];
int lg2[MAXN], f[MAXN][MAXN][10][10], d[MAXN][MAXN];

int tmp[MAXN][10];

bool check (int lim, int x1, int y1, int x2, int y2) {
    x2 -= lim - 1, y2 -= lim - 1;
    int lenx = x2 - x1 + 1, leny = y2 - y1 + 1;
    // printf("%d %d\n", lenx, leny);
    return max({f[x1][y1][lg2[lenx]][lg2[leny]], 
                f[x2 - (1 << lg2[lenx]) + 1][y1][lg2[lenx]][lg2[leny]],
                f[x1][y2 - (1 << lg2[leny]) + 1][lg2[lenx]][lg2[leny]],
                f[x2 - (1 << lg2[lenx]) + 1][y2 - (1 << lg2[leny]) + 1][lg2[lenx]][lg2[leny]]}) >= lim;
}

int main () {
    n = read(), m = read(); int i, j, k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) a[i][j] = read();
    }
    for (i = n; i >= 1; i--) for (j = 1; j <= m; j++) if (!a[i][j]) d[i][j] = 0; else d[i][j] = d[i + 1][j] + 1;
    lg2[0] = -1; for (i = 1; i <= max(n, m); i++) lg2[i] = lg2[i >> 1] + 1;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) tmp[j][0] = d[i][j];
        for (j = 1; j < 10; j++) for (k = 1; k + (1 << j) - 1 <= m; k++) tmp[k][j] = min(tmp[k][j - 1], tmp[k + (1 << (j - 1))][j - 1]);
        for (j = 1; j <= m; j++) if (a[i][j]) {
            int L = 1, R = m - j + 1;
            while (L <= R) {
                int mid = (L + R) >> 1;
                if (min(tmp[j][lg2[mid]], tmp[j + mid - 1 - (1 << lg2[mid]) + 1][lg2[mid]]) >= mid)
                    f[i][j][0][0] = mid, L = mid + 1;
                else R = mid - 1;
            }
        }
    }
    // for (i = 1; i <= n; i++) { for (j = 1; j <= m; j++)  cout << f[i][j][0][0]  << ' '; cout << endl; }
    for (i = 0; i < 10; i++) for (j = 0; j < 10; j++) if (i || j) {
        for (int p = 1; p + (1 << i) - 1 <= n; p++) for (int q = 1; q + (1 << j) - 1 <= m; q++) {
            if (i) {
                f[p][q][i][j] = max(f[p][q][i - 1][j], f[p + (1 << (i - 1))][q][i - 1][j]);
            }
            else {
                f[p][q][i][j] = max(f[p][q][i][j - 1], f[p][q + (1 << (j - 1))][i][j - 1]);
            }
        }
    }
    int t = read();
    while (t--) {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        int L = 1, R = min(x2 - x1 + 1, y2 - y1 + 1), ans = 0;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (check(mid, x1, y1, x2, y2)) ans = mid, L = mid + 1;
            else R = mid - 1;
        }
        cout << ans << endl;
    }
    return 0;
}