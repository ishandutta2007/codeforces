/**
 *    author:  tourist
 *    created: 06.09.2022 17:34:57       
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
    int ans = a[n - 1] - a[0];
    for (int i = 0; i < n - 1; i++) {
      ans = max(ans, a[i] - a[i + 1]);
    }
    for (int i = 1; i < n; i++) {
      ans = max(ans, a[i] - a[0]);
    }
    for (int i = 0; i < n - 1; i++) {
      ans = max(ans, a[n - 1] - a[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}