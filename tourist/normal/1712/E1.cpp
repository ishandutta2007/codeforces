/**
 *    author:  tourist
 *    created: 13.08.2022 17:52:00       
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
    int l, r;
    cin >> l >> r;
    long long len = r - l + 1;
    long long ans = len * (len - 1) * (len - 2) / 6;
    vector<int> cnt(r + 1);
    for (int i = l; i <= r; i++) {
      for (int j = i + i; j <= r; j += i) {
        cnt[j] += 1;
      }
    }
    for (int i = l; i <= r; i++) {
      ans -= cnt[i] * (cnt[i] - 1) / 2;
    }
    for (int x = 12; x <= 2 * r; x += 12) {
      if (x / 2 >= l && x / 2 <= r && x / 3 >= l && x / 3 <= r && x / 4 >= l && x / 4 <= r) {
        ans -= 1;
      }
    }
    for (int x = 30; x <= 2 * r; x += 30) {
      if (x / 2 >= l && x / 2 <= r && x / 3 >= l && x / 3 <= r && x / 5 >= l && x / 5 <= r) {
        ans -= 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}