/**
 *    author:  tourist
 *    created: 23.04.2022 18:05:01       
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
    int s = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s += x - 1;
    }
    cout << (s % 2 == 0 ? "maomao90" : "errorgorn") << '\n';
  }
  return 0;
}