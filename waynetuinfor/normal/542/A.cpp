#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int maxc = 8e5 + 5;
int l[maxn], r[maxn], tl[maxn], tr[maxn];
int a[maxn], b[maxn], c[maxn], ta[maxn], tb[maxn];

struct SegTree {
    pair<int, int> st[maxc * 4];

    void init() {
        for (int i = 0; i < maxc * 4; ++i)
            st[i] = make_pair(-1e9, -1);
    }

    void modify(int l, int r, int p, int v, int z, int o = 0) {
        if (r - l == 1)
            return st[o] = max(st[o], make_pair(v, z)), void();
        if (p < (l + r) >> 1)
            modify(l, (l + r) >> 1, p, v, z, o * 2 + 1);
        else
            modify((l + r) >> 1, r, p, v, z, o * 2 + 2);
        st[o] = max(st[o * 2 + 1], st[o * 2 + 2]);
    }

    pair<int, int> query(int l, int r, int ql, int qr, int o = 0) {
        if (l >= ql && r <= qr) return st[o];
        if (l >= qr || ql >= r) return make_pair(-1e9, -1);
        return max(query(l, (l + r) >> 1, ql, qr, o * 2 + 1),
                query((l + r) >> 1, r, ql, qr, o * 2 + 2));
    }
} st1, st2;

int main() {
    int n, m; scanf("%d%d", &n, &m);

    vector<int> ds;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        ds.push_back(l[i]);
        ds.push_back(r[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        ds.push_back(a[i]);
        ds.push_back(b[i]);
    }

    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());

    for (int i = 0; i < n; ++i) {
        tl[i] = lower_bound(ds.begin(), ds.end(), l[i]) - ds.begin();
        tr[i] = lower_bound(ds.begin(), ds.end(), r[i]) - ds.begin();
    }
    for (int i = 0; i < m; ++i) {
        ta[i] = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin();
        tb[i] = lower_bound(ds.begin(), ds.end(), b[i]) - ds.begin();
    }

    vector<int> ch(m), vd(n);
    iota(ch.begin(), ch.end(), 0);
    sort(ch.begin(), ch.end(), [&](int i, int j) { return b[i] < b[j]; });
    iota(vd.begin(), vd.end(), 0);
    sort(vd.begin(), vd.end(), [&](int i, int j) { return r[i] < r[j]; });

    st1.init(), st2.init();

    long long ans = 0;
    int zch = -1, zvd = -1;

    auto update = [&](int x, int y) {
        if (x == -1) return;
        int pl = max(l[x], a[y]), pr = min(r[x], b[y]);
        if (pr >= pl) {
            long long z = 1LL * (pr - pl) * c[y];
            if (z > ans) {
                ans = z;
                zvd = x;
                zch = y;
            }
        }
    };

    for (int i = 0, j = 0; i < m; ++i) {
        while (j < n && r[vd[j]] <= b[ch[i]]) {
            st1.modify(0, ds.size(), tl[vd[j]], r[vd[j]] - l[vd[j]], vd[j]);
            st2.modify(0, ds.size(), tl[vd[j]], r[vd[j]], vd[j]);
            ++j;
        }
        update(st1.query(0, ds.size(), ta[ch[i]], ds.size()).second, ch[i]);
        update(st2.query(0, ds.size(), 0, ta[ch[i]]).second, ch[i]);
    }

    iota(ch.begin(), ch.end(), 0);
    sort(ch.begin(), ch.end(), [&](int i, int j) { return a[i] > b[j]; });
    iota(vd.begin(), vd.end(), 0);
    sort(vd.begin(), vd.end(), [&](int i, int j) { return l[i] > r[j]; });

    st1.init(), st2.init();

    for (int i = 0, j = 0; i < m; ++i) {
        while (j < n && l[vd[j]] >= a[ch[i]]) {
            st1.modify(0, ds.size(), tr[vd[j]], r[vd[j]] - l[vd[j]], vd[j]);
            st2.modify(0, ds.size(), tr[vd[j]], -l[vd[j]], vd[j]);
            ++j;
        }
        update(st1.query(0, ds.size(), 0, tb[ch[i]] + 1).second, ch[i]);
        update(st2.query(0, ds.size(), tb[ch[i]] + 1, ds.size()).second, ch[i]);
    }

    iota(ch.begin(), ch.end(), 0);
    sort(ch.begin(), ch.end(), [&](int i, int j) { return b[i] < b[j]; });
    iota(vd.begin(), vd.end(), 0);
    sort(vd.begin(), vd.end(), [&](int i, int j) { return r[i] < r[j]; });

    set<pair<int, int>> st;
    for (int i = 0; i < n; ++i) st.insert(make_pair(l[i], i));
    for (int i = 0, j = 0; i < m; ++i) {
        while (j < n && r[vd[j]] < b[ch[i]]) {
            st.erase(make_pair(l[vd[j]], vd[j]));
            ++j;
        }
        auto it = st.upper_bound(make_pair(a[ch[i]], 1e9));
        if (it != st.begin()) update(prev(it)->second, ch[i]);
    }

    printf("%lld\n", ans);
    if (ans) printf("%d %d\n", zvd + 1, zch + 1);
    return 0;
}