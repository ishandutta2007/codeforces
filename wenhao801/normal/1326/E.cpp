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

const int MAXN = 300300;
int a[MAXN], b[MAXN], ans[MAXN], n;

struct seg {
    int t[MAXN << 2], tag[MAXN << 2];
    void cover(int x, int k) { t[x] += k, tag[x] += k; }
    void pushdown(int x) {
        if (tag[x]) {
            cover(x << 1, tag[x]), cover(x << 1 | 1, tag[x]);
            tag[x] = 0;
        }
    }
    void modify(int l, int r, int k, int L, int R, int x) {
        if (l > r) return;
        if (l <= L && R <= r) { cover(x, k); return; }
        int mid = (L + R) >> 1; pushdown(x);
        if (l <= mid) modify(l, r, k, L, mid, x << 1);
        if (mid < r) modify(l, r, k, mid + 1, R, x << 1 | 1);
        t[x] = min(t[x << 1], t[x << 1 | 1]);
    }
    int query(int l, int r, int L, int R, int x) {
        if (!l) return 0;
        if (l <= L && R <= r) return t[x];
        int mid = (L + R) >> 1, ret = 1e9; pushdown(x);
        if (l <= mid) ret = min(ret, query(l, r, L, mid, x << 1));
        if (mid < r) ret = min(ret, query(l, r, mid + 1, R, x << 1 | 1));
        return ret;
    }
} t1, t2;
int pos[MAXN];

int main() {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read(), pos[a[i]] = i;
    for (i = 1; i <= n; i++) b[i] = read();
    for (i = n, j = 0; i >= 1; i--) {
        int l = pos[i], r = n, res = pos[i] - 1, tmp = t2.query(pos[i] - 1, pos[i] - 1, 1, n, 1) - t1.query(pos[i] - 1, pos[i] - 1, 1, n, 1) - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (t2.query(pos[i], mid, 1, n, 1) <= tmp) r = mid - 1;
            else l = mid + 1, res = mid;
        }
        t1.modify(pos[i], res, 1, 1, n, 1);
        t2.modify(pos[i], n, 1, 1, n, 1);
        while (j < n && t1.query(n, n, 1, n, 1)) {
            ++j;
            int l = b[j], r = n, res = b[j] - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (t1.query(b[j], mid, 1, n, 1)) res = mid, l = mid + 1;
                else r = mid - 1;
            }
            t1.modify(b[j], res, -1, 1, n, 1);
            t2.modify(b[j], n, -1, 1, n, 1);
        }
        ans[j - 1] = max(ans[j - 1], i);
    }
    for (i = n - 1; i >= 0; i--) ans[i] = max(ans[i], ans[i + 1]);
    for (i = 0; i < n; i++) printf("%d ", ans[i]); putchar('\n');
    return 0;
}