/**
 *    author:  wxhtzdy
 *    created: 23.08.2022 12:46:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  vector<tuple<char, int, int>> f;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != '#' && grid[i][j] != '.') {
        f.emplace_back(grid[i][j], i, j);
        grid[i][j] = '.';
      }
    }
  }
  int q;
  cin >> q;
  vector<char> dir(q);
  vector<int> step(q);
  for (int i = 0; i < q; i++) {
    cin >> dir[i] >> step[i];
  }
  vector<vector<int>> ver(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ver[i][j] = (grid[i][j] == '#' ? 1 : 0);
      if (i > 0) {
        ver[i][j] += ver[i - 1][j]; 
      }
    }
  }
  vector<vector<int>> hor(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      hor[i][j] = (grid[i][j] == '#' ? 1 : 0);
      if (j > 0) {
        hor[i][j] += hor[i][j - 1]; 
      }
    }
  }
  auto GetVer = [&](int j, int l, int r) {
    int sum = ver[r][j];
    if (l > 0) {
      sum -= ver[l - 1][j]; 
    }
    return sum;
  };
  auto GetHor = [&](int i, int l, int r) {
    int sum = hor[i][r];
    if (l > 0) {
      sum -= hor[i][l - 1];
    }
    return sum;
  };
  sort(f.begin(), f.end());
  vector<char> ans;
  for (int k = 0; k < (int) f.size(); k++) {
    int x = get<1>(f[k]);
    int y = get<2>(f[k]);
    bool ok = true;
    for (int i = 0; i < q; i++) {
      if (dir[i] == 'N') {
        if (x - step[i] < 0) {
          ok = false;
          break;
        }
        if (GetVer(y, x - step[i], x) != 0) {
          ok = false;
          break;
        }
        x -= step[i];
      }
      if (dir[i] == 'S') {
        if (x + step[i] >= n) {
          ok = false;
          break;
        }
        if (GetVer(y, x, x + step[i]) != 0) {
          ok = false;
          break;
        }
        x += step[i];
      }
      if (dir[i] == 'W') {
        if (y - step[i] < 0) {
          ok = false;
          break;
        }
        if (GetHor(x, y - step[i], y) != 0) {
          ok = false;
          break;
        }
        y -= step[i];
      }
      if (dir[i] == 'E') {
        if (y + step[i] >= m) {
          ok = false;
          break;
        }
        if (GetHor(x, y, y + step[i]) != 0) {
          ok = false;
          break;
        }
        y += step[i];
      }
    }
    if (ok) {
      ans.push_back(get<0>(f[k]));
    }
  }
  if (ans.empty()) {
    cout << "no solution" << '\n';
  } else {
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i];
    }
    cout << '\n';
  }                                                       
  return 0;
}