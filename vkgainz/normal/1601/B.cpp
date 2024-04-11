#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

struct seg_tree {
    vector<int> seg;
    vector<int> idx;
    vector<int> b;
    int sz;
    void init(int n, vector<int> &x) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz, 1000000);
        idx.resize(2 * sz, -1);
        for (int i = 0; i < x.size(); i++) {
            b.push_back(x[i]);
        }
        while (b.size() < 2 * sz) {
            b.push_back(1000000);
        }
    }
    void upd(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] = v;
            idx[x] = i;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) upd(i, v, 2 * x + 1, lx, m);
        else upd(i, v, 2 * x + 2, m, rx);
        seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
        if (seg[2 * x + 1] < seg[2 * x + 2]) {
            idx[x] = idx[2 * x + 1];
        } else {
            idx[x] = idx[2 * x + 2];
        }
    }
    void upd(int i, int v) { upd(i, v, 0, 0, sz); }
    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 2 * sz - 1;
        if (lx >= l && rx <= r) return idx[x];
        int m = (lx + rx) / 2;
        int c = query(l, r, 2 * x + 1, lx, m);
        int d = query(l, r, 2 * x + 2, m, rx);
        if (b[c] < b[d])
            return c;
        else
            return d;
    }
    int restore(int l, int r) {
        return query(l, r, 0, 0, sz); 
    }
};

int main() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> d(n + 1), u(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        d[i] = i + b[i] - a[i + b[i]];
    }
    seg_tree in;
    in.init(n + 1, d);
    for (int i = 1; i <= n; i++) {
        in.upd(i, d[i]);
    }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) {
            adj[i].push_back({0, 0});
        } else {
            //use a segtree or smth to get the edge
            int best = in.restore(i - a[i], i + 1);
            adj[i].push_back({best + b[best], best});
        }
    }
    vector<int> par(n + 1, -1);
    vector<int> dist(n + 1, 1000000);
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        for (auto next : adj[curr]) {
            if (dist[curr] + 1 < dist[next.first]) {
                par[next.second] = curr;
                u[next.first] = next.second;
                dist[next.first] = dist[curr] + 1;
                q.push(next.first);
            }
        }
    }
    if (dist[0] == 1000000 || par[0] == -1) {
        cout << -1 << "\n";
        return 0;
    }
    vector<int> ret;
    ret.push_back(0);
    int curr = 0;
    while (par[curr] != n) {
        ret.push_back(u[par[curr]]);
        curr = u[par[curr]];
    }
    reverse(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for (int x : ret) {
        cout << x << " ";
    }
    cout << "\n";
}