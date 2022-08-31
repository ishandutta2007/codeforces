/**
 *    author:  tourist
 *    created: 27.12.2021 17:38:21       
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
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    long long ans = (long long) 9e18;
    for (int t = 0; t <= n - 1; t++) {
      long long sum = pref[n - t] + a[0] * t;
      long long cur = t;
      if (sum > k) {
        long long diff = sum - k;
        cur += (diff + t) / (t + 1);
      }
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}