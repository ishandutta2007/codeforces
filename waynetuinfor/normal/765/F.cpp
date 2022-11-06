#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class c> struct rge { c bg, ed; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
struct debug {
~debug() { cerr << endl; }
template <class c> typename \
enable_if <sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return *this; }
template <class c> typename \
enable_if <sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) { return *this << range(begin(i), end(i)); }
template <class c, class b> debug &operator<<(pair<c, b> p) { return *this << "(" << p.first << ", " << p.second << ")"; }
template <class c> debug &operator<<(rge<c> d) { *this << "[ "; for (auto it = d.bg; it != d.ed; ++it) *this << ", " + 2 * (it == d.bg) << *it; return *this << " ]"; }
};

const int maxn = 3e5 + 10, inf = 1e9 + 1;
int a[maxn], l[maxn], r[maxn], ans[maxn];
vector<int> to[maxn];
vector<int> query[maxn];

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    int pos;
    segtree(int l, int r) {
        if (l == r) lc = rc = nullptr, pos = maxn + 1;
        else lc = new segtree(l, m), rc = new segtree(m + 1, r), pull();
    }
    void pull() { pos = min(lc->pos, rc->pos); }
    void modify(int l, int r, int p, int v) {
        if (l == r) return pos = min(pos, v), void();
        if (p <= m) lc->modify(l, m, p, v);
        else rc->modify(m + 1, r, p, v);
        pull();
    }
    int query(int l, int r, int ql, int qr) {
        if (l > qr || ql > r) return maxn + 1;
        if (l >= ql && r <= qr) return pos;
        return min(lc->query(l, m, ql, qr), rc->query(m + 1, r, ql, qr));
    }
#undef m
} *st;

void init(int n) {
    vector<int> ds(a + 1, a + n + 1);
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    st = new segtree(0, ds.size() - 1);
    for (int i = n; i > 0; --i) {
        int now = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin();
        int jnow = st->query(0, ds.size() - 1, now, ds.size() - 1);
        if (jnow == maxn + 1) {
            st->modify(0, ds.size() - 1, now, i);
            continue;
        }
        to[i].push_back(jnow);
        while (true) {
            int tar = (a[i] + a[jnow]) >> 1;
            int p = lower_bound(ds.begin(), ds.end(), tar) - ds.begin() - 1;
            int know = st->query(0, ds.size() - 1, now, p);
            if (know == maxn + 1) break;
            to[i].push_back(jnow = know);
        }
        st->modify(0, ds.size() - 1, now, i);
    }
    st = new segtree(0, ds.size() - 1);
    for (int i = n; i > 0; --i) {
        int now = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin();
        int jnow = st->query(0, ds.size() - 1, 0, now);
        if (jnow == maxn + 1) {
            st->modify(0, ds.size() - 1, now, i);
            continue;
        }
        to[i].push_back(jnow);
        while (true) {
            int tar = a[i] + a[jnow] >> 1;
            int p = upper_bound(ds.begin(), ds.end(), tar) - ds.begin();
            int know = st->query(0, ds.size() - 1, p, now);
            if (know == maxn + 1) break;
            to[i].push_back(jnow = know);
        }
        st->modify(0, ds.size() - 1, now, i);
    }
}

struct fenwick {
    int dat[maxn];
    void init() { fill(dat, dat + maxn, inf); }
    void add(int p, int v) { for (; p < maxn; p += p & -p) dat[p] = min(dat[p], v); }
    int qry(int p, int v = inf) { for (; p; p -= p & -p) v = min(v, dat[p]); return v; }
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    init(n);
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i];
        query[l[i]].push_back(i);
    }
    bit.init();
    for (int i = n; i >= 1; --i) {
        for (int j : to[i]) bit.add(j, abs(a[j] - a[i]));
        for (int j : query[i]) ans[j] = bit.qry(r[j]);
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
    return 0;
}