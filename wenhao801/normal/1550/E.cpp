#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

inline int read () {
    int ret = 0, t = 1; char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200, MAXK = 18;
int n, K; char a[MAXN];

int f[MAXK][MAXN], g[1 << 17];
bool check (int lim) {
    int i, j;
    for (i = 1; i <= K; i++) {
        int las = n + 1; f[i][n + 1] = f[i][n + 2] = n + 1;
        for (j = n; j >= 1; j--) {
            if (a[j] != 'a' + i - 1 && a[j] != '?') { f[i][j] = f[i][j + 1], las = j; continue; }
            if (las - j >= lim) f[i][j] = j + lim - 1;
            else f[i][j] = f[i][j + 1];
        }
    }
    for (i = 1; i < (1 << K); i++) {
        g[i] = n + 1;
        for (j = 1; j <= K; j++) if ((i >> (j - 1)) & 1) {
            g[i] = min(g[i], f[j][g[i - (1 << (j - 1))] + 1]);
        }
    }
    return g[(1 << K) - 1] <= n;
}

int main () {
    n = read(), K = read(); int i, j;
    scanf("%s", a + 1);
    int L = 1, R = n / K, ans = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (check(mid)) ans = mid, L = mid + 1;
        else R = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}