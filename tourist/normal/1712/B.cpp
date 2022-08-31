/**
 *    author:  tourist
 *    created: 13.08.2022 17:36:08       
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
    for (int i = n - 1; i >= 0; i--) {
      if (i % 2 == n % 2) {
        a[i] = i + 1;
      } else {
        a[i] = max(0, i - 1);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] + 1 << " \n"[i == n - 1];
    }
  }
  return 0;
}