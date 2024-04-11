#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int inf = 1e9;

namespace segtree {
    struct data {
        vector<int> x, y;
        data() {}
        data(int sz) {
            x.resize(sz, -inf);
            y.resize(sz, +inf);
        }
        data(const vector<int> &p) {
            int k = (int)p.size();
            x.resize(1 << k, -inf);
            y.resize(1 << k, +inf);
            for (int i = 0; i < (1 << k); ++i) {
                int s = 0;
                for (int j = 0; j < k; ++j) {
                    if (i >> j & 1) s += p[j];
                    else s -= p[j];
                }
                x[i] = max(x[i], s);
                y[i] = min(y[i], s);
            }
        }
        data operator+(const data &d) const {
            data res(x.size());
            for (int i = 0; i < (int)x.size(); ++i) {
                res.x[i] = max(res.x[i], x[i]);
                res.x[i] = max(res.x[i], d.x[i]);
                res.y[i] = min(res.y[i], y[i]);
                res.y[i] = min(res.y[i], d.y[i]);
            }
            return res;
        }
    }; 
    data st[maxn * 4];
    void build(int l, int r, const vector<vector<int>> &p, int o = 0) {
        if (r - l == 1) return st[o] = data(p[l]), void();
        build(l, (l + r) >> 1, p, o * 2 + 1);
        build((l + r) >> 1, r, p, o * 2 + 2);
        st[o] = st[o * 2 + 1] + st[o * 2 + 2];
    }
    void modify(int l, int r, int z, const vector<int> &p, int o = 0) {
        if (r - l == 1) return st[o] = data(p), void();
        if (z < (l + r) >> 1) modify(l, (l + r) >> 1, z, p, o * 2 + 1);
        else modify((l + r) >> 1, r, z, p, o * 2 + 2);
        st[o] = st[o * 2 + 1] + st[o * 2 + 2];
    }
    data query(int l, int r, int ql, int qr, int o = 0) {
        if (l >= ql && r <= qr) return st[o];
        if (qr <= (l + r) >> 1) return query(l, (l + r) >> 1, ql, qr, o * 2 + 1);
        if (ql >= (l + r) >> 1) return query((l + r) >> 1, r, ql, qr, o * 2 + 2);
        return query(l, (l + r) >> 1, ql, qr, o * 2 + 1) +
               query((l + r) >> 1, r, ql, qr, o * 2 + 2);
    } 
}

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<vector<int>> p(n);
    for (int i = 0; i < n; ++i) {
        p[i].resize(k);
        for (int j = 0; j < k; ++j) scanf("%d", &p[i][j]);
    }
    segtree::build(0, n, p);
    int q; scanf("%d", &q);
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int z; vector<int> p(k);
            scanf("%d", &z); z--;
            for (int i = 0; i < k; ++i) scanf("%d", &p[i]);
            segtree::modify(0, n, z, p);
        } else {
            int l, r; scanf("%d%d", &l, &r);
            segtree::data res = segtree::query(0, n, l - 1, r);
            int ans = 0;
            for (int i = 0; i < (1 << k); ++i) ans = max(ans, res.x[i] - res.y[i]);
            printf("%d\n", ans);
        }
    }
}