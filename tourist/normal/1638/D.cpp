/**
 *    author:  tourist
 *    created: 14.02.2022 20:40:23       
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
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<bool>> was(h - 1, vector<bool>(w - 1));
  vector<vector<int>> col(h - 1, vector<int>(w - 1));
  vector<pair<int, int>> que;
  auto Check = [&](int i, int j) {
    if (i >= 0 && j >= 0 && i < h - 1 && j < w - 1) {
      if (was[i][j]) {
        return;
      }
      int color = -1;
      bool ok = true;
      for (int di = 0; di <= 1; di++) {
        for (int dj = 0; dj <= 1; dj++) {
          if (a[i + di][j + dj] != -1) {
            if (color == -1) {
              color = a[i + di][j + dj];
            } else {
              if (color != a[i + di][j + dj]) {
                ok = false;
              }
            }
          }
        }
      }
      if (ok) {
        que.emplace_back(i, j);
        col[i][j] = (color == -1 ? 1 : color);
        was[i][j] = true;
      }
    }
  };
  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w - 1; j++) {
      Check(i, j);
    }
  }
  for (int b = 0; b < (int) que.size(); b++) {
    auto [i, j] = que[b];
    for (int di = 0; di <= 1; di++) {
      for (int dj = 0; dj <= 1; dj++) {
        a[i + di][j + dj] = -1;
      }
    }
    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        Check(i + di, j + dj);
      }
    }
  }
  if ((int) que.size() == (h - 1) * (w - 1)) {
    cout << que.size() << '\n';
    reverse(que.begin(), que.end());
    for (auto& p : que) {
      cout << p.first + 1 << " " << p.second + 1 << " " <<
        col[p.first][p.second] << "\n";
    }
  } else {
    cout << -1 << '\n';
  }
  return 0;
}