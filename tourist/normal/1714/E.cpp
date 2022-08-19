/**
 *    author:  tourist
 *    created: 01.08.2022 17:43:24       
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
    bool any = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      while (a[i] % 10 != 0 && a[i] % 10 != 2) {
        a[i] += a[i] % 10;
      }
      any |= (a[i] % 10 == 0);
    }
    if (any) {
      cout << (a == vector<int>(n, a[0]) ? "Yes" : "No") << '\n';
      continue;
    }
    int val = a[0] % 20;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      ok &= (a[i] % 20 == val);
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
  return 0;
}