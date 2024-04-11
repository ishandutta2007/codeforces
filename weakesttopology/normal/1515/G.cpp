#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// returns a vector scc where scc[u] == scc[v] iff
// u and v lie in the same strongly connected component
//
// these ids are already sorted topologically in reverse order
// i.e., scc's with 0 out-degree first
// it is guarenteed that 0 <= scc[u] < n for all u

vector<int> tarjan(const auto& E) {
    int n = (int)size(E), timer = 0, ct = 0;

    enum State { unvisited, active, visited };
    vector<State> state(n, unvisited);

    vector<int> low(n, -1), num(n, -1), scc(n, -1);
    stack<int> stk;

    auto dfs = [&](auto& self, int u) -> void {
        low[u] = num[u] = timer++, state[u] = active;
        stk.push(u);
        for (auto [v, c] : E[u]) {
            if (state[v] == unvisited) self(self, v);
            if (state[v] == active) low[u] = min(low[u], low[v]);
        }
        if (low[u] == num[u]) {
            do {
                int v = stk.top(); stk.pop();
                scc[v] = ct, state[v] = visited;
            } while (not empty(stk) && num[stk.top()] >= num[u]);
            ++ct;
        }
    };

    for (int u = 0; u < n; ++u) if (num[u] == -1) dfs(dfs, u);

    return scc;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> E(n);

    for (int j = 0; j < m; ++j) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        E[u].emplace_back(v, c);
    }

    auto scc = tarjan(E);

    vector<bool> vis(n, false);
    vector<ll> g(n, 0), h(n, 0);

    auto dfs = [&](auto&& self, int u) -> void {
        vis[u] = true;
        for (auto [v, c] : E[u]) if (scc[u] == scc[v]) {
            if (not vis[v]) {
                h[v] = h[u] + c;
                self(self, v);
            }
            else {
                g[scc[u]] = gcd(g[scc[u]], h[u] - h[v] + c);
            }
        }
    };
    for (int u = 0; u < n; ++u) {
        if (not vis[u]) dfs(dfs, u);
    }

    int q;
    cin >> q;

    for (int z = 0; z < q; ++z) {
        int v, s, t;
        cin >> v >> s >> t;
        --v;
        string res = s % gcd(g[scc[v]], t) ? "NO" : "YES";
        cout << res << endl;
    }

    exit(0);
}