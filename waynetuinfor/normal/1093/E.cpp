#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], b[maxn], c[maxn], e[maxn], pos[maxn], d[maxn];

namespace segtree {
    struct fenwick {
        vector<int> ds, bit;
        void add(int v) { ds.push_back(v); }
        int query(int l, int r) { return query(r) - query(l - 1); }
        void done() {
            sort(ds.begin(), ds.end());
            ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
            bit.resize(ds.size() + 1);
        }
        void modify(int p, int v) {
            p = upper_bound(ds.begin(), ds.end(), p) - ds.begin();
            for (int i = p; i < (int)bit.size(); i += i & -i)
                bit[i] += v;
        }
        int query(int p) {
            p = upper_bound(ds.begin(), ds.end(), p) - ds.begin();
            int res = 0;
            for (int i = p; i > 0; i -= i & -i)
                res += bit[i];
            return res;
        }
    } st[maxn * 4];
    void make() {
        for (int i = 0; i < maxn * 4; ++i)
            st[i].done();
    }
    void add(int l, int r, int p, int v, int o = 0) {
        st[o].add(v);
        if (r - l == 1) return;
        if (p < (l + r) >> 1) add(l, (l + r) >> 1, p, v, o * 2 + 1);
        else add((l + r) >> 1, r, p, v, o * 2 + 2);
    } 
    void modify(int l, int r, int p, int v, int z, int o = 0) {
        st[o].modify(v, z);
        if (r - l == 1) return;
        if (p < (l + r) >> 1) modify(l, (l + r) >> 1, p, v, z, o * 2 + 1);
        else modify((l + r) >> 1, r, p, v, z, o * 2 + 2);
    } 
    int query(int l, int r, int ql, int qr, int x, int y, int o = 0) {
        if (l >= qr || ql >= r) return 0;
        if (l >= ql && r <= qr) return st[o].query(x, y);
        return query(l, (l + r) >> 1, ql, qr, x, y, o * 2 + 1) + 
               query((l + r) >> 1, r, ql, qr, x, y, o * 2 + 2);
    }
}

int t[maxn];
vector<int> op[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i) pos[b[i]] = i;
    for (int i = 0; i < n; ++i) c[i] = pos[a[i]];
    for (int i = 0; i < n; ++i) d[a[i]] = i;
    for (int i = 0; i < n; ++i) e[i] = b[i];
    for (int i = 0; i < n; ++i) segtree::add(0, n, i, c[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &t[i]);
        if (t[i] == 1) {
            int l, r, x, y; scanf("%d%d%d%d", &l, &r, &x, &y);
            --l, --r, --x, --y;
            op[i] = { l, r, x, y };
        } else {
            int x, y; scanf("%d%d", &x, &y);
            --x, --y;
            segtree::add(0, n, d[b[x]], y);
            segtree::add(0, n, d[b[y]], x);
            swap(b[x], b[y]);
            op[i] = { x, y };
        }
    }
    segtree::make();
    for (int i = 0; i < n; ++i) b[i] = e[i];
    for (int i = 0; i < n; ++i) segtree::modify(0, n, i, c[i], 1);
    for (int i = 0; i < m; ++i) {
        if (t[i] == 1) {
            int l = op[i][0], r = op[i][1], x = op[i][2], y = op[i][3];
            printf("%d\n", segtree::query(0, n, l, r + 1, x, y));
        } else {
            int x = op[i][0], y = op[i][1];
            segtree::modify(0, n, d[b[x]], x, -1);
            segtree::modify(0, n, d[b[x]], y, +1);
            segtree::modify(0, n, d[b[y]], y, -1);
            segtree::modify(0, n, d[b[y]], x, +1);
            swap(b[x], b[y]);
        }
    }
}