#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, q;
LL a0, b0, a[N], b[N];
LL tr[(1 << 18) + 5], lz[(1 << 18) + 5];
LL tr1[N];

void build(int i = 1, int l = 1, int r = m) {
    if (l == r) {
        tr[i] = b[l];
        return;
    }
    int m = l + r >> 1;
    build(i << 1, l, m);
    build(i << 1 | 1, m + 1, r);
    tr[i] = tr[i << 1] + tr[i << 1 | 1];
}

void app(int i, LL a, int l, int r) {
    lz[i] = lz[i] + a;
    tr[i] = tr[i] + a * (r - l + 1);
}

void pushdown(int i, int l, int m, int r) {
    app(i << 1, lz[i], l, m);
    app(i << 1 | 1, lz[i], m + 1, r);
    lz[i] = 0;
}

void update(int l1, int r1, LL x, int i = 1, int l2 = 1, int r2 = m) {
    if (l1 <= l2 && r2 <= r1) {
        app(i, x, l2, r2);
        return;
    }
    int m2 = l2 + r2 >> 1;
    pushdown(i, l2, m2, r2);
    if (l1 <= m2)
        update(l1, r1, x, i << 1, l2, m2);
    if (m2 < r1)
        update(l1, r1, x, i << 1 | 1, m2 + 1, r2);
    tr[i] = tr[i << 1] + tr[i << 1 | 1];
}

LL query(int l1, int r1, int i = 1, int l2 = 1, int r2 = m) {
    if (l1 <= l2 && r2 <= r1)
        return tr[i];
    int m2 = l2 + r2 >> 1;
    pushdown(i, l2, m2, r2);
    return (l1 <= m2 ? query(l1, r1, i << 1, l2, m2) : 0ll) + (m2 < r1 ? query(l1, r1, i << 1 | 1, m2 + 1, r2) : 0ll);
}

void add(int x, LL val) {
    for (; x <= m; x += x & -x)
        tr1[x] += val;
}
LL get(int x) {
    LL res = 0;
    for (; x; x -= x & -x)
        res += tr1[x];
    return res;
}

int main() {
    cin >> n >> m >> q;
    rep(i, 1, n) scanf("%lld", a + i);
    rep(i, 1, m) scanf("%lld", b + i);

    a0 = a[1], b0 = b[1];
    n--, m--;
    rep(i, 1, n) a[i] = a[i + 1] - a[i];
    rep(i, 1, m) b[i] = b[i + 1] - b[i];
    build(1, 1, m);
    rep(i, 1, m) add(i, b[i] - b[i - 1]);

    LL base = (a0 + b0) * (n + m + 1);
    rep(i, 1, m) base += b[i] * (m + 1 - i);

    while (q--) {
        int type, k, d;
        scanf("%d%d%d", &type, &k, &d);
        if (type == 1) {
            if (k == n + 1)
                a0 += d, base += 1ll * d * (n + m + 1), k--;
            rep(i, n - k + 1, n) a[i] += d;
        } else {
            if (k == m + 1)
                b0 += d, base += 1ll * d * (n + m + 1), k--;
            update(m - k + 1, m, d), add(m - k + 1, d);
            base += 1ll * d * k * (k + 1) / 2;
        }

        LL ans = base;
        rep(i, 1, n) {
            LL x = a[i], l = 0, j = 1 << 18;
            for (; j; j >>= 1)
                if (l + j <= m && x >= tr1[l + j])
                    l += j, x -= tr1[l];
            ans += a[i] * (n - i + m - l + 1) + (l ? query(1, l) : 0);
        }
        printf("%lld\n", ans);
    }
    return 0;
}