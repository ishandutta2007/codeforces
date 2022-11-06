#include <bits/stdc++.h>
using namespace std;

struct segtree {
#define m ((l + r) >> 1)
    segtree *lc, *rc;
    int val;
    segtree(int l, int r) {
        val = 0;
        if (l == r) lc = rc = nullptr;
        else lc = new segtree(l, m), rc = new segtree(m + 1, r);
    }
    void pull() { val = max(lc->val, rc->val); }
    int query(int l, int r, int ql, int qr) {
        if (l > qr || ql > r) return 0;
        if (l >= ql && r <= qr) return val;
        return max(lc->query(l, m, ql, qr), rc->query(m + 1, r, ql, qr));
    }
    void modify(int l, int r, int p, int v) {
        if (l == r) return val = max(val, v), void();
        if (p <= m) lc->modify(l, m, p, v);
        else rc->modify(m + 1, r, p, v);
        pull();
    }
#undef m
} *sgt;

const int maxn = 2e5 + 10;
int a[maxn], l[maxn], r[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> ds;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; a[i] -= i;
        ds.push_back(a[i]); ds.push_back(a[i] + 1);
    }
    sort(ds.begin(), ds.end()); ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    sgt = new segtree(0, ds.size() - 1);
    for (int i = 1; i <= n; ++i) {
        int p = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin();
        l[i] = sgt->query(0, ds.size() - 1, 0, p) + 1;
        sgt->modify(0, ds.size() - 1, p, l[i]);
    }
    sgt = new segtree(0, ds.size() - 1);
    for (int i = n; i >= 1; --i) {
        int p = lower_bound(ds.begin(), ds.end(), a[i] + 1) - ds.begin();
        r[i] = sgt->query(0, ds.size() - 1, p, ds.size() - 1) + 1;
        sgt->modify(0, ds.size() - 1, p, r[i]);
    }
    int ans = max(*max_element(l + 1, l + n + 1), *max_element(r + 1, r + n + 1));
    sgt = new segtree(0, ds.size() - 1);
    for (int i = 2; i <= n; ++i) {
        int q = lower_bound(ds.begin(), ds.end(), a[i - 2] + 0) - ds.begin();
        int p = lower_bound(ds.begin(), ds.end(), a[i - 0] + 1) - ds.begin();
        sgt->modify(0, ds.size() - 1, q, l[i - 2]);
        ans = max(ans, r[i] + sgt->query(0, ds.size() - 1, 0, p));
    }
    cout << max(0, n - ans - 1) << endl;
    return 0;
}