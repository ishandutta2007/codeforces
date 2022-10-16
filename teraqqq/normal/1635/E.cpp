#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

struct Edge {
    int t, u, v;
};

const int N = 2e5+7;

vi g[N];
int col[N];

bool dfs(int v) {
    for (int to : g[v]) {
        if (col[to]) {
            if (col[to] == col[v]) return false;
        } else {
            col[to] = 3 ^ col[v];
            if (!dfs(to)) return false;
        }
    }

    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& [t, u, v] : edges) {
        cin >> t >> u >> v; --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = n; i--; ){
        if (col[i]) continue;

        col[i] = 1;
        if (!dfs(i)) {
            cout << "NO" << endl;
            return;
        }
    }

    vector<vi> gc(n);
    vector<int> x(n), deg(n);
    int px = 1;

    for (auto [t, u, v] : edges) {
        assert(col[u] != col[v] && col[u] && col[v]);

        if (col[u] == 2) swap(u, v);

        if (t == 1) gc[u].push_back(v), deg[v]++;
        if (t == 2) gc[v].push_back(u), deg[u]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) if (!deg[i]) q.push(i);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        x[v] = px++;

        for (int to : gc[v]) {
            deg[to]--;
            if (!deg[to]) q.push(to);
        }
    }

    if (px <= n) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            cout << (col[i] == 1 ? "L" : "R") << ' ' << x[i] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    // cin >> t;
    while (t--) solve();
}