/**
 *    author:  milos
 *    created: 23.01.2021 21:20:05       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long sum = 0;
  vector<long long> dist(n);
  function<void(int, int, int)> Dfs = [&](int u, int p, int dep) {
    sum += (long long) dep * a[u];
    dist[u] = a[u];    
    for (int j : g[u]) {
      if (j != p) {
        Dfs(j, u, dep + 1);
        dist[u] += dist[j];
      }
    }
  };
  Dfs(0, -1, 0);
  long long ans = 0LL;
  function<void(int, int)> Solve = [&](int u, int p) {
    ans = max(ans, sum);
    for (int  j : g[u]) {
      if (j != p) {
        sum -= dist[j];
        dist[u] -= dist[j];
        sum += dist[u];
        dist[j] += dist[u];
        Solve(j, u);
        dist[j] -= dist[u];
        sum -= dist[u];
        dist[u] += dist[j];
        sum += dist[j];
      }
    }
  };
  Solve(0, -1);
  cout << ans << '\n';
  return 0;
}