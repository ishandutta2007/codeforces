/**
 *    author:  tourist
 *    created: 03.01.2022 17:33:12       
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
    if ((n + 1) / 2 < k) {
      cout << -1 << '\n';
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << (i == j && i % 2 == 0 && i < 2 * k ? 'R' : '.');
        }
        cout << '\n';
      }
    }
  }
  return 0;
}