#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  long long k;
  cin >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    edges.emplace_back(u, v);
  }
  auto Check = [&](int x) {
    vector<vector<int>> g(n);
    for (auto& e : edges) {
      int u = e.first;
      int v = e.second;
      if (a[u] <= x && a[v] <= x) {
        g[u].push_back(v);
      }
    }                                         
    vector<bool> was(n, false);
    vector<int> stk;
    function<void(int)> Dfs = [&](int u) {
      was[u] = true;
      for (int v : g[u]) {
        if (!was[v]) {
          Dfs(v);
        }
      }
      stk.push_back(u);
    };
    for (int i = 0; i < n; i++) {
      if (!was[i]) {
        Dfs(i);
      }
    }
    vector<int> f(n);        
    for (int i = n - 1; i >= 0; i--) {
      f[stk[i]] = n - i;
    }                
    for (int i = 0; i < n; i++) {
      for (int j : g[i]) {
        if (f[i] > f[j]) {
          return true;
        }
      }
    }
    vector<int> dp(n);
    for (int i = n - 1; i >= 0; i--) {
      int u = stk[i];
      for (int v : g[u]) {
        if (a[v] <= x) {
          dp[v] = max(dp[v], dp[u] + 1);
        }
      }
    }
    return *max_element(dp.begin(), dp.end()) >= k - 1;
  };
  int low = *min_element(a.begin(), a.end()), high = 1e9, ans = -1;
  while (low <= high) {
    int mid = low + high >> 1;
    if (Check(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << '\n';                             
  return 0;
}