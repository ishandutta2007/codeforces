#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if(k % 2 == 1) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << -1 << " ";
            }
            cout << '\n';
        }
        return 0;
    }
    vector<vector<pair<int,int>>> g(n * m);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j + 1 < m; ++j) {
            // (i, j) -> (i, j + 1)
            int x;
            cin >> x;
            int u = i * m + j, v = i * m + j + 1;
            g[u].push_back({v, x});
            g[v].push_back({u, x});
        }
    }
    for(int i = 0; i + 1 < n; ++i) {
        for(int j = 0; j < m; ++j) {
            // (i, j) -> (i + 1, j)
            int x;
            cin >> x;
            int u = i * m + j, v = (i + 1) * m + j;
            g[u].push_back({v, x});
            g[v].push_back({u, x});
        }
    }
    k /= 2;
    vector<vector<int>> dp(n * m, vector<int>(k + 1, 1e9));
    for(int u = 0; u < n * m; ++u) dp[u][0] = 0;
    for(int i = 1; i <= k; ++i) {
        for(int u = 0; u < n * m; ++u) {
            for(auto [v, w] : g[u]) {
                dp[u][i] = min(dp[u][i], w + dp[v][i - 1]);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << dp[i * m + j][k] * 2 << " ";
        }
        cout << '\n';
    }
}