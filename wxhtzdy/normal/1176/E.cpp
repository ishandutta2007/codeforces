/**
 *  author: milos
 *  created: 04.01.2021 11:44:33
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
    vector<int> dist(n, -1);
    vector<int> que(1, 0);
    dist[0] = 0;
    for (int i = 0; i < (int) que.size(); i++) {
      for (int j : g[que[i]]) {
        if (dist[j] == -1) {
          dist[j] = dist[que[i]] + 1;
          que.push_back(j);
        }
      }
    }
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
      if (dist[i] % 2 == 0) {
        even += 1;
      } else {
        odd += 1;
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (dist[i] % 2 == 0 && even <= odd) {
        ans.push_back(i + 1);
      }
      if (dist[i] % 2 == 1 && odd < even) {
        ans.push_back(i + 1);
      }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}