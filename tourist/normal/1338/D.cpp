/**
 *    author:  tourist
 *    created: 12.04.2020 18:15:51       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> take(n);
  vector<int> nope(n);
  int ans = 0;
  function<void(int, int)> Dfs = [&](int v, int pr) {
    vector<int> children;
    for (int u : g[v]) {
      if (u == pr) {
        continue;
      }
      Dfs(u, v);
      children.push_back(u);
    }
    {
      take[v] = 0;
      for (int u : children) {
        take[v] = max(take[v], nope[u]);
      }
      take[v] += 1;
    }
    {
      nope[v] = 0;
      for (int u : children) {
        nope[v] = max(nope[v], max(nope[u], take[u]));
      }
      nope[v] += (int) g[v].size() - 2;
    }
    {
      int m1 = 0, m2 = 0;
      for (int u : children) {
        if (nope[u] > m1) {
          m2 = m1;
          m1 = nope[u];
        } else {
          m2 = max(m2, nope[u]);
        }
      }
      ans = max(ans, m1 + m2 + 1);
    }
    {
      int m1 = 0, m2 = 0;
      for (int u : children) {
        int cur = max(nope[u], take[u]);
        if (cur > m1) {
          m2 = m1;
          m1 = cur;
        } else {
          m2 = max(m2, cur);
        }
      }
      ans = max(ans, m1 + m2 + (int) g[v].size() - 2);
    }
  };
  Dfs(0, -1);
  cout << ans << '\n';
  return 0;
}