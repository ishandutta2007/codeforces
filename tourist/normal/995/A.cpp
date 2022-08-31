/**
 *    author:  tourist
 *    created: 24.11.2020 19:39:26       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(4, vector<int>(n));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  vector<pair<int, int>> pos;
  for (int i = 0; i < n; i++) {
    pos.emplace_back(1, i);
  }
  for (int i = n - 1; i >= 0; i--) {
    pos.emplace_back(2, i);
  }
  vector<tuple<int, int, int>> ret;
  for (int shift = 0; shift < 2 * n; shift++) {
    for (int i = 0; i < n; i++) {
      if (a[0][i] != 0 && a[0][i] == a[1][i]) {
        ret.emplace_back(a[1][i], 0, i);
        a[1][i] = 0;
      }
      if (a[3][i] != 0 && a[3][i] == a[2][i]) {
        ret.emplace_back(a[2][i], 3, i);
        a[2][i] = 0;
      }
    }
    int start = -1;
    for (int i = 0; i < 2 * n; i++) {
      if (a[pos[i].first][pos[i].second] == 0) {
        start = i;
        break;
      }
    }
    if (start == -1) {
      cout << -1 << '\n';
      return 0;
    }
    auto u = pos[start];
    for (int it = 0; it < 2 * n - 1; it++) {
      auto p = pos[(start + it + 1) % (2 * n)];
      if (a[p.first][p.second] != 0) {
        ret.emplace_back(a[p.first][p.second], u.first, u.second);
        a[u.first][u.second] = a[p.first][p.second];
        a[p.first][p.second] = 0;
      }
      u = p;
    }
  }
  cout << ret.size() << '\n';
  for (auto& p : ret) {
    cout << get<0>(p) << " " << get<1>(p) + 1 << " " << get<2>(p) + 1 << '\n';
  }
  return 0;
}