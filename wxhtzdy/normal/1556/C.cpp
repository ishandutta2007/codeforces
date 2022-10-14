/**
 *    author:  milos
 *    created: 28.08.2021 21:12:40       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }             
  long long ans = 0;
  for (int l = 1; l + 1 < n; l += 2) {
    long long bal = 0, mn = 1e9;
    for (int r = l; r + 1 < n; r++) {
      bal += (r % 2 == 0 ? c[r] : -c[r]);
      mn = min(mn, bal);
      if (r % 2 == l % 2) {
        continue;
      }    
      long long min_l = max(0LL, -mn);
      long long min_r = bal + min_l;
      assert(min_r >= 0);
      ans += min(max(0LL, c[l - 1] - min_l + 1), max(0LL, c[r + 1] - min_r + 1));
    }
  }                                    
  for (int i = 0; i + 1 < n; i += 2) {
    ans += min(c[i], c[i + 1]);
  }
  cout << ans << '\n';
  return 0;
}