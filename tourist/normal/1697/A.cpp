/**
 *    author:  tourist
 *    created: 12.06.2022 18:34:19       
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
    int n, m;
    cin >> n >> m;
    int s = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s += a;
    }
    cout << max(0, s - m) << '\n';
  }
  return 0;
}