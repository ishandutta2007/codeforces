#include <bits/stdc++.h>
using namespace std;

set<int> component;
vector<vector<int>> sto;
vector<int> par;

int find(int x) {
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

vector<int> to_erase;

void merge(int x, int y) {
    int u = find(x), v = find(y);
    if(sto[u].size() < sto[v].size())
        swap(u, v);
    sto[u].insert(sto[u].end(), sto[v].begin(), sto[v].end());
    sto[v].clear();
    to_erase.push_back(v);
    par[v] = u;
}

vector<vector<int>> tree;
vector<int> p, q;
vector<set<int>> put;
vector<bool> leaf;
vector<bool> vis;
int st;

void dfs(int curr, int par) {
    if(leaf[curr]) return;

    put[par].erase(curr);
    if(put[par].empty()) {
        put[curr].insert(par);
    }
    for(int next : tree[curr]) {
        if(next == par) continue;
        put[curr].insert(next);
    }
    for(int next : tree[curr]) {
        if(next == par) continue;
        dfs(next, curr);
    }
}

void init(int curr, int par) {
    vis[curr] = true;
    for(int next : tree[curr]) {
        if(next == par) continue;
        leaf[curr] = false;
        init(next, curr);
    }
}

void reset(int n) {
    tree.clear(), tree.resize(n), p.clear(), p.resize(n), q.clear(), q.resize(n), st = 1, put.clear(), put.resize(n), component.clear(), sto.clear(), sto.resize(n), par.clear(), par.resize(n), iota(par.begin(), par.end(), 0), leaf.clear(), leaf.resize(n, 1), vis.clear(), vis.resize(n);
}

void solve() {
    int n, m; cin >> n >> m;
    reset(n);
    vector<set<int>> in(n);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        in[x].insert(y);
        in[y].insert(x);
    }
    for(int i = 0; i < n; i++)
        sto[i].push_back(i);

    for(int i = 0; i < n; i++) {
        component.insert(i);
        to_erase.clear();
        for(int x : component) {
            if(x == i) continue;
            for(int y : sto[x]) {
                if(in[i].count(y)) continue;
                merge(i, y);
                tree[i].push_back(y);
                tree[y].push_back(i);
                break;
            }
        }
        for(int x : to_erase)
            component.erase(x);
    }
    st = 1;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        if((int) tree[i].size() == 0) {
            p[i] = st, q[i] = st;
            ++st;
            continue;
        }
        init(i, -1);
        for(int next : tree[i]) {
            put[i].insert(next);
        }
        for(int next : tree[i]) {
            dfs(next, i);
        }
    }
    for(int i = 0; i < n; i++) {
        if(put[i].size() == 0) continue;
        int tmp = st;
        for(int j : put[i]) {
            p[j] = st, q[j] = st + 1;
            ++st;
        }
        p[i] = st++, q[i] = tmp;
    }
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}