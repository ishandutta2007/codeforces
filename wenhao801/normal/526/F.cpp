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

const int MAXN = 300300;
#define ls (x << 1)
#define rs (x << 1 | 1)
struct tree { int mn, cnt, tag; } t[MAXN << 2];
void pushup (int x) {
    if (t[ls].mn < t[rs].mn) t[x].mn = t[ls].mn, t[x].cnt = t[ls].cnt;
    if (t[ls].mn > t[rs].mn) t[x].mn = t[rs].mn, t[x].cnt = t[rs].cnt;
    if (t[ls].mn == t[rs].mn) t[x].mn = t[ls].mn, t[x].cnt = t[ls].cnt + t[rs].cnt;
}
void build (int l, int r, int x) {
    if (l == r) { t[x].mn = 998244353, t[x].cnt = 1; return; }
    int mid = (l + r) >> 1;
    build(l, mid, ls), build(mid + 1, r, rs), pushup(x);
}
void cover (int x, int k) { t[x].mn += k, t[x].tag += k; }
void pushdown (int x) { if (t[x].tag) cover(ls, t[x].tag), cover(rs, t[x].tag), t[x].tag = 0; }
void modify (int l, int r, int k, int L, int R, int x) {
    // if (x == 1) { printf("%d %d %d\n", l, r, k); }
    // printf("%d %d %d %d %d %d\n", l, r, k, L, R, x);
    if (l <= L && R <= r) {
        cover(x, k);
        return;
    }
    int mid = (L + R) >> 1; pushdown(x);
    if (l <= mid) modify(l, r, k, L, mid, ls);
    if (mid < r) modify(l, r, k, mid + 1, R, rs);
    pushup(x);
    // printf("return %d: %d\n", x, t[x].mn);
}
int n, a[MAXN];
int mn[MAXN], mntop, mx[MAXN], mxtop;

int main () {
    n = read(); int i, j;
    build(1, n, 1);
    for (i = 1; i <= n; i++) { j = read(); a[j] = read(); }
    long long ans = 0;
    for (i = 1; i <= n; i++) {
        j = i - 1;
        while (mntop && a[mn[mntop]] > a[i]) {
            modify(mn[mntop - 1] + 1, j, a[mn[mntop]] - a[i], 1, n, 1);
            j = mn[mntop]; --mntop;
        }
        j = i - 1;
        while (mxtop && a[mx[mxtop]] < a[i]) {
            modify(mx[mxtop - 1] + 1, j, a[i] - a[mx[mxtop]], 1, n, 1);
            j = mx[mxtop]; --mxtop;
        }
        mn[++mntop] = i; mx[++mxtop] = i;
        modify(i, i, i - 998244353, 1, n, 1);
        if (t[1].mn == i) ans += t[1].cnt;
        // printf("max = %d, min = %d, tmin = %d, ans = %lld, mntop = %d, mxtop = %d\n", a[mx[1]], a[mn[1]], t[1].mn, ans, mntop, mxtop);
    }
    printf("%lld\n", ans);
    return 0;
}