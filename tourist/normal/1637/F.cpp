/**
 *    author:  tourist
 *    created: 12.02.2022 18:08:05       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int root = (int) (max_element(h.begin(), h.end()) - h.begin());
  long long ans = 0;
  function<int(int, int)> Dfs = [&](int v, int pv) {
    vector<int> got;
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      got.push_back(Dfs(u, v));
    }
    if (got.empty()) {
      ans += h[v];
      return h[v];
    }
    if (pv == -1 && got.size() > 1) {
      auto it = max_element(got.begin(), got.end());
      ans += h[v] - (*it);
      (*it) = -1;
      it = max_element(got.begin(), got.end());
      ans += h[v] - (*it);
      return h[v];
    }
    if (pv == -1) {
      ans += h[v];
    }
    int mx = *max_element(got.begin(), got.end());
    if (mx >= h[v]) {
      return mx;
    } else {
      ans += h[v] - mx;
      return h[v];
    }
  };
  Dfs(root, -1);
  cout << ans << '\n';
  return 0;
}