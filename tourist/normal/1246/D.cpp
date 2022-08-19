/**
 *    author:  tourist
 *    created: 26.10.2019 12:31:16       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  p[0] = -1;
  for (int i = 1; i < n; i++) {
    cin >> p[i];
  }
  vector<vector<int>> children(n);
  for (int i = 1; i < n; i++) {
    children[p[i]].push_back(i);
  }
  vector<int> depth(n);
  for (int i = 1; i < n; i++) {
    depth[i] = depth[p[i]] + 1;
  }
  vector<int> mark(n);
  int x = (int) (max_element(depth.begin(), depth.end()) - depth.begin());
  while (x != 0) {
    mark[x] = 1;
    x = p[x];
  }
  vector<int> order;
  function<void(int)> Dfs = [&](int v) {
    order.push_back(v);
    for (int r = 0; r < 2; r++) {
      for (int u : children[v]) {
        if (mark[u] == r) {
          Dfs(u);            
        }
      }
    }
  };
  Dfs(0);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << order[i];
  }
  cout << '\n';
  vector<int> w(n);
  w[0] = -1;
  for (int i = 1; i < n; i++) {
    w[order[i]] = order[i - 1];
  }
  vector<int> ret;
  for (int x : order) {
    while (p[x] != w[x]) {
      ret.push_back(x);
      w[x] = w[w[x]];
    }
  }
  cout << ret.size() << '\n';
  for (int i = 0; i < (int) ret.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ret[i];
  }
  cout << '\n';
  return 0;
}