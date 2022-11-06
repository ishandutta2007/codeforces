#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }
inline void cadd(int &a, int b) { a = add(a, b); }
inline void csub(int &a, int b) { a = sub(a, b); }
inline void cmul(int &a, int b) { a = mul(a, b); }

vector<int> G[maxn];
int tin[maxn], tout[maxn], t, n, dep[maxn];

void dfs(int now, int fa, int d) {
    tin[now] = ++t; dep[now] = d;
    for (int u : G[now]) if (u != fa) dfs(u, now, d + 1);
    tout[now] = t;
}

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    struct data {
        int k, v, kd;
        data(): k(0), v(0), kd(0) {}
        data(int a, int b, int c): k(a), v(b), kd(c) {}
        data operator+(const data &rhs) { return data(add(k, rhs.k), add(v, rhs.v), add(kd, rhs.kd)); }
        bool operator==(const data &rhs) const { return k == rhs.k && v == rhs.v && kd == rhs.kd; }
    } dat, tag;
    segtree(int l, int r) {
        lc = rc = nullptr;
        if (l == r) return;
        lc = new segtree(l, m); rc = new segtree(m + 1, r);
    }
    void pull() { dat = lc->dat + rc->dat; } 
    void push() {
        if (!lc || tag == data(0, 0, 0)) return;
        lc->dat = lc->dat + tag; lc->tag = lc->tag + tag;
        rc->dat = rc->dat + tag; rc->tag = rc->tag + tag;
        tag = data(0, 0, 0);
    }
    void modify(int l, int r, int ql, int qr, int k, int v, int d) {
        push();
        if (l > qr || ql > r) return; 
        if (l >= ql && r <= qr) return dat = dat + data(k, v, mul(k, d)), tag = tag + data(k, v, mul(k, d)), void();
        lc->modify(l, m, ql, qr, k, v, d); rc->modify(m + 1, r, ql, qr, k, v, d);
        pull();
    }
    data query(int l, int r, int p) {
        push();
        if (l == r) return dat;
        if (p <= m) return lc->query(l, m, p);
        else return rc->query(m + 1, r, p);
    }
} *st;

void modify(int v, int k, int x) { st->modify(1, n, tin[v], tout[v], k, x, dep[v]); }

int query(int v) {
    segtree::data dat = st->query(1, n, tin[v]);
    return sub(dat.v, sub(mul(dat.k, dep[v]), dat.kd));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[p].push_back(i); G[i].push_back(p);
    }
    dfs(1, 0, 0);
    st = new segtree(1, n);
    int q; cin >> q;
    while (q--) {
        int t, v, x, k; cin >> t;
        if (t == 1) cin >> v >> x >> k, modify(v, k, x);
        else cin >> v, cout << query(v) << '\n';
    }
    return 0;
}