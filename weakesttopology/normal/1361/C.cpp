#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

struct EulerianTour {
    int n, m = 0, odd = 0;
    vector<vector<pair<int, int>>> E;
    vector<int> deg;
    EulerianTour(int n) : n(n), E(n), deg(n) {}
    void add_edge(int u, int v) {
        int V[2] = {u, v};
        for (auto t : {0, 1}) {
            int v = V[t];
            E[v].emplace_back(V[t ^ 1], m << 1 | t);
            deg[v] += 1;
            odd += (deg[v] % 2 ? +1 : -1);
        }
        ++m;
    }
    // returns eulerian tour by vertices and edges (reversed if first bit is 1)
    pair<vector<int>, vector<int>> find(int src) const {
        assert(odd == 0);
        auto d = deg;
        vector<bool> dead(m, false);
        vector<int> ptr(n, 0), p, e;
        stack<pair<int, int>> stk;
        stk.emplace(src, -1);
        while (not empty(stk)) {
            auto [u, i] = stk.top();
            if (d[u] == 0) {
                stk.pop();
                p.push_back(u);
                if (i != -1) e.push_back(i);
            }
            else {
                for (int& l = ptr[u]; l < deg[u]; ++l) {
                    auto [v, j] = E[u][l];
                    if (not dead[j >> 1]) {
                        stk.emplace(v, j);
                        --d[u], --d[v], dead[j >> 1] = true;
                        break;
                    }
                }
            }
        }
        return {p, e};
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<array<int, 2>> edges(n);
    for (auto& [u, v] : edges) cin >> u >> v;

    int opt = 0;
    vector<int> p(2 * n);
    iota(all(p), 0);

    for (int k = 1; k <= 20; ++k) {
        int N = 1 << k, fullmask = N - 1;
        EulerianTour euler(N);
        for (auto [u, v] : edges) {
            euler.add_edge(u & fullmask, v & fullmask);
        }
        if (euler.odd > 0) break;
        auto e = euler.find(edges[0][0] & fullmask).second;
        if ((int)size(e) == n) {
            p.clear();
            for (auto j : e) p.insert(end(p), {j ^ 1, j});
            opt = k;
        }
        else break;
    }

    cout << opt << endl;
    for (auto x : p) cout << x + 1 << " ";
    cout << endl;

    exit(0);
}