/**
 *    author:  wxhtzdy
 *    created: 22.08.2022 14:32:47
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
        a[i][j] = (int) (s[j] - '0');
      }
    }        
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cnt += a[i][j];
      }
    }
    if (cnt == n * m) {
      cout << n * m - 2 << '\n';
      continue;
    }
    if (cnt <= 1) {
      cout << cnt << '\n';
      continue;
    }
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m - 1; j++) {
        int cc = 0;
        for (int di = 0; di <= 1; di++) {
          for (int dj = 0; dj <= 1; dj++) {
            cc += a[i + di][j + dj];
          }
        }
        if (cc > 0 && cc < 3) {
          ok = true;
        }
      }
    }
    cout << cnt - !ok << '\n';
  }                                                                    
  return 0;
}