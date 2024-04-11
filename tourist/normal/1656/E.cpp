/**
 *    author:  tourist
 *    created: 24.03.2022 18:21:29       
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
  int tt;
  cin >> tt;
  while (tt--) {
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
    vector<int> dist(n, -1);
    vector<int> que(1, 0);
    dist[0] = 0;
    for (int b = 0; b < (int) que.size(); b++) {
      for (int u : g[que[b]]) {
        if (dist[u] == -1) {
          que.push_back(u);
          dist[u] = dist[que[b]] ^ 1;
        }
      }
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      if (dist[i] == 0) {
        a[i] = -(int) g[i].size();
      } else {
        a[i] = (int) g[i].size();
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}