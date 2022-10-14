/**
 *    author: m371
 *    created: 09.10.2021 10:11:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  auto Valid = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;  
  };
  vector<vector<vector<pair<int, int>>>> g(n, vector<vector<pair<int, int>>>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!(a[i][j] & (8))) {
        int nx = i - 1;
        int ny = j;
        if (Valid(nx, ny)) {
          if (!(a[nx][ny] & (2))) {
            g[i][j].emplace_back(nx, ny);
            //cout << i << " " << j << " " << nx << " " << ny << '\n';
            g[nx][ny].emplace_back(i, j);   
          }
        }
      }
      if (!(a[i][j] & (4))) {
        int nx = i;
        int ny = j + 1;
        if (Valid(nx, ny)) {
          if (!(a[nx][ny] & (1))) {
            g[i][j].emplace_back(nx, ny);
            //cout << i << " " << j << " " << nx << " " << ny << '\n';
            g[nx][ny].emplace_back(i, j);   
          }
        }
      }
      if (!(a[i][j] & (2))) {
        int nx = i + 1;
        int ny = j;
        if (Valid(nx, ny)) {
          if (!(a[nx][ny] & (2))) {
            g[i][j].emplace_back(nx, ny);
            //cout << i << " " << j << " " << nx << " " << ny << '\n';
            g[nx][ny].emplace_back(i, j);   
          }
        }
      }
      if (!(a[i][j] & (1))) {
        int nx = i;
        int ny = j - 1;
        if (Valid(nx, ny)) {
          if (!(a[nx][ny] & (1))) {
            g[i][j].emplace_back(nx, ny);
           // cout << i << " " << j << " " << nx << " " << ny << '\n';
            g[nx][ny].emplace_back(i, j);   
          }
        }
      }
    }
  }
  vector<vector<bool>> was(n, vector<bool>(m, false));
  vector<int> sizes;
  int sz = 0;
  function<void(int, int)> Dfs = [&](int i, int j) {
    if (!Valid(i, j) || was[i][j]) {
      return;
    }
    was[i][j] = true;
    sz++;
    for (auto to : g[i][j]) {
      Dfs(to.first, to.second);
    }
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!was[i][j]) {
        sz = 0;
        Dfs(i, j);
        sizes.push_back(sz);
      }
    }
  }
  sort(sizes.rbegin(), sizes.rend());
  for (int i = 0; i < sizes.size(); i++) {
    cout << sizes[i] << " ";
  }
  return 0;
}