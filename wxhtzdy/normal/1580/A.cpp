/**
 *    author:  milos
 *    created: 06.10.2021 18:43:45       
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
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    vector<vector<int>> sum(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[i][j] = (s[i][j] == '1' ? 1 : 0);
        if (i > 0) {
          sum[i][j] += sum[i - 1][j];
        }
        if (j > 0) {
          sum[i][j] += sum[i][j - 1];
        }
        if (i > 0 && j > 0) {
          sum[i][j] -= sum[i - 1][j - 1];
        }
      }
    }
    auto Get = [&](int xl, int yl, int xr, int yr) {
      int ret = sum[xr][yr];
      if (xl > 0) ret -= sum[xl - 1][yr];
      if (yl > 0) ret -= sum[xr][yl - 1];
      if (xl > 0 && yl > 0) ret += sum[xl - 1][yl - 1];
      return ret;  
    };
    int ans = 1e9;
    vector<vector<int>> c(m, vector<int>(2));
    for (int i = 0; i < n; i++) {
      for (int j = i + 4; j < n; j++) {
        for (int k = 0; k < m; k++) {
          c[k][0] = (s[i][k] == '0' ? 1 : 0) + (s[j][k] == '0' ? 1 : 0) + Get(i + 1, k, j - 1, k);
          c[k][1] = j - i - 1 - Get(i + 1, k, j - 1, k);
        }
        int mn = 1e9, curr = 1e9;
        for (int k = 0; k < m - 3; k++) {
          curr = min(curr + c[k][0], c[k][1]);
          mn = min(mn, curr + c[k + 1][0] + c[k + 2][0] + c[k + 3][1]);
        }
        ans = min(ans, mn);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}