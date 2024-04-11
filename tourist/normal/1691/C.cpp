/**
 *    author:  tourist
 *    created: 31.05.2022 18:46:35       
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
    string s;
    cin >> s;
    if (s == string(n, '0')) {
      cout << 0 << '\n';
      continue;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (s[i] == '1');
    }
    int ans = 11 * cnt;
    int L = 0;
    int R = n - 1;
    while (s[L] == '0') {
      L += 1;
    }
    while (s[R] == '0') {
      R -= 1;
    }
    R = n - 1 - R;
    if (cnt == 1) {
      if (R <= k) {
        ans -= 10;
      } else {
        if (L <= k) {
          ans -= 1;
        }
      }
    } else {
      if (L + R <= k) {
        ans -= 11;
      } else {
        if (R <= k) {
          ans -= 10;
        } else {
          if (L <= k) {
            ans -= 1;
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}