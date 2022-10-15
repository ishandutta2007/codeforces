#include <bits/stdc++.h>
using namespace std;
vector<int> tarjan(const vector<vector<int>>& E) {
    int n = (int)size(E), timer = 0, ct = 0;
    enum State { unvisited, active, visited };
    vector<State> state(n, unvisited);
    vector<int> low(n, -1), num(n, -1), scc(n, -1);
    stack<int> stk;
    auto dfs = [&](auto& self, int u) -> void {
        low[u] = num[u] = timer++, state[u] = active;
        stk.push(u);
        for (auto v : E[u]) {
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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> E(n);
        for (int j = 0; j < m; ++j) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            E[u].push_back(v);
        }
        auto scc = tarjan(E);
        bool good = false;
        for (int u = 0; u + 1 < n; ++u) {
            if (scc[u] != scc[u + 1]) {
                good = true;
                break;
            }
        }
        if (not good) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
            int j = 0;
            for (int u = 0; u < n; ++u) {
                j += scc[u] == 0;
            }
            cout << j << ' ' << n - j << '\n';
            for (int u = 0; u < n; ++u) {
                if (scc[u] == 0) {
                    cout << u + 1 << ' ';
                }
            }
            cout << '\n';
            for (int u = 0; u < n; ++u) {
                if (scc[u] > 0) {
                    cout << u + 1 << ' ';
                }
            }
            cout << '\n';
        }
    }
    exit(0);
}