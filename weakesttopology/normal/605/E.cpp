#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    constexpr int nmax = 1000;
    double p[nmax][nmax];

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            int x;
            cin >> x;
            p[u][v] = x / 100.0;
        }
    }

    vector<double> E(n, 1e300), P(n, 1), Enxt(n, 0);

    priority_queue<pair<double, int>> pq;

    const int snk = n - 1, src = 0;
    pq.emplace(E[snk] = 0, snk);

    vector<bool> vis(n, false);

    while (not empty(pq)) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (int v = 0; v < n; ++v) if (not vis[v] && p[v][u] != 0) {
            if (chmin(E[v], (Enxt[v] + p[v][u] * P[v] * E[u] + 1) / (1 - P[v] + P[v] * p[v][u]))) {
                Enxt[v] += P[v] * p[v][u] * E[u], P[v] *= 1 - p[v][u];
                pq.emplace(-E[v], v);
            }
        }
    }

    double res = E[src];
    cout << setprecision(10) << fixed;
    cout << res << endl;

    exit(0);
}