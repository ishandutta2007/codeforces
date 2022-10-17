#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 5005000;
int n, m, f[MAXN]; bool a[MAXN];
int vis[MAXN];

int main() {
    int T = read(); while (T--) {
        n = read(), m = read(); int i, j, mn = 1e9;
        for (i = 1; i <= n; i++) a[read()] = 1;
        for (i = 1; i <= m; i++) f[i] = 1e9, a[i] && (mn = min(mn, i));
        int ans = 1e9, mx = m;
        for (i = m; i >= 1; i--) {
            f[i] = i; if (a[i]) ++vis[i];
            for (j = i; 1ll * i * j <= m; j++) {
                if (a[i * j]) --vis[f[i * j]];
                f[i * j] = min(f[i * j], f[j]);
                if (a[i * j]) ++vis[f[i * j]];
            }
            if (i <= mn) {
                while (!vis[mx]) --mx;
                ans = min(ans, mx - i);
            }
        }
        printf("%d\n", ans);
        for (i = 1; i <= m; i++) a[i] = vis[i] = 0;
    }
    return 0;
}