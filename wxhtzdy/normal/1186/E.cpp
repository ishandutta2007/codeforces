/**
 *    author:  wxhtzdy
 *    created: 14.07.2022 15:06:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m, qq;
  cin >> n >> m >> qq;
  vector<vector<int>> c(2 * n, vector<int>(2 * m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      c[i][j] = (int) (s[j] - '0');
    }
  }                         
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i + n][j] = c[i][j + m] = 1 - c[i][j];
      c[i + n][j + m] = c[i][j];
    }
  }             
  n *= 2;
  m *= 2;
  vector<vector<int>> f(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      f[i][j] = c[i][j];
      if (i > 0) {
        f[i][j] += f[i - 1][j];
      }
      if (j > 0) {
        f[i][j] += f[i][j - 1];
      }
      if (i > 0 && j > 0) {
        f[i][j] -= f[i - 1][j - 1];
      }
    }
  }
  vector<vector<int>> q(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      q[i][j] = 1 - c[i][j];
      if (i > 0) {
        q[i][j] += q[i - 1][j];
      }
      if (j > 0) {
        q[i][j] += q[i][j - 1];
      }
      if (i > 0 && j > 0) {
        q[i][j] -= q[i - 1][j - 1];
      }
    }
  }
  auto Get = [&](int x, int y) {
    if (x < 0 || y < 0) {
      return 0LL;
    }
    if (x < n && y < m) {
      return (long long) f[x][y];
    }
    int i = x / n;
    int j = y / m;
    bool is = ((__builtin_popcount(i) + __builtin_popcount(j)) % 2);
    long long res = 0;
    long long fx = (x / n) * n;
    long long fy = (y / m) * m;
    if (is) {
      res += q[x % n][y % m];
    } else {
      res += f[x % n][y % m]; 
    }
    res += (fx * (y + 1) + fy * (x + 1) - fx * fy) / 2;
    return res;
  };
  while (qq--) {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    --xa; --ya; --xb; --yb;
    cout << Get(xb, yb) - Get(xb, ya - 1) - Get(xa - 1, yb) + Get(xa - 1, ya - 1) << '\n';
  }                                                    
  return 0;
}