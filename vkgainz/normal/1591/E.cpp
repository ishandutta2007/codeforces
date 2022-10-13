#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
#include <unordered_set>
using namespace std;

struct seg_tree {
    vector<int> seg;
    vector<int> lazy;
    int sz;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz, 0);
        lazy.resize(2 * sz, 0);
   }
    void upd(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) upd(i, v, 2 * x + 1, lx, m);
        else upd(i, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    void ch(int i, int v) {
        upd(i, v, 0, 0, sz); 
    }
    int query(int k, int x, int lx, int rx) {
        if (seg[x] < k) {
            return -1;
        }
        if (rx - lx == 1) {
            return lx;
        }
        int m = (lx + rx) / 2;
        if (seg[2 * x + 1] >= k) {
            return query(k, 2 * x + 1, lx, m);
        } else {
            return query(k - seg[2 * x + 1], 2 * x + 2, m, rx);
        }
    }
    int query(int k) { return query(k, 0, 0, sz); }
    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) {
            return seg[x];
        }
        int m = (lx + rx) / 2;
        return get(l, r, 2 * x + 1, lx, m)
            + get(l, r, 2 * x + 2, m, rx);
    }
    int get(int l, int r) { return get(l, r, 0, 0, sz); }
};

struct query {
    int l, k, idx;
};

vector<vector<int>> adj;
vector<int> f;
vector<int> a;
vector<vector<query>> process;
vector<int> ans;
vector<unordered_set<int>> sto;
seg_tree in;

void dfs(int curr, int par) {
    in.ch(f[a[curr]], -1);
    sto[f[a[curr]]].erase(a[curr]);
    ++f[a[curr]];
    in.ch(f[a[curr]], 1);
    sto[f[a[curr]]].insert(a[curr]);
    for (query &toans : process[curr]) {
        int l = toans.l;
        int k = toans.k;
        k += in.get(0, l);
        int larger = in.query(k);
        if (larger == -1) {
            ans[toans.idx] = -1;
        } else {
            ans[toans.idx] = *sto[larger].begin() + 1;
        }
    }
    for (int next : adj[curr]) {
        dfs(next, curr);
    }
    //remove
    in.ch(f[a[curr]], -1);
    sto[f[a[curr]]].erase(a[curr]);
    --f[a[curr]];
    in.ch(f[a[curr]], 1);
    sto[f[a[curr]]].insert(a[curr]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        a.resize(n);
        f.resize(n, 0);
        adj.clear();
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            int p; cin >> p;
            adj[p - 1].push_back(i + 1);
        }
        in.init(n + 1);
        sto.clear();
        sto.resize(n + 1);
        for (int i = 0; i < n; i++) {
            in.ch(0, 1);
            sto[0].insert(a[i]);
        }
        process.clear();
        process.resize(n);
        for (int i = 0; i < q; i++) {
            int v, l, k; cin >> v >> l >> k;
            --v;
            process[v].push_back({l, k, i});
        }
        ans.clear();
        ans.resize(q);
        dfs(0, -1);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}