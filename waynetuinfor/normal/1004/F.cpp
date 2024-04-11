#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], x;

void add(vector<pair<int, int>> &v, pair<int, int> p) {
    assert(v.size() == 0 || p.second >= v.back().second);
    if (v.size() && v.back().second == p.second)
        v.back().first += p.first;
    else
        v.push_back(p);
}

namespace segtree {
    struct data {
        long long ans;
        vector<pair<int, int>> prefix, suffix;
        data() = default;
        data(int v) {
            if (v >= x) ans = 1;
            else ans = 0;
            prefix.emplace_back(1, v);
            suffix.emplace_back(1, v);
        }
        data operator+(const data &rhs) const {
            data res; res.ans = ans + rhs.ans;
            for (int i = 0; i < (int)prefix.size(); ++i) 
                add(res.prefix, prefix[i]);
            for (int i = 0; i < (int)rhs.prefix.size(); ++i) 
                add(res.prefix, make_pair(rhs.prefix[i].first, rhs.prefix[i].second | prefix.back().second));
            for (int i = 0; i < (int)rhs.suffix.size(); ++i)
                add(res.suffix, rhs.suffix[i]);
            for (int i = 0; i < (int)suffix.size(); ++i)
                add(res.suffix, make_pair(suffix[i].first, suffix[i].second | rhs.suffix.back().second));
            int j = rhs.prefix.size() - 1, s = 0;
            for (int i = 0; i < (int)suffix.size(); ++i) {
                while (j >= 0 && (suffix[i].second | rhs.prefix[j].second) >= x) {
                    s += rhs.prefix[j].first;
                    --j;
                }
                res.ans += suffix[i].first * 1ll * s;
            }
            return res;
        }
    } st[maxn * 4];
    void build(int l, int r, int o = 0) {
        if (r - l == 1) return st[o] = data(a[l]), void();
        build(l, (l + r) >> 1, o * 2 + 1);
        build((l + r) >> 1, r, o * 2 + 2);
        st[o] = st[o * 2 + 1] + st[o * 2 + 2];
    } 
    void modify(int l, int r, int p, int v, int o = 0) {
        if (r - l == 1) return st[o] = data(v), void();
        if (p < (l + r) >> 1) modify(l, (l + r) >> 1, p, v, o * 2 + 1);
        else modify((l + r) >> 1, r, p, v, o * 2 + 2);
        st[o] = st[o * 2 + 1] + st[o * 2 + 2];
    } 
    data query(int l, int r, int ql, int qr, int o = 0) {
        if (l >= ql && r <= qr) return st[o];
        if (qr <= ((l + r) >> 1)) return query(l, (l + r) >> 1, ql, qr, o * 2 + 1);
        if (ql >= ((l + r) >> 1)) return query((l + r) >> 1, r, ql, qr, o * 2 + 2);
        return query(l, (l + r) >> 1, ql, qr, o * 2 + 1) +
               query((l + r) >> 1, r, ql, qr, o * 2 + 2);
    }
}

int main() {
    int n, m; scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    segtree::build(0, n);
    while (m--) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        if (a == 1) segtree::modify(0, n, b - 1, c);
        else printf("%lld\n", segtree::query(0, n, b - 1, c).ans);
    }
    return 0;
}