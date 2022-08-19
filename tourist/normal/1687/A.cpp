/**
 *    author:  tourist
 *    created: 03.06.2022 18:34:32       
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
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    long long add = (long long) k * (k - 1) / 2;
    if (k > n) {
      add -= (long long) (k - n) * (k - n - 1) / 2;
      k = n;
    }
    long long ans = 0;
    for (int i = 0; i + k <= n; i++) {
      ans = max(ans, pref[i + k] - pref[i]);
    }
    cout << ans + add << '\n';
  }
  return 0;
}