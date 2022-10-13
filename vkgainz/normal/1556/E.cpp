#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct seg_tree {
    vector<long long> seg;
    vector<long long> mx;
    int sz;
    void init(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        seg.resize(2 * sz);
        mx.resize(2 * sz);
    }
    void upd(int i, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = v;
            mx[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) upd(i, v, 2 * x + 1, lx, m);
        else upd(i, v, 2 * x + 2, m, rx);
        seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
    }
    void upd(int i, long long v) { upd(i, v, 0, 0, sz); }
    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 1e18;
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
    long long query(int l, int r) { return query(l, r, 0, 0, sz); }
    long long get_max(int l, int r, int x, int lx, int rx) {
        if (rx >= r || lx <= l) return -1e18;
        if (lx >= l && rx <= r) return mx[x];
        int m = (lx + rx) / 2;
        return max(get_max(l, r, 2 * x + 1, lx, m), get_max(l, r, 2 * x + 2, m, rx));
    }
    long long get_max(int l, int r) { return get_max(l, r, 0, 0, sz); }
} tree;

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n);
    vector<int> d(n);
    vector<long long> p(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        d[i] -= b[i];
    }
    tree.init(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + d[i - 1];
        tree.upd(i, p[i]);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        if (p[r] - p[l - 1] != 0) {
            cout << -1 << "\n";
        }
        else {
            long long mx = tree.get_max(l, r + 1) - p[l - 1];
            if (mx > 0) cout << -1 << "\n";
            else {
                long long mn = tree.query(l, r + 1) - p[l - 1];
                cout << -mn << "\n";
            }
        }
    }

}