/**
 *    author:  milos
 *    created: 01.08.2021 07:38:15       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;           
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[j][i];
      }
    }
    vector<int> suff(n);
    for (int i = n - 1; i >= 0; i--) {
      if (i < n - 1) suff[i] = suff[i + 1];
      suff[i] += a[i][0];  
    }
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
      if (i > 0) pref[i] = pref[i - 1];
      pref[i] += a[i][1];
    }           
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }    
    int ans = min(suff[1], pref[n - 2]);
    for (int i = 1; i < n - 1; i++) {
      ans = min(ans, max(pref[i - 1], suff[i + 1]));
    }
    cout << ans << '\n';
  }
  return 0;
}