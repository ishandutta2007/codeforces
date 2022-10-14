/**
 *    author:  wxhtzdy
 *    created: 11.10.2022 16:41:54
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
      int pp = 0;
      int mx = 0;
      int cnt = 0;
      for (int j = 1; j <= n; j++) {
        cnt++;
        if (pref[j] - pref[pp] == pref[i]) {
          pp = j;
          mx = max(mx, cnt);
          cnt = 0; 
        }
      }
      if (pp == n) {
        ans = min(ans, mx);
      }
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}