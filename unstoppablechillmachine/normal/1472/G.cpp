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
 
const int N = 2e5 + 10;
vector<int> g[N], g2[N], order;
bool used[N];

void dfs(int v) {
  used[v] = true;
  for (auto u : g2[v])  {
    if (!used[u]) {
      dfs(u);
    }
  }
  order.pb(v);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      g[i] = {};
      g2[i] = {};
      used[i] = false;
    }
    order = {};
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
    }
    queue<int> q;
    q.push(1);
    vector<int> dist(n + 1, 1e9);
    dist[1] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto u : g[v]) {
        if (dist[u] == 1e9) {
          dist[u] = dist[v] + 1;
          q.push(u);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j : g[i]) {
        if (dist[j] == dist[i] + 1) {
          g2[i].pb(j);
        }
      }
    }
    dfs(1);
    vector<int> dp(n + 1, 1e9);
    for (int v : order) {
      dp[v] = dist[v];
      for (auto u : g[v]) {
        dp[v] = min(dp[v], dist[u]);
      }
      for (auto u : g2[v]) {
        dp[v] = min(dp[v], dp[u]);
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << dp[i] << ' ';
    }
    cout << '\n';
  }
}