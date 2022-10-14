#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<tuple<int, int, int>> que;
  vector<vector<int>> dist(n, vector<int>(m, 1e9));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '.') {
        que.emplace_back(0, i, j);
        dist[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    que.emplace_back(0, i, -1);
    que.emplace_back(0, i, m);
  }
  for (int i = 0; i < m; i++) {
    que.emplace_back(0, -1, i);
    que.emplace_back(0, n, i);
  }
  for (int v = 0; v < que.size(); v++) {
    int d = get<0>(que[v]);
    int x = get<1>(que[v]);
    int y = get<2>(que[v]);
    for (int dir = 0; dir < 8; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] > d + 1) {
        dist[nx][ny] = d + 1;
        que.emplace_back(dist[nx][ny], nx, ny);
      }
    }
  }
  int low = 0, high = 1e3, ans = 0;
  while (low <= high) {
    int mid = low + high >> 1;
    que.clear();
    vector<vector<int>> t(n, vector<int>(m, 1e9));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dist[i][j] > mid) {
          t[i][j] = 0;
          que.emplace_back(0, i, j);
        }
      }
    }
    for (int v = 0; v < que.size(); v++) {
      int d = get<0>(que[v]);
      int x = get<1>(que[v]);
      int y = get<2>(que[v]);
      for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && t[nx][ny] > d + 1) {
          t[nx][ny] = d + 1;
          que.emplace_back(t[nx][ny], nx, ny);
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == 'X' && t[i][j] > mid) {
          ok = false;
        }
      }
    }
    if (ok) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << (dist[i][j] > ans ? 'X' : '.');
    }
    cout << '\n';
  }
  return 0;
}