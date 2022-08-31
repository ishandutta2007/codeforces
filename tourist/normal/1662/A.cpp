/**
 *    author:  tourist
 *    created: 24.04.2022 15:05:43       
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
    vector<int> a(11);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      a[y] = max(a[y], x);
    }
    int mn = *min_element(a.begin() + 1, a.end());
    int s = accumulate(a.begin(), a.end(), 0);
    if (mn == 0) {
      cout << "MOREPROBLEMS" << '\n';
    } else {
      cout << s << '\n';
    }
  }
  return 0;
}