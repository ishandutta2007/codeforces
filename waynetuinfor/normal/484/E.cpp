#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, inf = 1e9 + 1;
int h[maxn], lto[maxn], rto[maxn];
int ans[maxn], n;

struct query { int l, r, w, idx; };

struct segtree {
    struct data {
        int lz, rz, ans, sz;
        int ql, qr;
        data() {}
        data(int l, int r, int v) {
            ql = l; qr = r;
            sz = r - l + 1;
            lz = rz = ans = v * sz;
        }
        data operator+(const data &d) const {
            if (d.sz == 0 || sz == 0) return sz == 0 ? d : (*this);
            data res(ql, d.qr, 0);
            res.lz = (lz == sz ? lz + d.lz : lz); res.rz = (d.rz == d.sz ? d.rz + rz : d.rz);
            res.ans = max(ans, d.ans); res.ans = max(res.ans, max(res.lz, res.rz));
            res.ans = max(res.ans, rz + d.lz);
            return res;
        }
    } t[maxn * 4];
    int tag[maxn * 4];
    segtree() {}
    segtree(int l, int r) { build(l, r); };
    void build(int l, int r, int o = 1) {
        tag[o] = 1; t[o] = data(l, r, 0);
        if (l == r) return;
        build(l, (l + r) / 2, o * 2); build((l + r) / 2 + 1, r, o * 2 + 1);
        pull(o);
    }
    void modify(int l, int r, int ql, int qr, int v, int o = 1) {
        push(l, r, o);
        if (l > qr || ql > r) return;
        if (l >= ql && r <= qr) return tag[o] = v, t[o] = data(l, r, v), void();
        modify(l, (l + r) / 2, ql, qr, v, o * 2); modify((l + r) / 2 + 1, r, ql, qr, v, o * 2 + 1);
        pull(o);
    } 
    data query(int l, int r, int ql, int qr, int o = 1) {
        push(l, r, o);
        if (l > qr || ql > r) return data(0, -1, 0);
        if (l >= ql && r <= qr) return t[o];
        return query(l, (l + r) / 2, ql, qr, o * 2) + query((l + r) / 2 + 1, r, ql, qr, o * 2 + 1);
    }
    void pull(int o) { t[o] = t[o * 2] + t[o * 2 + 1]; }
    void push(int l, int r, int o) {
        if (l == r || tag[o] == -1) return;
        t[o * 2 + 0] = data(l, (l + r) / 2 + 0, tag[o]); tag[o * 2 + 0] = tag[o];
        t[o * 2 + 1] = data((l + r) / 2 + 1, r, tag[o]); tag[o * 2 + 1] = tag[o];
        tag[o] = -1;
    }
} sgt;

void dvcq(int l, int r, const vector<query> &qr, const vector<int> &s) {
    if (l == r) {
        for (int i = 0; i < qr.size(); ++i) ans[qr[i].idx] = l;
        return;
    }
    if (qr.size() == 0) return;
    int m = l + r >> 1;
    for (int i = 0; i < s.size(); ++i) if (h[s[i]] >= m) sgt.modify(1, n, lto[s[i]], rto[s[i]], 1);
    // printf("l = %d r = %d\n", l, r);
    // for (int i = 0; i < qr.size(); ++i) printf("%d ", qr[i].idx); puts("");
    // for (int i = 0; i < s.size(); ++i) printf("%d ", s[i]); puts("");
    // printf("on");
    vector<query> lq, rq; vector<int> ls, rs;
    for (int i = 0; i < qr.size(); ++i) {
        int k = sgt.query(1, n, qr[i].l, qr[i].r).ans;
        if (k >= qr[i].w) rq.push_back(qr[i]);
        else lq.push_back(qr[i]);
    }
    for (int i = 0; i < s.size(); ++i) {
        if (h[s[i]] < m) ls.push_back(s[i]);
        else rs.push_back(s[i]);
    }
    for (int i = 0; i < s.size(); ++i) if (h[s[i]] >= m) sgt.modify(1, n, lto[s[i]], rto[s[i]], 0);
    // printf("off");
    dvcq(l, m, lq, ls); dvcq(m + 1, r, rq, rs);
}

int main() {
    scanf("%d", &n);
    vector<int> ds;
    for (int i = 1; i <= n; ++i) scanf("%d", h + i), ds.push_back(h[i]);
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 1; i <= n; ++i) h[i] = lower_bound(ds.begin(), ds.end(), h[i]) - ds.begin();
    int m; scanf("%d", &m);
    vector<query> qr;
    for (int i = 0; i < m; ++i) {
        int l, r, w; scanf("%d %d %d", &l, &r, &w);
        qr.push_back({ l, r, w, i });
    }
    for (int i = 1; i <= n; ++i) {
        lto[i] = i - 1;
        while (lto[i] > 0 && h[lto[i]] >= h[i]) lto[i] = lto[lto[i]];
    }
    for (int i = n; i > 0; --i) {
        rto[i] = i + 1;
        while (rto[i] <= n && h[rto[i]] > h[i]) rto[i] = rto[rto[i]];
    }
    for (int i = 1; i <= n; ++i) ++lto[i], --rto[i];
    // for (int i = 1; i <= n; ++i) printf("lto[%d] = %d, rto[%d] = %d\n", i, lto[i], i, rto[i]);
    vector<int> s(n); iota(s.begin(), s.end(), 1);
    dvcq(0, ds.size(), qr, s);
    for (int i = 0; i < m; ++i) printf("%d\n", ds[ans[i] - 1]);
    return 0;
}