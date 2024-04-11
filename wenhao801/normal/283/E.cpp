#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
#define ll long long
#define pii pair<int, int>
#define fr first
#define se second

int n, m, a[MAXN], ind[MAXN]; pii b[MAXN];
bool cmpl (pii x, pii y) { return x.fr < y.fr; }
bool cmpr (pii x, pii y) { return x.se < y.se; }

int t[MAXN << 2]; bool tag[MAXN << 2];

void pushup (int x) { t[x] = t[x << 1] + t[x << 1 | 1]; }
void cover (int x, int l, int r) { t[x] = (r - l + 1) - t[x]; tag[x] ^= 1; }
void pushdown (int x, int l, int r) {
    if (tag[x]) {
        int mid = (l + r) >> 1;
        cover(x << 1, l, mid); cover(x << 1 | 1, mid + 1, r);
        tag[x] = 0;
    }
}
void modify (int l, int r, int L, int R, int x) {
    if (l <= L && R <= r) { cover(x, L, R); return; }
    int mid = (L + R) >> 1; pushdown(x, L, R);
    if (l <= mid) modify(l, r, L, mid, x << 1);
    if (mid < r) modify(l, r, mid + 1, R, x << 1 | 1);
    pushup(x);
}
int query (int l, int r, int L, int R, int x) {
    if (l <= L && R <= r) return t[x];
    int mid = (L + R) >> 1, ret = 0; pushdown(x, L, R);
    if (l <= mid) ret += query(l, r, L, mid, x << 1);
    if (mid < r) ret += query(l, r, mid + 1, R, x << 1 | 1);
    pushup(x); return ret;
}
void build (int l, int r, int x) {
    t[x] = 0; tag[x] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    for (i = 1; i <= m; i++) {
        b[i].fr = read(), b[i].se = read();
        b[i].fr = lower_bound(a + 1, a + n + 1, b[i].fr) - a;
        b[i].se = upper_bound(a + 1, a + n + 1, b[i].se) - a - 1;
    }
    sort(b + 1, b + m + 1, cmpl);
    ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (i = 1, j = 0; i < n; i++) {
        while (j < m && b[j + 1].fr == i) { ++j; if (b[j].fr < b[j].se) modify(1, b[j].se, 1, n, 1); }
        ind[i] += n - i - query(i + 1, n, 1, n, 1); 
    }
    sort(b + 1, b + m + 1, cmpr); build(1, n, 1);
    for (i = n, j = m + 1; i > 1; i--) {
        while (j > 1 && b[j - 1].se == i) { --j; if (b[j].fr < b[j].se) modify(b[j].fr, n, 1, n, 1); }
        ind[i] += query(1, i - 1, 1, n, 1);
    }
    for (i = 1; i <= n; i++) ans -= 1ll * ind[i] * (ind[i] - 1) / 2;
    printf("%lld\n", ans);
    return 0;
}