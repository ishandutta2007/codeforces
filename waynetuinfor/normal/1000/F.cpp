#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
int a[maxn], l[maxn], r[maxn];
int ans[maxn], n;
vector<int> qr[maxn];
deque<int> ps[maxn];

namespace segtree {
    pair<int, int> st[maxn * 4];
    void init() { fill_n(st, maxn * 4, make_pair(maxn, maxn)); }
    void modify(int l, int r, int p, pair<int, int> v, int o = 0) {
        if (r - l == 1) return st[o] = v, void();
        if (p < (l + r) / 2) modify(l, (l + r) / 2, p, v, o * 2 + 1);
        else modify((l + r) / 2, r, p, v, o * 2 + 2);
        st[o] = min(st[o * 2 + 1], st[o * 2 + 2]);
    }
    pair<int, int> query(int l, int r, int ql, int qr, int o = 0) {
        if (l >= qr || ql >= r) return make_pair(maxn, maxn);
        if (l >= ql && r <= qr) return st[o];
        return min(query(l, (l + r) / 2, ql, qr, o * 2 + 1),
                   query((l + r) / 2, r, ql, qr, o * 2 + 2));
    }
}

set<pair<int, int>> s[maxn];

void add(int r, int l) {
    s[r].insert(make_pair(l, a[r]));
    segtree::modify(1, n + 1, r, *s[r].begin());
}

void erase(int r, int l) {
    s[r].erase(make_pair(l, a[r]));
    if (s[r].size() == 0) segtree::modify(1, n + 1, r, make_pair(maxn, maxn));
    else segtree::modify(1, n + 1, r, *s[r].begin());
}

int main() {
    scanf("%d", &n);
    segtree::init();
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int q; scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &l[i], &r[i]);
        qr[r[i]].push_back(i);
    }
    set<pair<int, int>> s;
    for (int i = 1; i <= n; ++i) {
        ps[a[i]].push_back(i);
        if (ps[a[i]].size() == 1) add(i, 0);
        else if (ps[a[i]].size() == 2) erase(ps[a[i]][0], 0), add(i, ps[a[i]][0]);
        else if (ps[a[i]].size() > 2) {
            erase(ps[a[i]][1], ps[a[i]][0]);
            ps[a[i]].pop_front();
            add(i, ps[a[i]][0]);
        }
        for (int j : qr[i]) {
            pair<int, int> p = segtree::query(1, n + 1, l[j], n + 1);
            if (p.first < l[j]) ans[j] = p.second;
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    puts("");
    return 0;
}