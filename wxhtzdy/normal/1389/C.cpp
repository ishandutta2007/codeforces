/**
 *    author:  milos
 *    created: 13.04.2021 23:21:23       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size(), ans = n;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        int cnt = 0;
        for (int k = 0; k < n; k++) {
          if (s[k] - '0' == i && cnt % 2 == 0) {
            cnt++;  
          } else {
            if (s[k] - '0' == j && cnt % 2 == 1) {
              cnt++;
            }
          }
        }
        if (i != j && cnt % 2 == 1) {
          cnt--;
        }                                    
        ans = min(ans, n - cnt);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}