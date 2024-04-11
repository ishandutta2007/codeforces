/**
 *    author:  tourist
 *    created: 12.02.2022 17:40:06       
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool big = false;
    long long ans = 0;
    for (int i = 1; i < n - 1; i++) {
      big |= (a[i] > 1);
      ans += (a[i] + 1) / 2;
    }
    if (!big || (n == 3 && a[1] % 2 == 1)) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }
  return 0;
}