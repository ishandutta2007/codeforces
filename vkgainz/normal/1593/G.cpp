#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

struct Node {
    int pref, suf, len;
};

Node merge(Node x, Node y) {
    if (x.len == 0) return y;
    if (y.len == 0) return x;
    if (x.suf == y.pref) {
        if (x.len == y.len) { return {0, 0, 0}; }
        else {
            if (x.len > y.len) {
                if (y.len % 2 == 0) {
                    return {x.pref, x.suf, x.len - y.len};
                }
                else {
                    return {x.pref, 3 - x.suf, x.len - y.len};
                }
            }
            else {
                if (x.len % 2 == 0) {
                    return {y.pref, y.suf, y.len - x.len};
                }
                else {
                    return {3 - y.pref, y.suf, y.len - x.len};
                }
            }
        }
    } else {
        return {x.pref, y.suf, x.len + y.len};
    }
}

struct seg_tree {
    vector<Node> seg;
    int sz = 1;
    void build(vector<int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                seg[x] = {v[lx], v[lx], 1};
            }
            else { seg[x] = {0, 0, 0}; }
            return;
        }
        int m = (lx + rx) / 2;
        build(v, 2 * x + 1, lx, m);
        build(v, 2 * x + 2, m, rx);
        seg[x] = merge(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void init(int N, vector<int> &v) {
        while (sz < N) sz *= 2;
        seg.resize(2 * sz);
        build(v, 0, 0, sz);
    }
    Node query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return {0, 0, 0};
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        Node a = query(l, r, 2 * x + 1, lx, m);
        Node b = query(l, r, 2 * x + 2, m, rx);
        return merge(a, b);
    }
    int query(int l, int r) { return query(l, r, 0, 0, sz).len / 2; }
};

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        seg_tree curr;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == ')') 
                a[i] = 1;
            else
                a[i] = 2;
        }
        curr.init(n, a);
        int q; cin >> q;
        while (q--) {
            int l, r; cin >> l >> r;
            --l;
            cout << curr.query(l, r) << "\n";
        }
    }
}