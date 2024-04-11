/**
 *    author:  milos
 *    created: 27.01.2021 00:02:30       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      g[x].push_back(y);
    }
    vector<int> que(1, 0);
    vector<int> dist(n, -1);
    dist[0] = 0;
    for (int b = 0; b < (int) que.size(); b++) {
      for (int j : g[que[b]]) {
        if (dist[j] == -1) {
          dist[j] = dist[que[b]] + 1;
          que.push_back(j);
        }
      }
    }
    const int inf = 1e9;
    vector<int> dp(n, inf);
    vector<bool> was(n, false);
    function<void(int)> Dfs = [&](int u) {
      was[u] = true;
      dp[u] = dist[u];
      for (int j : g[u]) {
        if (!was[j] && dist[u] < dist[j]) {
          Dfs(j);
        }
        if (dist[u] < dist[j]) {
          dp[u] = min(dp[u], dp[j]);
        } else {
          dp[u] = min(dp[u], dist[j]);
        }
      }
    };
    Dfs(0);                  
    for (int i = 0; i < n; i++) {
      cout << dp[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}