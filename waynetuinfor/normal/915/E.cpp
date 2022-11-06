#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e6 + 10;
int l[maxn], r[maxn], k[maxn];
int w[maxn], pos[maxn];

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    int sum, weight, tag;
    void pull() { sum = lc->sum + rc->sum; weight = lc->weight + rc->weight; }
    segtree(int l, int r) {
        lc = rc = nullptr; sum = weight = 0; tag = -1;
        if (l == r) { weight = sum = w[l]; return; }
        lc = new segtree(l, m); rc = new segtree(m + 1, r);
        pull();
    }
    void modify(int l, int r, int ql, int qr, int v) {
        push();
        if (l > qr || ql > r) return;
        if (l >= ql && r <= qr) return tag = v, sum = v * weight, void();
        lc->modify(l, m, ql, qr, v); rc->modify(m + 1, r, ql, qr, v);
        pull();
    }
    void push() {
        if (!lc || tag == -1) return;
        lc->sum = tag * lc->weight; lc->tag = tag;
        rc->sum = tag * rc->weight; rc->tag = tag;
        tag = -1;
    }
    void dfs(int l, int r) {
        push();
        cout << "l = " << l << " r = " << r << " sum = " << sum << " weight = " << weight << endl;
        if (l == r) return;
        lc->dfs(l, m); rc->dfs(m + 1, r);
    }
#undef m
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> ds;
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i] >> k[i];
        ds.push_back(l[i]), ds.push_back(r[i]);
    }
    ds.push_back(1); ds.push_back(n);
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    int it = 0;
    w[it++] = ds[0] - 1; w[it++] = 1;
    pos[0] = it - 1;
    for (int i = 1; i < ds.size(); ++i) {
        w[it++] = ds[i] - ds[i - 1] - 1;
        w[it++] = 1;
        pos[i] = it - 1;
    }
    // cout << "ds = " << endl;
    // for (int i = 0; i < ds.size(); ++i) cout << ds[i] << ' '; cout << endl;
    // cout << "w = " << endl;
    // for (int i = 0; i < it; ++i) cout << w[i] << ' '; cout << endl;
    --it;
    st = new segtree(0, it);
    for (int i = 0; i < q; ++i) {
        int ql = lower_bound(ds.begin(), ds.end(), l[i]) - ds.begin();
        int qr = lower_bound(ds.begin(), ds.end(), r[i]) - ds.begin();
        ql = pos[ql]; qr = pos[qr];
        // cout << "ql = " << ql << " qr = " << qr << " w[ql] = " << w[ql] << " w[qr] = " << w[qr] << endl;
        st->modify(0, it, ql, qr, (k[i] == 2));
        st->push();
        cout << st->sum << '\n';
        // st->dfs(0, it); cout << endl;
    }
    return 0;
}