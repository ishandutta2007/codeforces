#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxk = 6, mod = 1e9 + 7;

int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
int mul(int a, int b) { return a * 1ll * b % mod; }

int kpw[maxk][maxn], comb[maxk][maxn];

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1, a = mul(a, a)) if (n & 1) ret = mul(ret, a);
    return ret;
}

void init() {
    for (int i = 0; i < maxk; ++i) {
        for (int j = 1; j < maxn; ++j) kpw[i][j] = add(kpw[i][j - 1], fpow(j, i));
    } 
    comb[0][0] = 1;
    for (int i = 1; i < maxk; ++i) {
        for (int j = 0; j < maxn; ++j) {
            comb[i][j] = comb[i - 1][j];
            if (j > 0) comb[i][j] = add(comb[i][j], comb[i - 1][j - 1]);
        }
    }
}

int a[maxn];

struct segtree {
#define m ((l + r) >> 1)
    struct data {
        int s[maxk];
        data() { memset(s, 0, sizeof(s)); }
        data(int a, int p) {
            for (int i = 0; i < maxk; ++i) {
                int pw = fpow(p, i);
                s[i] = mul(a, pw);
            }
        }
        data(int a, int l, int r) {
            for (int i = 0; i < maxk; ++i) s[i] = mul(a, sub(kpw[i][r], kpw[i][l - 1]));
        }
        data operator+(const data &rhs) const {
            data ret;
            for (int i = 0; i < maxk; ++i) ret.s[i] = add(s[i], rhs.s[i]);
            return ret;
        }
    };
    segtree *lc, *rc;
    data dat;
    int tag;
    segtree(int l, int r) {
        tag = -1;
        if (l == r) lc = rc = nullptr, dat = data(a[l], l);
        else lc = new segtree(l, m), rc = new segtree(m + 1, r), pull();
    }
    void pull() { dat = lc->dat + rc->dat; }
    void modify(int l, int r, int ql, int qr, int x) {
        push(l, r);
        if (l > qr || ql > r) return;
        if (l >= ql && r <= qr) return tag = x, dat = data(x, l, r), void();
        lc->modify(l, m, ql, qr, x); rc->modify(m + 1, r, ql, qr, x);
        pull();
    }
    data query(int l, int r, int ql, int qr) {
        push(l, r);
        if (l > qr || ql > r) return data();
        if (l >= ql && r <= qr) return dat;
        return lc->query(l, m, ql, qr) + rc->query(m + 1, r, ql, qr);
    } 
    void push(int l, int r) {
        if (l == r || tag == -1) return;
        lc->tag = tag; lc->dat = data(tag, l, m);
        rc->tag = tag; rc->dat = data(tag, m + 1, r);
        tag = -1;
    }
#undef m
} *sgt;

int main() {
    init();
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sgt = new segtree(1, n);
    while (m--) {
        char c; int l, r, k; cin >> c >> l >> r >> k;
        if (c == '=') {
            sgt->modify(1, n, l, r, k);
            continue;
        }
        segtree::data dat = sgt->query(1, n, l, r);
        int ans = 0, coef = 1;
        for (int i = 0; i <= k; ++i) {
            int t = mul(comb[k][i], dat.s[k - i]);
            t = mul(t, fpow(l - 1, i));
            if (coef == 1) ans = add(ans, t);
            else ans = sub(ans, t);
            coef = -coef;
        }
        cout << ans << endl;
    }
    return 0;
}