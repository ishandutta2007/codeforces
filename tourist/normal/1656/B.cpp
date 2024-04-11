/**
 *    author:  tourist
 *    created: 24.03.2022 17:36:31       
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool ok = false;
    for (int i = 0; i < n; i++) {
      int x = a[i] + k;
      auto it = lower_bound(a.begin(), a.end(), x);
      if (it != a.end() && (*it) == x) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}