#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> E(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }
    int m;
    cin >> m;
    vector<set<int>> S(n);
    vector<array<int, 2>> paths(m);
    vector<int> o(n);
    ll ans = 0;
    for (int j = 0; j < m; ++j) {
        auto& [u, v] = paths[j];
        cin >> u >> v;
        --u, --v;
        if (u == v) {
            ans += o[u]++;
        }
        else {
            S[u].insert(j), S[v].insert(j);
        }
    }
    vector<int> tin(n), cnt(n);
    int timer = 0;
    auto cmp = [&](int u, int v) { return tin[u] < tin[v]; };
    auto dfs = [&](auto& self, int u, int p) -> void {
        tin[u] = timer++;
        for (auto& v : E[u]) {
            if (v == p) swap(E[u].back(), v);
            if (v == p) continue;
            self(self, v, u);
            cnt[v] = (int)size(S[v]);
            if (size(S[v]) > size(S[u])) swap(S[v], S[u]);
            S[u].merge(S[v]);
        }
        if (p != -1) E[u].pop_back();
        ll tot = size(S[u]);
        ans += size(S[u]) * o[u];
        map<array<int, 2>, int> pcnt;
        for (auto v : E[u]) {
            for (auto j : S[v]) {
                S[u].erase(j);
                bool endpoint = false;
                for (int t : {0, 1}) {
                    int& w = paths[j][t];
                    if (w == u) {
                        endpoint = true;
                        continue;
                    }
                    auto iter = prev(upper_bound(begin(E[u]), end(E[u]), w, cmp));
                    w = *iter;
                }
                if (not cmp(paths[j][0], paths[j][1])) swap(paths[j][0], paths[j][1]);
                if (not endpoint) ++pcnt[paths[j]];
            }
        }
        for (auto v : E[u]) {
            for (auto j : S[v]) {
                ll a = cnt[paths[j][0]] + cnt[paths[j][1]] - pcnt[paths[j]];
                ans += tot - a;
                for (auto w : paths[j]) {
                    if (w != u) --cnt[w];
                }
                assert(paths[j][1] != u);
                if (paths[j][0] != u) --pcnt[paths[j]];
                --tot;
            }
        }
    };
    dfs(dfs, 0, -1);
    cout << ans << endl;
    exit(0);
}