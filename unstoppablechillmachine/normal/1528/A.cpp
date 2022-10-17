#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<pair<int, int>> vl(n);
    for (int i = 0; i < n; i++) {
      cin >> vl[i].first >> vl[i].second;
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].pb(v);
      g[v].pb(u);
    }
    vector<pair<int, int>> dp(n);
    function<void(int, int)> dfs = [&](int v, int parent) {
      for (auto u : g[v]) {
        if (u != parent) {
          dfs(u, v);
          dp[v].first += max(dp[u].first + abs(vl[v].first - vl[u].first), dp[u].second + abs(vl[v].first - vl[u].second));
          dp[v].second += max(dp[u].first + abs(vl[v].second - vl[u].first), dp[u].second + abs(vl[v].second - vl[u].second));
        }
      }
    };
    dfs(0, -1);
    cout << max(dp[0].first, dp[0].second) << '\n';
  }  
}