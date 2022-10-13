#include <bits/stdc++.h>
using namespace std;
 
#define rsz(x, n) x.clear(), x.resize(n)
#define sz(x) (int) x.size()
 
vector<vector<int>> adj;
vector<vector<pair<long long, long long>>> dp;
vector<long long> b, w;
int m;
 
void merge(vector<pair<long long, long long>> &x, vector<pair<long long, long long>> &y) {
    vector<pair<long long, long long>> ans(sz(x) + sz(y) - 1);
    for(int i = 0; i < sz(x) + sz(y) - 1; i++) {
        ans[i] = {-100000, -100000};
    }
    for(int i = 1; i < sz(x); i++) {
        for(int j = 1; j < sz(y); j++) {
            ans[i + j] = max(ans[i + j], {x[i].first + y[j].first + (y[j].second > 0), x[i].second});
            ans[i + j - 1] = max(ans[i + j - 1], {x[i].first + y[j].first, x[i].second + y[j].second});
        }
    }
    x = ans;
}
 
void dfs(int curr, int par) {
    dp[curr] = {{-1000000, -1000000}, {0, w[curr] - b[curr]}};
    for(int next : adj[curr]) {
        if(next == par) continue;
        dfs(next, curr);
        merge(dp[curr], dp[next]);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t;
    while(t--) {
        int n; cin >> n >> m;
        rsz(adj, n);
        rsz(b, n), rsz(w, n);
        rsz(dp, n);
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> w[i];
        }
        for(int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        cout << dp[0][m].first + (dp[0][m].second > 0) << "\n";
    }
}