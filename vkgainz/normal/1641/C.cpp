#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
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
    void push(int x, int lx, int rx) {
        seg[x] = rx - lx;
        if (rx - lx != 1) {
            lazy[2 * x + 1] = 1;
            lazy[2 * x + 2] = 1;
        }
    }
    void prop(int x, int lx, int rx) {
        if (lazy[x] == 0) return;
        push(x, lx, rx);
        lazy[x] = 0;
    }
    void upd(int l, int r, int x, int lx, int rx) {
        prop(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            push(x, lx, rx);
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, 2 * x + 1, lx, m);
        upd(l, r, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    void upd(int l, int r) { upd(l, r, 0, 0, sz); }
    //might have to change into descent on tree?
    int query(int l, int r, int x, int lx, int rx) {
        prop(x, lx, rx);
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
    }
    int query(int l, int r) { return query(l, r, 0, 0, sz); }
};

struct mn_tree {
    vector<int> seg;
    int sz;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz, 1e9);
    }
    void upd(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = min(seg[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) upd(i, v, 2 * x + 1, lx, m);
        else upd(i, v, 2 * x + 2, m, rx);
        seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void upd(int i, int v) { upd(i, v, 0, 0, sz); }
    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 1e9;
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return min(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r) { return query(l, r, 0, 0, sz); }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    seg_tree upd;
    mn_tree in;
    upd.init(n);
    in.init(n);
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;
            --l;
            if (x == 0) {
                upd.upd(l, r);
            } else {
                in.upd(l, r - 1);
            }
        } else {
            int j; cin >> j;
            --j;
            if (upd.query(j, j + 1) == 1) {
                cout << "NO" << "\n";
                continue;
            }
            int le;
            //get le and ri using bin search and check
            int lo = 0, hi = j - 1;
            for (int k = 0; k < 20 && lo < hi; k++) {
                int mid = (lo + hi) / 2;
                int num = upd.query(mid, j);
                if (num == j - mid) {
                    hi = mid; 
                } else {
                    lo = mid + 1;
                }
            }
            le = lo;
            if (j == 0 || upd.query(j - 1, j) == 0) {
                le = j;
            }
            int bst = in.query(le, j + 1);
            int num = upd.query(j + 1, bst + 1);
            if (num == bst - j) {
                cout << "YES" << "\n";
            } else {
                cout << "N/A" << "\n";
            }
        }
    }

}