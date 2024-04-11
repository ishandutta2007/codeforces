/**                         
 *    author:  milos
 *    created: 23.03.2021 13:56:12       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        a[i][j] = (s[j] == '1');
      }
    }                        
    auto Rec1 = [&](int x, int y) {
      vector<pair<int, int>> c;
      c.emplace_back(x, y);
      while (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1) {
        x += 1;
      }
      x -= 1;
      while (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1) {
        y += 1;
      }
      y -= 1;
      c.emplace_back(x, y);
      while (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1) {
        x -= 1;
      }
      x += 1;
      while (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1) {
        y -= 1;
      }
      y += 1;
      c.emplace_back(x, y);
      int ans = (c[1].first - c[0].first) * 4;
      return (c[0] == c[2] && c[1].first - c[0].first == c[1].second - c[0].second && c[1].first > c[0].first ? ans : 0);
    };
    auto Rec2 = [&](int x, int y) {
      vector<pair<int, int>> c;
      c.emplace_back(x, y);
      while (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1) {
        x += 1;
        y += 1;
      }
      x -= 1;
      y -= 1;
      c.emplace_back(x, y);
      while (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1) {
        x += 1;
        y -= 1;  
      }
      x -= 1;
      y += 1;
      c.emplace_back(x, y);
      while (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1) {
        x -= 1;
        y -= 1;  
      }
      x += 1;
      y += 1;
      c.emplace_back(x, y);
      while (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1) {
        x -= 1;
        y += 1;  
      }
      x += 1;
      y -= 1;
      c.emplace_back(x, y);
      int ans = (c[1].first - c[0].first) * 4;
      if (c[0] == c[4] && c[1].first - c[0].first == c[2].first - c[1].first && c[2].first - c[3].first == c[3].first - c[4].first && c[1].first > c[0].first) {
        return ans;
      } else {
        return 0;
      }
    };
    int f = 0;
    function<void(int, int)> Dfs = [&](int x, int y) {
      if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 0) {
        return 0;
      }
      f += a[x][y];
      a[x][y] = 0;
      Dfs(x - 1, y);
      Dfs(x + 1, y);
      Dfs(x, y - 1);
      Dfs(x, y + 1);
      Dfs(x + 1, y + 1);
      Dfs(x - 1, y + 1);
      Dfs(x + 1, y - 1);
      Dfs(x - 1, y - 1);
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1) {
          int cnt = Rec1(i, j);
          if (cnt == 0) {
            cnt = Rec2(i, j);
          }
          f = 0;
          Dfs(i, j);
          ans += (cnt == f ? 1 : 0);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}