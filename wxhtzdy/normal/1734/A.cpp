/**
 *    author:  wxhtzdy
 *    created: 24.09.2022 23:51:30
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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 1e18;
    for (int i = 0; i + 2 < n; i++) {
      ans = min(ans, a[i + 2] - a[i + 1] + a[i + 1] - a[i]);
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}