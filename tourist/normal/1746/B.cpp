/**
 *    author:  tourist
 *    created: 15.10.2022 18:43:55       
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
    int k0 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        k0 += 1;
      }
    }
    int k1 = 0;
    int ans = max(k0, k1);
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        k0 -= 1;
      } else {
        k1 += 1;
      }
      ans = min(ans, max(k0, k1));
    }                             
    cout << ans << '\n';
  }
  return 0;
}