#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int x[maxn], y[maxn];

int main() {
    int n; scanf("%d", &n);
    int m = 4 * n + 1;
    for (int i = 0; i < m; ++i) scanf("%d%d", &x[i], &y[i]);
    for (int i = 0; i < m; ++i) {
        int xl = 1e9, xr = -1e9;
        int yl = 1e9, yr = -1e9;
        for (int j = 0; j < m; ++j) {
            if (i == j) continue;
            xl = min(xl, x[j]);
            xr = max(xr, x[j]);
            yl = min(yl, y[j]);
            yr = max(yr, y[j]);
        }

        int cnt[4] = {0, 0, 0, 0};
        bool ok = true;
        for (int j = 0; j < m; ++j) {
            if (i == j) continue;
            bool res = false;
            if (x[j] == xl) ++cnt[0], res = true;
            if (x[j] == xr) ++cnt[1], res = true;
            if (y[j] == yl) ++cnt[2], res = true;
            if (y[j] == yr) ++cnt[3], res = true;
            ok &= res;
        }

        if (!ok) continue;

        if (cnt[0] >= n && cnt[1] >= n && cnt[2] >= n && cnt[3] >= n) {
            if (x[i] < xl || x[i] > xr || y[i] < yl || y[i] > yr || 
                x[i] != xl && x[i] != xr && y[i] != yl && y[i] != yr) {
                printf("%d %d\n", x[i], y[i]);
                return 0;
            }
        }
    }
    assert(false);
}