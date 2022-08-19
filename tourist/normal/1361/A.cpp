/**
 *    author:  tourist
 *    created: 04.06.2020 17:34:50       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    --t[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return t[i] < t[j];
  });
  vector<int> was(n);
  int T = 0;
  for (int i : order) {
    ++T;
    int cnt = 0;
    for (int j : g[i]) {
      if (t[i] == t[j]) {
        cout << -1 << '\n';
        return 0;
      }
      if (t[j] < t[i] && was[t[j]] != T) {
        was[t[j]] = T;
        cnt += 1;
      }
    }
    if (cnt != t[i]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << order[i] + 1;
  }
  cout << '\n';
  return 0;
}