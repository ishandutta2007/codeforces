/**
 *    author:  tourist
 *    created: 19.05.2022 18:36:27       
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
    long long a, b, c;
    cin >> a >> b >> c;
    cout << a + b * (long long) 1e9 << " " << b << " " << c << '\n';
  }
  return 0;
}