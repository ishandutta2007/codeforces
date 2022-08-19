/**
 *    author:  tourist
 *    created: 23.04.2022 18:07:46       
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int L = n;
    int R = -1;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == a[i + 1]) {
        L = min(L, i);
        R = max(R, i);
      }
    }
    if (L >= R) {
      cout << 0 << '\n';
    } else {
      cout << max(1, R - L - 1) << '\n';
    }
  }
  return 0;
}