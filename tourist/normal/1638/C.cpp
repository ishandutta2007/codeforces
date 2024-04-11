/**
 *    author:  tourist
 *    created: 14.02.2022 20:30:40       
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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int ans = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      mx = max(mx, p[i]);
      if (mx == i + 1) {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}