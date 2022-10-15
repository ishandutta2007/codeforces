#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll x;
    cin >> n >> m >> x;

    vector<ll> a(n);
    for (auto& y : a) cin >> y;

    if (accumulate(all(a), 0LL) < (n - 1) * x) {
        cout << "NO" << endl;
        exit(0);
    }

    vector<vector<pair<int, int>>> E(n);
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].emplace_back(v, j);
        E[v].emplace_back(u, j);
    }

    vector<bool> tree(m, false), vis(n, false);
    vector<int> deg(n, 0);

    auto dfs = [&](auto&& self, int u) -> void {
        vis[u] = true;
        for (auto [v, j] : E[u]) {
            if (not vis[v]) {
                deg[u] += 1;
                deg[v] += 1;
                tree[j] = true;
                self(self, v);
            }
        }
    };
    dfs(dfs, 0);

    stack<int> stk;
    for (int u = 0; u < n; ++u) {
        if (deg[u] == 1) stk.push(u);
    }

    vector<bool> dead(n, false);
    vector<int> edges, edges_back;

    while (size(edges) + size(edges_back) < n - 1) {
        int u = stk.top();
        stk.pop();
        while (true) {
            auto [v, j] = E[u].back();
            if (dead[v] || not tree[j]) E[u].pop_back();
            else break;
        }
        auto [v, j] = E[u].back();
        if (a[u] + a[v] >= x) {
            edges.push_back(j);
            a[v] += a[u] - x;
        }
        else edges_back.push_back(j);
        if (--deg[v] == 1) stk.push(v);
        dead[u] = true;
    }

    reverse(all(edges_back));
    edges.insert(end(edges), all(edges_back));

    cout << "YES" << endl;
    for (auto j : edges) {
        cout << j + 1 << endl;
    }

    exit(0);
}