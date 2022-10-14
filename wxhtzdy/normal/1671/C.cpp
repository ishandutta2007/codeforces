/**
 *    author:  wxhtzdy
 *    created: 04.06.2022 13:25:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    long long ans = 0;       
    for (int i = 1; i <= n; i++) {
      if (pref[i] > x) {
        break;
      }
      long long d = x - pref[i];
      ans += (d / i) + 1;
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}