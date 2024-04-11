/**
 *    author:  wxhtzdy
 *    created: 19.06.2022 08:55:58
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
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    int mx = -1e9;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mx <= a[i][j]) {
          mx = a[i][j];
          x = i;
          y = j;
        }
      }
    }
    int h = max(x + 1, n - x);
    int w = max(y + 1, m - y);
    cout << h * w << '\n';
  }                                                                  
  return 0;
}