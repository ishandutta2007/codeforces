#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> E(n);
        vector<int> p(n);
        for (int u = 1; u < n; ++u) {
            int& v = p[u];
            cin >> v;
            --v;
            E[v].push_back(u);
        }
        vector<int> h(n), best(n, -1);
        for (int u = n - 1; u > 0; --u) {
            int v = p[u];
            if (chmax(h[v], h[u] + 1)) best[v] = u;
        }
        vector<int> P;
        int bad = max(0, k - (h[0] + 1));
        k -= bad;
        auto dfs = [&](auto& self, int u, bool ret) -> void {
            if (ret) {
                if (bad == 0) return;
                --bad;
                P.push_back(u);
                for (auto v : E[u]) {
                    if (bad == 0) break;
                    self(self, v, true);
                    P.push_back(u);
                }
            }
            else {
                if (k == 0) return;
                --k;
                P.push_back(u);
                for (auto v : E[u]) {
                    if (bad == 0) break;
                    if (v == best[u]) continue;
                    self(self, v, true);
                    P.push_back(u);
                }
                if (k > 0) self(self, best[u], false);
            }
        };
        dfs(dfs, 0, false);
        cout << size(P) - 1 << endl;
        for (auto u : P) {
            cout << u + 1 << " ";
        }
        cout << endl;
    }
    exit(0);
}