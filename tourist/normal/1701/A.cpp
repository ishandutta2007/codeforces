/**
 *    author:  tourist
 *    created: 08.07.2022 18:34:54       
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b + c + d == 0) {
      cout << 0 << '\n';
    } else {
      if (a + b + c + d == 4) {
        cout << 2 << '\n';
      } else {
        cout << 1 << '\n';
      }
    }
  }
  return 0;
}