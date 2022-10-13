#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <map>

using namespace std;

struct seg_tree {
    vector<int> seg;
    vector<int> lazy;
    int sz;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
        lazy.resize(2 * sz);
    }
    void push(int x, int lx, int rx, int v) {
        seg[x] += v;
        if (rx - lx != 1) {
            lazy[2 * x + 1] += v;
            lazy[2 * x + 2] += v;
        }
    }
    void prop(int x, int lx, int rx) {
        push(x, lx, rx, lazy[x]);
        lazy[x] = 0;
    }
    void upd(int l, int r, int v, int x, int lx, int rx) {
        prop(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            push(x, lx, rx, v);
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m);
        upd(l, r, v, 2 * x + 2, m, rx);
        seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void upd(int l, int r, int v) { upd(l, r, v, 0, 0, sz); }
    int query(int l, int r, int x, int lx, int rx) {
        prop(x, lx, rx);
        if (lx >= r || rx <= l) return 1000000;
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r) { return query(l, r, 0, 0, sz); }
    void print(int x, int lx, int rx) {
        prop(x, lx, rx);
        if (rx - lx == 1) {
            cout << seg[x] << " ";
            return;
        }
        int m = (lx + rx) / 2;
        print(2 * x + 1, lx, m);
        print(2 * x + 2, m, rx);
    }
    void print() { 
        print(0, 0, sz);
        cout << "\n";
    }

};

struct sum_tree {
    vector<int> seg;
    int sz;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
    }
    void upd(int i, int x, int lx, int rx) {
        if (rx - lx == 1) 
            seg[x] = 1;
        else {
            int m = (lx + rx) / 2;
            if (i < m) upd(i, 2 * x + 1, lx, m);
            else upd(i, 2 * x + 2, m, rx);
            seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
        }
    }
    void upd(int i) { upd(i, 0, 0, sz); }
    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m)
            + query(l, r, 2 * x + 2, m, rx);
    }
    int query(int l, int r) { return query(l, r, 0, 0, sz); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        vector<pair<int, int>> ord(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ord[i] = {a[i], i};
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        int l = 0, r = 0;
        seg_tree curr;
        curr.init(n + 1);
        for (int i = 0; i < a.size(); i++) {
            curr.upd(i + 1, n + 1, 1);
        }
        sort(ord.begin(), ord.end());
        long long ans = 0LL;
        sum_tree invCount;
        invCount.init(n);
        for (int i = 0; i < m; i++) {
            while (r < n && ord[r].first <= b[i]) {
                curr.upd(ord[r].second + 1, n + 1, -1);
                ++r;
            }
            while (l < n && ord[l].first < b[i]) {
                curr.upd(0, ord[l].second + 1, 1);
                ++l;
            }
            ans += curr.query(0, n + 1);
            //curr.print();
        }
        for (int i = 0; i < n; i++) {
            ans += invCount.query(ord[i].second, n);
            invCount.upd(ord[i].second);
        }
        cout << ans << "\n";
    }
}