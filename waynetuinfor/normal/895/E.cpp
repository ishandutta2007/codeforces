#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    double s, tagp, tags;
    void pull() { s = lc->s + rc->s; }
    segtree(int l, int r) {
        lc = rc = nullptr; s = 0.0;
        tagp = 1.0; tags = 0.0;
        if (l == r) { s = a[l] * 1.0; return; }
        lc = new segtree(l, m); rc = new segtree(m + 1, r);
        pull();
    }
    void modify(int l, int r, int ql, int qr, double v, double p) {
        push(l, r);
        if (l > qr || ql > r) return;
        if (l >= ql && r <= qr) {
            s = s * p + 1.0 * (r - l + 1) * v;
            tagp *= p; tags = tags * p + v;
            return;
        }
        lc->modify(l, m, ql, qr, v, p); rc->modify(m + 1, r, ql, qr, v, p);
        pull();
    }
    double query(int l, int r, int ql, int qr) {
        push(l, r);
        if (l > qr || ql > r) return 0.0;
        if (l >= ql && r <= qr) return s;
        return lc->query(l, m, ql, qr) + rc->query(m + 1, r, ql, qr);
    }
    void push(int l, int r) {
        if (l == r || tags == 0.0) return;
        lc->s = lc->s * tagp + 1.0 * (m - l + 1) * tags; lc->tagp *= tagp; lc->tags = lc->tags * tagp + tags;
        rc->s = rc->s * tagp + 1.0 * (r - m) * tags; rc->tagp *= tagp; rc->tags = rc->tags * tagp + tags;
        tagp = 1.0; tags = 0.0;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    segtree *st = new segtree(1, n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
            int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
            double s1 = st->query(1, n, l1, r1);
            double s2 = st->query(1, n, l2, r2);
            s1 /= (len1 * 1.0 * len2); s2 /= (len1 * 1.0 * len2);
            double p1 = 1.0 * (r1 - l1) / (r1 - l1 + 1);        
            double p2 = 1.0 * (r2 - l2) / (r2 - l2 + 1);  
            st->modify(1, n, l1, r1, s2, p1); st->modify(1, n, l2, r2, s1, p2);
        } else {
            int l, r; cin >> l >> r;
            cout << fixed << setprecision(20) << st->query(1, n, l, r) << endl;
        }
    }
    return 0;
}