#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int a[maxn], cnt;

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    int val;
    void pull() { val = __gcd(lc->val, rc->val); }
    segtree(int l, int r) {
        lc = rc = nullptr;
        if (l == r) { val = a[l]; return; }
        lc = new segtree(l, m); rc = new segtree(m + 1, r);
        pull();
    }
    void solve(int l, int r, int ql, int qr, int x) {
        if (cnt > 1 || val % x == 0) return;
        if (l > qr || ql > r) return;
        if (l >= ql && r <= qr) {
            if (l == r && val % x) return ++cnt, void();
            if (l == r) return;
            if (lc->val % x && rc->val % x) return cnt = 2, void();
            if (lc->val % x) lc->solve(l, m, ql, qr, x);
            else rc->solve(m + 1, r, ql, qr, x);
            return;
            // lc->solve(l, m, ql, qr, x); rc->solve(m + 1, r, ql, qr, x);
        }
        lc->solve(l, m, ql, qr, x); rc->solve(m + 1, r, ql, qr, x);
    } 
    void modify(int l, int r, int p, int v) {
        if (l == r) return val = v, void();
        if (p <= m) lc->modify(l, m, p, v);
        else rc->modify(m + 1, r, p, v);
        pull();
    }
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    st = new segtree(1, n);
    int q; cin >> q; while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, x; cin >> l >> r >> x;
            cnt = 0; 
            st->solve(1, n, l, r, x);
            if (cnt > 1) puts("NO");
            else puts("YES");
        } else {
            int p, x; cin >> p >> x;
            st->modify(1, n, p, x);
        }
    }
    return 0;
}