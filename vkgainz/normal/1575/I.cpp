#include <iostream>
#include <vector>

using namespace std;


struct seg_tree {
    vector<long long> seg;
    vector<long long> lazy;
    int sz;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.resize(2 * sz);
        lazy.resize(2 * sz);
    }
    void push(int x, int lx, int rx, long long v) {
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
    long long get(int i, int x, int lx, int rx) {
        prop(x, lx, rx);
        if (rx - lx == 1) {
            return seg[x];
        } else {
            int m = (lx + rx) / 2;
            if (i < m) {
                return get(i, 2 * x + 1, lx, m); 
            } else {
                return get(i, 2 * x + 2, m, rx);
            }
        }
    }
    long long get(int i) { return get(i, 0, 0, sz); }
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

vector<vector<int>> adj;
vector<vector<int>> tab;
vector<int> d;
vector<int> st, sz;
int t;
seg_tree sto;

void dfs(int curr, int par) {
    if (par != -1) { tab[curr][0] = par,
        d[curr] = d[par] + 1; }
    st[curr] = t++;
    sz[curr] = 1;
    for (int j = 1; j < 20; j++) {
        tab[curr][j] = tab[ tab[curr][j - 1] ][j - 1];
    }
    for (int next : adj[curr]) {
        if (next != par) {
            dfs(next, curr);
            sz[curr] += sz[next];
        }
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) { swap(u, v); }
    for (int j = 19; j >= 0; j--) {
        if (d[u] - (1 << j) >= d[v]) {
            u = tab[u][j];
        }
    }
    if (u == v) {
        return u;
    } else {
        for (int j = 19; j >= 0; j--) {
            if (tab[u][j] != tab[v][j]) {
                u = tab[u][j], 
                  v = tab[v][j];
            }
        }
        return tab[u][0];
    }
}

int main() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    adj.resize(n);
    d.resize(n);
    st.resize(n);
    sz.resize(n);
    tab.resize(n, vector<int>(20));
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    sto.init(n);
    for (int i = 0; i < n; i++) {
        sto.upd(st[i], st[i] + sz[i], a[i]);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, c; cin >> u >> c;
            --u;
            c = abs(c);
            int ch = c - a[u];
            sto.upd(st[u], st[u] + sz[u], ch);
            a[u] = c;
        } else {
            int u, v; cin >> u >> v;
            --u, --v;
            int l = lca(u, v);
            long long ans = 2 * 1LL * (sto.get(st[u]) + sto.get(st[v]) 
                    - sto.get(st[l]));
            if (l != 0) {
                ans -= 2 * 1LL * sto.get(st[tab[l][0]]);
            }
            ans -= (sto.get(st[u]) + sto.get(st[v]));
            if (u != 0) {
                ans += sto.get(st[tab[u][0]]);
            } 
            if (v != 0) {
                ans += sto.get(st[tab[v][0]]);
            }
            cout << ans << "\n";
        }
    }
}