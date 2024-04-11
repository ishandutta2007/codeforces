/**
 *    author:  tourist
 *    created: 05.01.2021 18:05:09       
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
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> res(n, -1);
    res[0] = 1;
    vector<int> que;
    for (int x : g[0]) {
      que.push_back(x);
      res[x] = 0;
    }
    for (int b = 0; b < (int) que.size(); b++) {
      for (int v : g[que[b]]) {
        if (res[v] == -1) {
          res[v] = 1;
          for (int x : g[v]) {
            if (res[x] == -1) {
              res[x] = 0;
              que.push_back(x);
            }
          }
        }
      }
    }
    if (*min_element(res.begin(), res.end()) == -1) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      if (res[i] == 1) {
        ret.push_back(i);
      }
    }
    cout << ret.size() << '\n';
    for (int i = 0; i < (int) ret.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ret[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}