/**
 *    author:  tourist
 *    created: 31.05.2022 18:43:01       
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
    vector<int> c(2);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      c[x % 2] += 1;
    }
    cout << min(c[0], c[1]) << '\n';
  }
  return 0;
}