#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

struct DSU {
    vector<int> p, sz;
    explicit DSU(int n) {
        p.resize(n + 1);
        iota(all(p), 0);
        sz.resize(n + 1, 1);
    }
    int find(int v) {
        return p[v] == v ? v : p[v] = find(p[v]);
    }
    bool merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            return false;
        }
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

const int N = 3e5 + 10;
vector<int> g[N], cpath, path;
int used[N], timer;

void find_path(int from, int to) {
    used[from] = timer;
    cpath.pb(from);
    if (from == to) {
        path = cpath;
    }
    for (auto u : g[from]) {
        if (used[u] < timer) {
            find_path(u, to);
        }
    }
    cpath.pop_back();
}

map<pair<int, int>, int> value;
void add(int a, int b) {
    value[{min(a, b), max(a, b)}] ^= 1;
}

int get(int a, int b) {
    return value[{min(a, b), max(a, b)}];
}

int up[N], cnt_paths;

void dfs(int v, int parent = 0) {
    int cc = 0;
    for (auto u : g[v]) {
        if (u != parent) {
            dfs(u, v);
            if (get(u, v)) {
               if (!up[u]) {
                   cnt_paths++;
               }
               cc++;
            }
        }
    }
    cnt_paths -= cc / 2;
    up[v] = (cc & 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU kek(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (kek.merge(u, v)) {
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    int q;
    cin >> q;
    vector<vector<int>> answer;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cpath = {};
        timer++;
        find_path(a, b);
        answer.pb(path);
        for (int j = 0; j + 1 < SZ(path); j++) {
            add(path[j], path[j + 1]);
        }
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        for (int j : g[i]) {
            if (get(i, j) == 1) {
                ok = false;
            }
        }
    }
    if (ok) {
        cout << "YES\n";
        for (auto path : answer) {
            cout << SZ(path) << '\n';
            for (auto it : path) {
                cout << it << ' ';
            }
            cout << '\n';
        }
    } else {
        dfs(1);
        cout << "NO\n" << cnt_paths << '\n';
    }
}