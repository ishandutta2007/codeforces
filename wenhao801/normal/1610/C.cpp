#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 200200;
int n; pii a[MAXN];
bool check (int m) {
    int i, j;
    int cur = 1;
    for (i = 1; i <= n; i++) {
        int l = max(1, m - a[i].fr), r = min(n, a[i].se + 1);
        if (l <= cur && cur <= r) ++cur;
    }
    return cur > m;
}

int main () {
    int T = read(); while (T--) {
        n = read(); int L = 1, R = n, ans = 0;
        for (int i = 1; i <= n; i++) a[i].fr = read(), a[i].se = read();
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (check(mid)) ans = mid, L = mid + 1; else R = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}