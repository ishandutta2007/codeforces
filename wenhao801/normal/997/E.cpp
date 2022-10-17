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

using ll = long long;
const int MAXN = 120200, inf = 1e9 + 7;
int n, m, a[MAXN];
struct qry { int l, r, id; } q[MAXN];

struct node {
    int mn, cnt; ll res;
    node operator + (const node &other) const {
        node ret;
        if (mn == other.mn) ret.mn = mn, ret.cnt = cnt + other.cnt;
        else if (mn > other.mn) ret.mn = other.mn, ret.cnt = other.cnt;
        else ret.mn = mn, ret.cnt = cnt;
        ret.res = res + other.res;
        return ret;
    }
} t[MAXN << 2];
int tag[MAXN << 2], tag2[MAXN << 2];

void build (int l, int r, int x) {
    if (l == r) { t[x].mn = inf, t[x].cnt = 1; return; }
    int mid = (l + r) >> 1;
    build(l, mid, x << 1), build(mid + 1, r, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}
void cover (int x, int k) {
    t[x].mn += k; tag[x] += k;
}
void claim (int x, int k) {
    t[x].res += 1ll * k * t[x].cnt; tag2[x] += k;
}
void pushdown (int x) {
    if (tag[x]) cover(x << 1, tag[x]), cover(x << 1 | 1, tag[x]), tag[x] = 0;
    if (tag2[x]) {
        if (t[x].mn == t[x << 1].mn) claim(x << 1, tag2[x]);
        if (t[x].mn == t[x << 1 | 1].mn) claim(x << 1 | 1, tag2[x]);
        tag2[x] = 0;
    }
}
void modify (int l, int r, int k, int L, int R, int x) {
    if (l > r) return;
    if (l <= L && R <= r) { cover(x, k); return; }
    int mid = (L + R) >> 1; pushdown(x);
    if (l <= mid) modify(l, r, k, L, mid, x << 1);
    if (mid < r) modify(l, r, k, mid + 1, R, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}
node query (int l, int r, int L, int R, int x) {
    if (l <= L && R <= r) return t[x];
    int mid = (L + R) >> 1; pushdown(x);
    if (l <= mid && mid < r) return query(l, r, L, mid, x << 1) + query(l, r, mid + 1, R, x << 1 | 1);
    if (l <= mid) return query(l, r, L, mid, x << 1);
    else return query(l, r, mid + 1, R, x << 1 | 1);
}

int mn[MAXN], mntop, mx[MAXN], mxtop;
ll ans[MAXN];

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    m = read();
    for (i = 1; i <= m; i++) q[i].l = read(), q[i].r = read(), q[i].id = i;
    sort(q + 1, q + m + 1, [](qry u, qry v) { return u.l < v.l; });
    build(1, n, 1); mn[0] = mx[0] = n + 1;
    for (i = n, j = m; i >= 1; i--) {
        while (mntop && a[mn[mntop]] > a[i]) {
            modify(mn[mntop], mn[mntop - 1] - 1, a[mn[mntop]] - a[i], 1, n, 1);
            --mntop;
        }
        mn[++mntop] = i;
        while (mxtop && a[mx[mxtop]] < a[i]) {
            modify(mx[mxtop], mx[mxtop - 1] - 1, a[i] - a[mx[mxtop]], 1, n, 1);
            --mxtop;
        }
        mx[++mxtop] = i;
        modify(i, i, -inf, 1, n, 1);
        modify(i + 1, n, -1, 1, n, 1);
        claim(1, 1);
        while (q[j].l == i) {
            node tmp = query(1, q[j].r, 1, n, 1);
            ans[q[j].id] = tmp.res;
            --j;
        }
    }
    for (i = 1; i <= m; i++) printf("%lld\n", ans[i]);
    return 0;
}