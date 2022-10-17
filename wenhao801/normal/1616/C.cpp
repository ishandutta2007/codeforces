#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 77;
const double eps = 1e-8;
int n, a[MAXN];

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j, k;
        for (i = 1; i <= n; i++) a[i] = read();
        int ans = n - 1;
        for (i = 1; i <= n; i++) for (j = i + 1; j <= n; j++) {
            int tmp = 0;
            double d = 1.0 * (a[j] - a[i]) / (j - i);
            for (k = 1; k <= n; k++) if (k != i && k != j)
                tmp += fabs(a[i] - d * (i - k) - a[k]) > eps;
            ans = min(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}