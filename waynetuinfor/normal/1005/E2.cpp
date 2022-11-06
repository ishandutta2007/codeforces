#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5, tsize = 1e7;
const int inf = 1e9;
int a[maxn], b[maxn];
int lc[tsize], rc[tsize], ptr;
int sz[tsize], val[tsize], pri[tsize];

int gnode(int v) {
    lc[ptr] = rc[ptr] = -1;
    pri[ptr] = rand();
    sz[ptr] = 1;
    val[ptr] = v;
    return ptr++;
}

inline void pull(int x) {
    sz[x] = 1 + (lc[x] == -1 ? 0 : sz[lc[x]]) + (rc[x] == -1 ? 0 : sz[rc[x]]);
}

int merge(int a, int b) {
    if (a == -1 || b == -1) return a != -1 ? a : b;
    if (pri[a] > pri[b]) return rc[a] = merge(rc[a], b), pull(a), a;
    else return lc[b] = merge(a, lc[b]), pull(b), b;
}

void split(int t, int k, int &a, int &b) {
    if (t == -1) return a = b = -1, void();
    if (val[t] <= k) a = t, split(rc[t], k, rc[a], b), pull(a);
    else b = t, split(lc[t], k, a, lc[b]), pull(b);
}


namespace segtree {
    int st[maxn * 4];
    void insert(int &t, int v) {
        int a, b;
        split(t, v - 1, a, b);
        t = merge(merge(a, gnode(v)), b);
    }
    int ask(int &t, int l, int r) {
        int a, b;
        split(t, l - 1, a, b);
        int c, d;
        split(b, r, c, d);
        int res = (c != -1 ? sz[c] : 0);
        t = merge(a, merge(c, d));
        return res;
    }
    void init() {
        for (int i = 0; i < maxn * 4; ++i) 
            st[i] = -1;
    }
    void add(int l, int r, int p, int v, int o = 0) {
        insert(st[o], v);
        if (r - l == 1) return;
        if (p < (l + r) / 2) add(l, (l + r) / 2, p, v, o * 2 + 1);
        else add((l + r) / 2, r, p, v, o * 2 + 2);
    }
    int query(int l, int r, int ql, int qr, int tl, int tr, int o = 0) {
        if (l >= qr || ql >= r) return 0;
        if (l >= ql && r <= qr) return ask(st[o], tl, tr);
        return query(l, (l + r) / 2, ql, qr, tl, tr, o * 2 + 1) +
               query((l + r) / 2, r, ql, qr, tl, tr, o * 2 + 2);
    }
}

int main() {
    srand(time(nullptr));
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        b[i] = b[i - 1], a[i] = a[i - 1];
        if (x == m) ++b[i];
        if (x < m) ++a[i];
    }
    segtree::init();
    vector<int> ds;
    for (int i = 0; i <= n; ++i) ds.push_back(2 * a[i] - i);
    sort(ds.begin(), ds.end()), ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    segtree::add(0, ds.size(), lower_bound(ds.begin(), ds.end(), 0) - ds.begin(), 0);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k = lower_bound(ds.begin(), ds.end(), 2 * a[i] - i) - ds.begin();
        ans += segtree::query(0, ds.size(), k + 1, ds.size(), -inf, 2 * a[i] + 2 * b[i] - i);
        segtree::add(0, ds.size(), k, 2 * a[i] + 2 * b[i] - i);
    }
    printf("%lld\n", ans);
}