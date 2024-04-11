/**              
 *  author: milos
 *  created: 11.12.2020 15:38:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> pref(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      cin >> s[i];              
      for (int j = 0; j < m; j++) {                       
        if (s[i][j] == '*') pref[i][j] = 1;
        if (j > 0) pref[i][j] += pref[i][j - 1];
      }
    }
    /*for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << pref[i][j] << " ";
      }
      cout << '\n';
    }*/
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '*') {
          for (int k = 0; k <= n; k++) {
            if ((i + k) >= n) break;
            int left = j - k, right = j + k;
            //cout << i << " " << left << " " << right << pref[i + k][right] << '\n';
            if (left < 0 || right >= m) break;
            if (left == 0) {
              //cout << i << " " << left << " " << right << " " << pref[i + k][right] << '\n';
              if (pref[i + k][right] == (right + 1)) ans++;
              else break;      
              //cout << i << '\n';
            } else {
              //cout << i << " " << left << " " << right << " " << pref[i + k][right] - pref[i + k][left - 1] << '\n';
              if ((pref[i + k][right] - pref[i + k][left - 1]) == (k * 2 + 1)) ans++;
              else break;
              //cout << i << '\n';
            }
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}