#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10, lg = 20;
int a[maxn];

struct data {
    int l, r, t, len;
    data(): l(0), r(0), t(0), len(0) {}
    data(int a, int b, int c, int d): l(a), r(b), t(c), len(d) {}
    data operator+(const data& d) const {
        data ret; ret.len = len + d.len;
        if (l == len && d.r == d.len) {
            ret.l = ret.r = len + d.len;
            ret.t = ret.l * (ret.l + 1) / 2;
            return ret;
        }
        if (l == len) {
            ret.l = d.l + l;
            ret.r = d.r;
            ret.t = d.t - d.l * (d.l + 1) / 2;
            ret.t += ret.l * (ret.l + 1) / 2;
            return ret;
        } 
        if (d.r == d.len) {
            ret.r = d.r + r;
            ret.l = l;
            ret.t = t - r * (r + 1) / 2;
            ret.t += ret.r * (ret.r + 1) / 2;
            return ret;
        }
        ret.l = l; ret.r = d.r;
        ret.t = t + d.t;
        ret.t -= r * (r + 1) / 2; ret.t -= d.l * (d.l + 1) / 2;
        ret.t += (d.l + r) * (d.l + r + 1) / 2;
        return ret;
    }
};

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[400000];
    static SegmentTree *ptr;
    data val[lg];
    SegmentTree *lc, *rc;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        if (L == R) {
            for (int i = 0; i < lg; ++i) {
                int bit = (a[L] >> i) & 1;
                val[i] = data(bit, bit, bit, 1);
            }
            return;
        }
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        for (int i = 0; i < lg; ++i) val[i] = lc->val[i] + rc->val[i];
    }
    void modify(int L, int R, int x, int v) {
        if (L == R) {
            for (int i = 0; i < lg; ++i) {
                int bit = (v >> i) & 1;
                val[i] = data(bit, bit, bit, 1);
            }
            return;
        }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
#undef M
} *st, SegmentTree::mem[400000], *SegmentTree::ptr = mem;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    st = new (SegmentTree::ptr++) SegmentTree(1, n);
    while (m--) {
        int p, v; cin >> p >> v;
        st->modify(1, n, p, v);
        unsigned long long ans = 0;
        for (int i = 0; i < lg; ++i) ans += st->val[i].t * (1 << i);
        cout << ans << '\n';
    }
    return 0;
}