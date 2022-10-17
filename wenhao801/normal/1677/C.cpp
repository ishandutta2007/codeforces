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

const int MAXN = 200200;
using ll = long long;
int n, a[MAXN], b[MAXN]; bool vis[MAXN];

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read(), vis[i] = 0;
        for (i = 1; i <= n; i++) b[a[i]] = read();
        int cnt = 0;
        for (i = 1; i <= n; i++) if (!vis[i]) {
            vis[i] = 1; int len = 1;
            for (j = b[i]; !vis[j]; j = b[j]) vis[j] = 1, ++len;
            cnt += len & 1;
        }
        cnt = (n - cnt) >> 1; ll ans = 0;
        for (i = 1; i <= cnt; i++) ans += 2ll * ((n - i + 1) - i);
        printf("%lld\n", ans);
    }
    return 0;
}