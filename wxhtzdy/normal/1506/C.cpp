/**
 *    author:  milos
 *    created: 25.03.2021 16:02:17       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s >> t;
    int n = (int) s.size(), m = (int) t.size(), ans = max(n, m) * 2;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int sz = j - i + 1;
        bool ok = false;
        for (int k = 0; k < m; k++) {
          if (k + sz > m) {
            break;
          }
          bool have = true; 
          for (int l = 0; l < sz; l++) {
            if (i + l >= n || k + l >= m || s[i + l] != t[k + l]) {
              have = false;  
            }
          }
          if (have) {
            ok = true;
          }
        }
        if (ok) {
          ans = min(ans, n - sz + m - sz);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}