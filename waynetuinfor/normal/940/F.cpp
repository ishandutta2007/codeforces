#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

struct query {
    int l, r, t, lpos, rpos, idx;
    bool operator<(const query &rhs) const { return tie(lpos, rpos, t) < tie(rhs.lpos, rhs.rpos, rhs.t); }
};

pair<int, int> op[maxn];
int c[maxn], ct[maxn], a[maxn], ans[maxn];

void add(int p) { --ct[c[a[p]]], ++c[a[p]], ++ct[c[a[p]]]; }
void sub(int p) { --ct[c[a[p]]], --c[a[p]], ++ct[c[a[p]]]; }

void addt(int t, int l, int r) {
    int p = op[t].first;
    int x = a[p], y = op[t].second;
    if (p >= l && p <= r) sub(p); a[p] = y;
    if (p >= l && p <= r) add(p); op[t].second = x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> ds;
    for (int i = 1; i <= n; ++i) cin >> a[i], ds.push_back(a[i]);
    int tnow = 0, qc = 0, sz = (int)pow(n, 2.0 / 3);
    sz = max(sz, 1);
    vector<query> qry;
    for (int i = 0; i < q; ++i) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            qry.push_back({ l, r, tnow, l / sz, r / sz, qc });
            ++qc;
        } else {
            int p, v; cin >> p >> v;
            ++tnow;
            op[tnow] = make_pair(p, v);
            ds.push_back(v);
        }
    }
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin() + 1;
    for (int i = 1; i <= tnow; ++i) op[i].second = lower_bound(ds.begin(), ds.end(), op[i].second) - ds.begin() + 1;
    ct[0] = ds.size() + 1;
    sort(qry.begin(), qry.end());
    for (int l = 1, r = 0, t = 0, i = 0; i < qry.size(); ++i) {
        while (t < qry[i].t) addt(++t, l, r); while (t > qry[i].t) addt(t--, l, r);
        while (r < qry[i].r) add(++r); while (r > qry[i].r) sub(r--);
        while (l > qry[i].l) add(--l); while (l < qry[i].l) sub(l++);
        ans[qry[i].idx] = 1;
        while (ct[ans[qry[i].idx]] > 0) ++ans[qry[i].idx];
    } 
    for (int i = 0; i < qc; ++i) cout << ans[i] << '\n';
    return 0;
}