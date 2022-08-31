/**
 *    author:  tourist
 *    created: 06.05.2020 17:40:19       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  int empty_rows = 0;
  for (int i = 0; i < h; i++) {
    int st = 0;
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#' && (j == 0 || s[i][j - 1] == '.')) {
        ++st;
      }
    }
    if (st > 1) {
      cout << -1 << '\n';
      return 0;
    }
    if (st == 0) {
      ++empty_rows;
    }
  }
  int empty_cols = 0;
  for (int i = 0; i < w; i++) {
    int st = 0;
    for (int j = 0; j < h; j++) {
      if (s[j][i] == '#' && (j == 0 || s[j - 1][i] == '.')) {
        ++st;
      }
    }
    if (st > 1) {
      cout << -1 << '\n';
      return 0;
    }
    if (st == 0) {
      ++empty_cols;
    }
  }
  if ((empty_rows > 0) != (empty_cols > 0)) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] != '#') {
        continue;
      }
      ++ans;
      vector<pair<int, int>> que;
      que.emplace_back(i, j);
      s[i][j] = '.';
      for (int b = 0; b < (int) que.size(); b++) {
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            if (di * di + dj * dj == 1) {
              int ni = que[b].first + di;
              int nj = que[b].second + dj;
              if (ni >= 0 && nj >= 0 && ni < h && nj < w && s[ni][nj] == '#') {
                s[ni][nj] = '.';
                que.emplace_back(ni, nj);
              }
            }
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}