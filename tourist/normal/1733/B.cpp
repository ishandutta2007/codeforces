/**
 *    author:  tourist
 *    created: 19.09.2022 17:36:09       
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
    int n, x, y;
    cin >> n >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    if (x > 0) {
      cout << -1 << '\n';
      continue;
    }
    if (y == 0) {
      cout << -1 << '\n';
      continue;
    }
    if ((n - 1) % y == 0) {
      int me = 2;
      for (int i = 0; i < (n - 1) / y; i++) {
        for (int j = 0; j < y; j++) {
          cout << me << " ";
        }
        me += y;
      }
      cout << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}