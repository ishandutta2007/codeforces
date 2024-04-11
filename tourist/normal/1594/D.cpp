/**
 *    author:  tourist
 *    created: 08.10.2021 18:26:41       
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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
      int x, y;
      string z;
      cin >> x >> y >> z;
      --x; --y;
      g[x].emplace_back(y, z[0] == 'i');
      g[y].emplace_back(x, z[0] == 'i');
    }
    vector<int> c(n, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (c[i] != -1) {
        continue;
      }
      vector<int> que(1, i);
      c[i] = 0;
      int sum = 0;
      for (int b = 0; b < (int) que.size(); b++) {
        sum += c[que[b]];
        for (auto& p : g[que[b]]) {
          int to = p.first;
          int col = c[que[b]] ^ p.second;
          if (c[to] == -1) {
            c[to] = col;
            que.push_back(to);
          } else {
            if (c[to] != col) {
              ans = -1;
              break;
            }
          }
        }
        if (ans == -1) {
          break;
        }
      }
      if (ans == -1) {
        break;
      }
      ans += max(sum, (int) que.size() - sum);
    }
    cout << ans << '\n';
  }
  return 0;
}