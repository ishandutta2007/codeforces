/**
 *    author:  tourist
 *    created: 01.08.2022 17:35:02       
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
    int n, h, m;
    cin >> n >> h >> m;
    int ans = 12345;
    for (int i = 0; i < n; i++) {
      int hh, mm;
      cin >> hh >> mm;
      int x = h * 60 + m;
      int y = hh * 60 + mm;
      int diff = y - x;
      if (diff < 0) {
        diff += 1440;
      }
      ans = min(ans, diff);
    }
    cout << ans / 60 << " " << ans % 60 << '\n';
  }
  return 0;
}