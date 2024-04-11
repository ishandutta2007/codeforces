#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    int ans = 0;
    vector<vector<int>> was(n, vector<int>(n));
    vector<pair<int, int>> order;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        order.emplace_back(i, j);
      }
    }
    sort(order.begin(), order.end(), [&](pair<int, int> x, pair<int, int> y) {
      int val_x = x.first + x.second;
      int val_y = y.first + y.second;
      if (val_x != val_y) {
        return val_x < val_y;
      } else {
        return x.first < y.first;
      }
    });
    for (int id = 0; id < n * n; id++) {
      int i = order[id].first;
      int j = order[id].second;
      bool ok = true;
      for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && was[ni][nj]) {
          ok = false;
        }
      }
      if (ok) {
        ans ^= a[i][j];
        for (int dir = 0; dir < 4; dir++) {
          int ni = i + dx[dir];
          int nj = j + dy[dir];
          if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
            was[ni][nj] = 1;
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}