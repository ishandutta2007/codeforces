/**
 *    author:  milos
 *    created: 11.08.2020 10:45:57      
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
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      if (i < n - 1) {
        if (s[i][m - 1] == 'R')
          ans++;
      } else {
        for (int j = 0; j < m - 1; j++) {
          if (s[i][j] == 'D')
            ans++;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;   
}