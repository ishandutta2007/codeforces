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

const int MAXN = 5050;
int pre[MAXN][MAXN], suf[MAXN][MAXN], a[MAXN];

int main () {
    int T = read(); while (T--) {
        int n = read(), i, j;
        for (i = 1; i <= n; i++) a[i] = read();

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) pre[i][j] = pre[i - 1][j] + (a[i] <= j);
        }
        for (i = n; i >= 1; i--) {
            for (j = 1; j <= n; j++) suf[i][j] = suf[i + 1][j] + (a[i] <= j);
        }
        long long ans = 0;
        for (i = 2; i <= n; i++) for (j = i + 1; j < n; j++) {
            ans += 1ll * pre[i - 1][a[j] - 1] * suf[j + 1][a[i] - 1];
        }
        printf("%lld\n", ans);
        for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) pre[i][j] = suf[i][j] = 0;
    }
    return 0;
}