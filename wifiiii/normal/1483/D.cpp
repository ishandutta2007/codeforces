#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 606;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dis(n, vector<ll>(n, 1e18));
    vector<vector<int>> g(n, vector<int>(n)), ok(n, vector<int>(n));
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        dis[u][v] = min(dis[u][v], (ll)w);
        dis[v][u] = w;
        g[u][v] = g[v][u] = w;
    }
    for(int i = 0; i < n; ++i) dis[i][i] = 0;
    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    vector<vector<int>> lim(n, vector<int>(n, -1));
    for(int i = 0; i < q; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        --u, --v;
        lim[u][v] = max(lim[u][v], l);
        lim[v][u] = max(lim[v][u], l);
    }
    for(int i = 0; i < n; ++i) {
        vector<ll> max_dis(n, -1e18);
        for(int j = 0; j < n; ++j) {
            if(i == j || lim[i][j] == -1) continue;
            for(int k = 0; k < n; ++k) {
                max_dis[k] = max(max_dis[k], lim[i][j] - dis[j][k]);
            }
        }
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                if(j != k && g[j][k] && dis[i][j] + g[j][k] <= max_dis[k]) {
                    ok[j][k] = ok[k][j] = 1;
                }
            }
        }
    }
    int ans = 0;
    for(int j = 0; j < n; ++j) {
        for(int k = j + 1; k < n; ++k) {
            ans += ok[j][k];
        }
    }
    cout << ans << '\n';
}