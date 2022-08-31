/**
 *    author:  tourist
 *    created: 25.06.2022 18:24:34       
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
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (a[i] > 0);
    }
    for (int i = 0; i < n - 1; i++) {
      ans -= (a[i] > 0 && a[i + 1] > 0);
    }
    ans = min(ans, 2);
    cout << ans << '\n';
  }
  return 0;
}