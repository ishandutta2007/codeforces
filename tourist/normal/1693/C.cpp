/**
 *    author:  tourist
 *    created: 16.06.2022 18:42:58       
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<vector<int>> gr(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    gr[y].push_back(x);
  }
  vector<int> deg(n);
  for (int i = 0; i < n; i++) {
    deg[i] = (int) g[i].size();
  }
  const int inf = (int) 1e9;
  vector<int> d(n, inf);
  d[n - 1] = 0;
  set<pair<int, int>> s;
  s.emplace(d[n - 1], n - 1);
  while (!s.empty()) {
    int i = s.begin()->second;
    s.erase(s.begin());
    for (int j : gr[i]) {
      --deg[j];
      int ft = d[i] + 1 + deg[j];
      if (ft < d[j]) {
        s.erase(make_pair(d[j], j));
        d[j] = ft;
        s.emplace(d[j], j);
      }
    }
  }
  cout << d[0] << '\n';
  return 0;
}