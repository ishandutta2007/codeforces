/**
 *    author:  tourist
 *    created: 19.04.2022 18:58:36       
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
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = (long long) 1e18;
  for (int p = 0; p < n; p++) {
    long long cur = 0;
    long long x = 0;
    for (int i = p + 1; i < n; i++) {
      long long k = x / a[i] + 1;
      cur += k;
      x = k * a[i];
    }
    x = 0;
    for (int i = p - 1; i >= 0; i--) {
      long long k = x / a[i] + 1;
      cur += k;
      x = k * a[i];
    }
    ans = min(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}