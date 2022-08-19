/**
 *    author:  tourist
 *    created: 22.04.2022 18:41:02       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

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
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += abs(a[i] - a[i + 1]);
    }
    {
      int mn = (int) 1e9;
      mn = min(mn, a[0] - 1);
      mn = min(mn, a[n - 1] - 1);
      for (int i = 0; i < n; i++) {
        mn = min(mn, 2 * (a[i] - 1));
      }
      ans += mn;
    }
    int mx = *max_element(a.begin(), a.end());
    if (mx < x) {
      int mn = (int) 1e9;
      mn = min(mn, x - a[0]);
      mn = min(mn, x - a[n - 1]);
      for (int i = 0; i < n; i++) {
        mn = min(mn, 2 * (x - a[i]));
      }
      ans += mn;
    }
    cout << ans << '\n';
  }
  return 0;
}