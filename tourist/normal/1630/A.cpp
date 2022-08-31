/**
 *    author:  tourist
 *    created: 27.01.2022 17:26:26       
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
    if (k < n - 1) {
      for (int i = 0; i < n; i++) {
        int j = (i == 0 ? n - 1 - k : (i == n - 1 - k ? 0 : (i == k ? n - 1 : (i == n - 1 ? k : n - 1 - i))));
        if (i < j) {
          cout << i << " " << j << '\n';
        }
      }
    } else {
      if (n == 4) {
        cout << -1 << '\n';
      } else {
        k -= 1;
        for (int i = 0; i < n; i++) {
          int j = (i == 0 ? n - 1 - k : (i == n - 1 - k ? 0 : (i == k ? n - 1 : (i == n - 1 ? k : n - 1 - i))));
          if (i == 2) j = n - 4; else
          if (i == 3) j = n - 3; else
          if (i == n - 4) j = 2; else
          if (i == n - 3) j = 3;
          if (i < j) {
            cout << i << " " << j << '\n';
          }
        }
      }
    }
  }
  return 0;
}