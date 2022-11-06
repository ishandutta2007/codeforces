#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5, mod = (int)1e9 + 87, p = 131;
int a[maxn], pw[maxn];

namespace segtree {
    const int size = maxn * 4;
    struct data {
       int sz, lz, rz;
       data() {}
       data(int s, int t) {
           sz = s;
           lz = rz = t;
       }
       data operator+(const data &rhs) const {
           if (sz == 0 || rhs.sz == 0) return sz ? (*this) : rhs;
           data ret(sz + rhs.sz, 0);
            ret.lz = (lz * 1ll * pw[rhs.sz] % mod + rhs.lz) % mod;
            ret.rz = (rhs.rz * 1ll * pw[sz] % mod + rz) % mod;
           return ret;
       }
    } dat[size];
    void build(int l, int r, int o = 1) {
        if (r - l == 1) return dat[o] = data(1, 1), void();
        build(l, (l + r) / 2, o * 2), build((l + r) / 2, r, o * 2 + 1);
        dat[o] = dat[o * 2] + dat[o * 2 + 1];
    }
    void modify(int l, int r, int p, int v, int o = 1) {
        if (r - l == 1) return dat[o] = data(1, v), void();
        if (p < (l + r) / 2) modify(l, (l + r) / 2, p, v, o * 2);
        else modify((l + r) / 2, r, p, v, o * 2 + 1);
        dat[o] = dat[o * 2] + dat[o * 2 + 1];
    }
    data query(int l, int r, int ql, int qr, int o = 1) {
        if (l >= qr || ql >= r) return data(0, 0);
        if (l >= ql && r <= qr) return dat[o];
        return query(l, (l + r) / 2, ql, qr, o * 2) + query((l + r) / 2, r, ql, qr, o * 2 + 1);
    }
};

int main() {
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) pw[i] = pw[i - 1] * 1ll * p % mod;
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i), --a[i];
    segtree::build(0, n);
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0 && a[i] < n - 1) {
            int z = min(a[i], n - 1 - a[i]);
            segtree::data l = segtree::query(0, n, a[i] - z, a[i]);
            segtree::data r = segtree::query(0, n, a[i] + 1, a[i] + z + 1);
            if (l.lz != r.rz) return 0 * puts("YES");
        }
        segtree::modify(0, n, a[i], 0);
    }
    puts("NO");
    return 0;
}