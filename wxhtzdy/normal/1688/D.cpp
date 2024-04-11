/**
 *    author:  wxhtzdy
 *    created: 05.06.2022 14:00:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    long long ans = pref[min(n, k)];
    for (int i = 0; i <= n - k; i++) {
      ans = max(ans, pref[i + k] - pref[i]);
    }
    if (k <= n) {
      cout << ans + k * 1LL * (k - 1) / 2 << '\n';
      continue;
    }
    ans += k * 1LL * n - n * 1LL * (n + 1) / 2;
    cout << ans << '\n';
  }                                                                    
  return 0;
}