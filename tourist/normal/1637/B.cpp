/**
 *    author:  tourist
 *    created: 12.02.2022 17:37:23       
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
      ans += (a[i] == 0 ? 2 : 1) * (i + 1) * (n - i);
    }
    cout << ans << '\n';
  }
  return 0;
}