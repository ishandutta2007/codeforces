#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    int sx, sy;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == 'L') {
          sx = i;
          sy = j;
        }
      }
    }
    vector<vector<int>> deg(n, vector<int>(m));
    auto Valid = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#';
    };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '#') continue;
        for (int d = 0; d < 4; d++) {
          int ni = i + dx[d], nj = j + dy[d];
          if (Valid(ni, nj)) {
            deg[i][j] += 1;
          }
        }
      }
    }
    /*cout << "deg\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << deg[i][j] << " ";
      }
      cout << "\n";
    }*/
    vector<pair<int, int>> que(1, make_pair(sx, sy));
    vector<vector<int>> vis(n, vector<int>(m));
    vis[sx][sy] = 1;
    for (int x = 0; x < que.size(); x++) {
      int i = que[x].first;
      int j = que[x].second;
      for (int d = 0; d < 4; d++) {
        int ni = i + dx[d], nj = j + dy[d];
        if (!Valid(ni, nj)) continue;
        if (i == sx && j == sy) {
          //cout << "at: " << ni << " " << nj << " " << deg[ni][nj] << " " << vis[ni][nj] << "\n";
        }
        deg[ni][nj] -= 1;
        if (!vis[ni][nj] && deg[ni][nj] <= 1) {
          vis[ni][nj] = 1;
          que.emplace_back(ni, nj);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == sx && j == sy) {
          cout << 'L';
        } else {
          if (vis[i][j]) {
            cout << '+';
          } else {
            cout << s[i][j];
          }
        }
      }
      cout << "\n";
    }
  }
  return 0;
}