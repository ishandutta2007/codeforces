/**
 *  author: milos
 *  created: 07.01.2021 12:42:55
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
      g[y].push_back(x);
    }
    vector<int> ans(n, -1);
    vector<int> que;
    ans[0] = 1;                 
    for (int v : g[0]) {
      ans[v] = 0;
      que.push_back(v);
    }
    for (int b = 0; b < (int) que.size(); b++) {
      for (int v : g[que[b]]) {
        if (ans[v] == -1) {
          ans[v] = 1;
          for (int x : g[v]) {
            if (ans[x] == -1) {
              ans[x] = 0;
              que.push_back(x);
            }
          }
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (ans[i] == -1) {
        ok = false;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    vector<int> v;
    for (int i = 0; i < n; i++) {
      if (ans[i] == 1) {
        v.push_back(i + 1);
      }
    }
    cout << (int) v.size() << '\n';
    for (int i = 0; i < (int) v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}