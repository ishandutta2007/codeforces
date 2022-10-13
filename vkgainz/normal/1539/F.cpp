#include <bits/stdc++.h>
using namespace std;

struct seg_tree {
    vector<int> lazy, mn, mx;
    int sz;
    void init(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        lazy.assign(2 * sz, 0);
        mn.assign(2 * sz, 0), mx.resize(2 * sz, 0);
    }
        
    void push(int x, int lx, int rx, int v) {
        mx[x] += v, mn[x] += v;
        if(rx - lx != 1) {
            lazy[2 * x + 1] += v;
            lazy[2 * x + 2] += v;
        }
    }
    void prop(int x, int lx, int rx) {
        push(x, lx, rx, lazy[x]);
        lazy[x] = 0;
    }
    void upd(int l, int r, int v, int x, int lx, int rx) { //ADD v to range [l...r)
        prop(x, lx, rx);
        if(lx >= r || rx <= l) return;
        if(lx >= l && rx <= r) {
            push(x, lx, rx, v);
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);
        mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
        //combine
    }
    void upd(int l, int r, int v) { upd(l, r, v, 0, 0, sz); }
    //create a query max and query min function
    int query_max(int l, int r, int x, int lx, int rx) {
        prop(x, lx, rx);
        if(lx >= r || rx <= l) return -1000000000;
        if(lx >= l && rx <= r) return mx[x];
        int m = (lx + rx) / 2;
        return max(query_max(l, r, 2 * x + 1, lx, m), query_max(l, r, 2 * x + 2, m, rx));
    }
    int query_max(int l, int r) { return query_max(l, r, 0, 0, sz); }
    int query_min(int l, int r, int x, int lx, int rx) {
        prop(x, lx, rx);
        if(lx >= r || rx <= l) return 1000000000;
        if(lx >= l && rx <= r) return mn[x];
        int m = (lx + rx) / 2;
        return min(query_min(l, r, 2 * x + 1, lx, m), query_min(l, r, 2 * x + 2, m, rx));
    }
    int query_min(int l, int r) { return query_min(l, r, 0, 0, sz); }
} r, l;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
        
    vector<vector<int>> in(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        in[a[i]].push_back(i + 1);
    }
    
    vector<int> ans(n + 1);
        
    r.init(n + 1);
    for(int i = 1; i <= n; i++) {
        r.upd(i, n + 1, 1);
    }
    for(int i = 0; i <= n; i++) {
        for(int query_idx : in[i]) {
            int mx = r.query_max(query_idx, n + 1);
            int mn = r.query_min(0, query_idx);
            ans[query_idx] = max(ans[query_idx], (mx - mn) / 2);
        }
        for(int upd_idx : in[i]) {
            r.upd(upd_idx, n + 1, -2);
        }
    }
    
    l.init(n + 1);
    for(int i = 1; i <= n; i++) {
        l.upd(i, n + 1, -1);
    }
    for(int i = n; i >= 0; i--) {
        for(int query_idx : in[i]) {
            int mx = l.query_max(0, query_idx);
            int mn = l.query_min(query_idx, n + 1);
            ans[query_idx] = max(ans[query_idx], (mx - mn - 1) / 2);
        }
        for(int upd_idx : in[i]) {
            l.upd(upd_idx, n + 1, 2);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}