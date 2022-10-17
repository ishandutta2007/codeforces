#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

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
int n, a[MAXN][2], b[MAXN][2];

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i][0] = read();
    for (i = 1; i <= n; i++) a[i][1] = read();
    for (i = 1; i <= n; i++) b[i][0] = read();
    for (i = 1; i <= n; i++) b[i][1] = read();
    int cur[2] = {}; long long ans = 0;
    for (i = 1; i <= n; i++) {
        cur[0] += a[i][0] - b[i][0], cur[1] += a[i][1] - b[i][1];
        if (cur[0] < 0 && cur[1] > 0) {
            int tmp = min(-cur[0], cur[1]); ans += tmp;
            cur[0] += tmp, cur[1] -= tmp;
        }
        if (cur[0] > 0 && cur[1] < 0) {
            int tmp = min(cur[0], -cur[1]); ans += tmp;
            cur[0] -= tmp, cur[1] += tmp;
        }
        ans += abs(cur[0]) + abs(cur[1]);
    }
    if (cur[0] || cur[1]) puts("-1"); else printf("%lld\n", ans);
    return 0;
}