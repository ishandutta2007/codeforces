#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 110;
int n, a[MAXN], mex[MAXN][MAXN], f[MAXN][MAXN];

bool vis[MAXN];

int main() {
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = min(read(), 102);
        for (i = 1; i <= n; i++) {
            for (j = i; j <= n; j++) {
                vis[a[j]] = 1; mex[i][j] = mex[i][j - 1];
                while (vis[mex[i][j]]) ++mex[i][j];
            }
            for (j = 1; j <= n; j++) vis[a[j]] = 0;
        }
        long long ans = 0;
        for (int len = 1; len <= n; len++) for (i = 1; i + len - 1 <= n; i++) {
            const int l = i, r = i + len - 1;
            f[l][r] = 1 + mex[l][r];
            for (j = l; j < r; j++) f[l][r] = max(f[l][r], f[l][j] + f[j + 1][r]);
            ans += f[l][r];
        }
        printf("%lld\n", ans);
    }
    return 0;
}