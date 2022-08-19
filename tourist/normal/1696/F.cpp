/**
 *    author:  tourist
 *    created: 25.06.2022 18:24:34       
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
    vector<vector<string>> s(n, vector<string>(n));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        cin >> s[i][j];
        s[j][i] = s[i][j];
      }
    }
    bool found = false;
    for (int ver = 1; ver < n; ver++) {
      vector<pair<int, int>> que(2);
      que[0] = make_pair(0, ver);
      que[1] = make_pair(ver, 0);
      vector<bool> used(n, false);
      used[0] = used[ver] = true;
      for (int b = 0; b < (int) que.size(); b++) {
        for (int i = 0; i < n; i++) {
          if (!used[i]) {
            if (s[que[b].first][i][que[b].second] == '1') {
              used[i] = true;
              que.emplace_back(que[b].second, i);
            }
          }
        }
      }
      if ((int) que.size() != n) {
        continue;
      }
      vector<vector<int>> g(n, vector<int>(n, n + 5));
      for (auto& p : que) {
        g[p.first][p.second] = g[p.second][p.first] = 1;
      }
      for (int i = 0; i < n; i++) {
        g[i][i] = 0;
      }
      for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
          }
        }
      }
      bool fail = false;
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          for (int k = 0; k < n; k++) {
            if ((s[i][j][k] == '1') != (g[i][k] == g[j][k])) {
              fail = true;
            }
          }
        }
      }
      if (!fail) {
        cout << "Yes" << '\n';
        que.erase(que.begin());
        for (auto& p : que) {
          cout << p.first + 1 << " " << p.second + 1 << '\n';
        }
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "No" << '\n';
    }
  }
  return 0;
}