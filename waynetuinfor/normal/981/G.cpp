#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 998244353;

namespace segtree {
    int st[maxn * 4], sz[maxn * 4];
    int tg[maxn * 4], sc[maxn * 4];
    void build(int l, int r, int o = 0) {
        st[o] = tg[o] = 0, sc[o] = 1, sz[o] = r - l;
        if (r - l == 1) return;
        build(l, (l + r) / 2, o * 2 + 1);
        build((l + r) / 2, r, o * 2 + 2);
    }
    void push(int o) {
        if (sz[o] == 1) return;
        st[o * 2 + 1] = (st[o * 2 + 1] * 1ll * sc[o] % mod + sz[o * 2 + 1] * 1ll * tg[o] % mod) % mod;
        sc[o * 2 + 1] = sc[o * 2 + 1] * 1ll * sc[o] % mod;
        tg[o * 2 + 1] = (tg[o * 2 + 1] * 1ll * sc[o] % mod + tg[o]) % mod;
        st[o * 2 + 2] = (st[o * 2 + 2] * 1ll * sc[o] % mod + sz[o * 2 + 2] * 1ll * tg[o] % mod) % mod;
        sc[o * 2 + 2] = sc[o * 2 + 2] * 1ll * sc[o] % mod;
        tg[o * 2 + 2] = (tg[o * 2 + 2] * 1ll * sc[o] % mod + tg[o]) % mod;
        sc[o] = 1, tg[o] = 0;
    }
    void add(int l, int r, int ql, int qr, int v, int o = 0) {
        push(o);
        if (l >= qr || ql >= r) return;
        if (l >= ql && r <= qr) {
            (tg[o] += v) %= mod;
            (st[o] += sz[o] * 1ll * v % mod) %= mod;
            return;
        }
        add(l, (l + r) / 2, ql, qr, v, o * 2 + 1);
        add((l + r) / 2, r, ql, qr, v, o * 2 + 2);
        st[o] = st[o * 2 + 1] + st[o * 2 + 2];
        st[o] %= mod;
    }
    void mul(int l, int r, int ql, int qr, int v, int o = 0) {
        push(o);
        if (l >= qr || ql >= r) return;
        if (l >= ql && r <= qr) {
            sc[o] = sc[o] * 1ll * v % mod;
            tg[o] = tg[o] * 1ll * v % mod;
            st[o] = st[o] * 1ll * v % mod;
            return;
        }
        mul(l, (l + r) / 2, ql, qr, v, o * 2 + 1);
        mul((l + r) / 2, r, ql, qr, v, o * 2 + 2);
        st[o] = st[o * 2 + 1] + st[o * 2 + 2];
        st[o] %= mod;
    }
    int query(int l, int r, int ql, int qr, int o = 0) {
        push(o);
        if (l >= qr || ql >= r) return 0;
        if (l >= ql && r <= qr) return st[o];
        return (query(l, (l + r) / 2, ql, qr, o * 2 + 1) + query((l + r) / 2, r, ql, qr, o * 2 + 2)) % mod;
    }
}

set<pair<int, int>> pos[maxn];
int n;
 
void insert(int l, int r, int x) {
    vector<pair<int, int>> seg;
    auto it = pos[x].lower_bound(make_pair(l, -1));
    while (it != pos[x].end()) {
        if (it->second > r) break;
        seg.emplace_back(it->second, it->first);
        ++it;
    }
    if (seg.size() == 0) {
        pos[x].insert(make_pair(r, l));
        segtree::add(0, n, l, r + 1, 1);
        return;
    }
    int tl = l, tr = r;
    for (int i = 0; i < seg.size(); ++i) {
        if (i == 0 && seg[i].first > l) segtree::add(0, n, l, seg[i].first, 1);
        if (i == seg.size() - 1 && seg[i].second < r) segtree::add(0, n, seg[i].second + 1, r + 1, 1);
        if (i) segtree::add(0, n, seg[i - 1].second + 1, seg[i].first, 1);
        int ql = max(seg[i].first, l), qr = min(seg[i].second, r);
        if (ql <= qr) segtree::mul(0, n, ql, qr + 1, 2);
        tl = min(tl, seg[i].first), tr = max(tr, seg[i].second);
    }
    for (int i = 0; i < seg.size(); ++i) pos[x].erase(make_pair(seg[i].second, seg[i].first));
    pos[x].insert(make_pair(tr, tl));
}

int main() {
    int q; scanf("%d %d", &n, &q);
    segtree::build(0, n);
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int l, r, x; scanf("%d %d %d", &l, &r, &x);
            --l, --r;
            insert(l, r, x);
        } else {
            int l, r; scanf("%d %d", &l, &r);
            --l;
            printf("%d\n", segtree::query(0, n, l, r));
        }
    }
    return 0;
}