/**
 *    author:  tourist
 *    created: 24.11.2019 11:14:08       
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
  vector<vector<int>> dist(h, vector<int>(w, -1));
  vector<pair<int, int>> qe;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.') {
        continue;
      }
      int border = 0;
      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          if (i + di < 0 || j + dj < 0 || i + di >= h || j + dj >= w || s[i + di][j + dj] == '.') {
            border = 1;
            break;
          }
        }
      }
      if (border) {
        dist[i][j] = 0;
        qe.emplace_back(i, j);
      }
    }
  }
  for (int b = 0; b < (int) qe.size(); b++) {
    int i = qe[b].first;
    int j = qe[b].second;
    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        if (i + di < 0 || j + dj < 0 || i + di >= h || j + dj >= w || s[i + di][j + dj] == '.' || dist[i + di][j + dj] != -1) {
          continue;
        }
        dist[i + di][j + dj] = dist[i][j] + 1;
        qe.emplace_back(i + di, j + dj);
      }
    }
  }
  vector<vector<bool>> was(h, vector<bool>(w, false));
  vector<tuple<int, int, int>> que;
  int low = 0, high = (min(h, w) - 1) / 2;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    que.clear();
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (dist[i][j] >= mid) {
          que.emplace_back(i, j, 0);
          was[i][j] = true;
        } else {
          was[i][j] = false;
        }
      }
    }
    bool fail = false;
    for (int b = 0; b < (int) que.size(); b++) {
      int i = get<0>(que[b]);
      int j = get<1>(que[b]);
      int d = get<2>(que[b]);
      if (d == mid) {
        break;
      }
      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          if (i + di >= 0 && j + dj >= 0 && i + di < h && j + dj < w) {
            if (s[i + di][j + dj] == '.') {
              fail = true;
              break;
            }
            if (!was[i + di][j + dj]) {
              was[i + di][j + dj] = true;
              que.emplace_back(i + di, j + dj, d + 1);
            }
          } else {
            fail = true;
            break;
          }
        }
      }
      if (fail) {
        break;
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (!was[i][j] && s[i][j] == 'X') {
          fail = true;
          break;
        }
      }
      if (fail) { 
        break;
      }
    }
    if (fail) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  cout << low << '\n';
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (dist[i][j] < low) {
        s[i][j] = '.';
      }
    }
    cout << s[i] << '\n';
  }
  return 0;
}