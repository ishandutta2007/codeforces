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

    int n;
    cin >> n;

    map<array<ll, 2>, vector<pair<array<ll, 2>, int>>> E;

    for (int i = 0; i < n; ++i) {
        array<ll, 4> a;
        for (auto& x : a) cin >> x;
        vector<array<ll, 2>> L;
        for (auto t : {0, 2}) {
            auto b = a;
            b[t] += b[t + 1];
            ll x = b[0] * b[3], y = b[1] * b[2];
            ll g = gcd(x, y);
            x /= g, y /= g;
            L.push_back({x, y});
        }
        for (auto t : {0, 1}) E[L[t]].emplace_back(L[t ^ 1], i);
    }

    enum State { unvisited = 0, active, visited };
    map<array<ll, 2>, State> st;

    vector<pair<int, int>> edges;
    auto dfs = [&](auto&& self, auto u) -> int {
        int i = -1;
        st[u] = active;
        for (auto [v, j] : E[u]) {
            if (st[v] == unvisited) {
                int k = self(self, v);
                if (k != -1) {
                    edges.emplace_back(j, k);
                    continue;
                }
            }
            if (st[v] == visited) {
                if (i != -1) {
                    edges.emplace_back(j, i);
                    i = -1;
                }
                else i = j;
            }
        }
        st[u] = visited;
        return i;
    };

    for (auto& [u, V] : E) {
        if (st[u] == unvisited) dfs(dfs, u);
    }

    cout << size(edges) << endl;
    for (auto [i, j] : edges) {
        cout << i + 1 << " " << j + 1 << endl;
    }

    exit(0);
}