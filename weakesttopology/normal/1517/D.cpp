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

    int n, m, k;
    cin >> n >> m >> k;

    if (k % 2) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << -1 << "\n "[j + 1 < m];
            }
        }
        exit(0);
    }
    k /= 2;

    auto Id = [&](int x, int y){ return x * m + y; };

    int N = n * m;
    vector<vector<pair<int, int>>> E(N);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int u = Id(i, j), v = Id(i, j + 1);
            int w;
            cin >> w;
            E[u].emplace_back(v, w);
            E[v].emplace_back(u, w);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int u = Id(i, j), v = Id(i + 1, j);
            int w;
            cin >> w;
            E[u].emplace_back(v, w);
            E[v].emplace_back(u, w);
        }
    }

    vector<ll> dp(N, 0), dpnxt(N, LINF);

    for (int j = 0; j < k; ++j) {
        for (int u = 0; u < N; ++u) {
            for (auto [v, w] : E[u]) {
                dpnxt[u] = min(dpnxt[u], 2 * w + dp[v]);
            }
        }
        fill(all(dp), LINF), swap(dp, dpnxt);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dp[Id(i, j)] << "\n "[j + 1 < m];
        }
    }

    exit(0);
}