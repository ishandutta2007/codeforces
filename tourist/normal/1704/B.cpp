/**
 *    author:  tourist
 *    created: 31.07.2022 17:07:08       
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
    int ans = 0;
    int beg = 0;
    while (beg < n) {
      int end = beg;
      int mx = a[beg];
      int mn = a[beg];
      while (end + 1 < n) {
        int new_mx = max(mx, a[end + 1]);
        int new_mn = min(mn, a[end + 1]);
        if (new_mx - new_mn > 2 * x) {
          break;
        }
        mx = new_mx;
        mn = new_mn;
        end += 1;
      }
      ans += 1;
      beg = end + 1;
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}