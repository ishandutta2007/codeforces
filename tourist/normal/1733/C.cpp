/**
 *    author:  tourist
 *    created: 19.09.2022 17:55:15       
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
    cout << n - 1 << '\n';
    if (n > 1) {
      cout << 1 << " " << n << '\n';
    }
    if ((a[0] + a[n - 1]) % 2 == 0) {
      a[0] = a[n - 1];
    } else {
      a[n - 1] = a[0];
    }
    for (int i = 1; i < n - 1; i++) {
      if ((a[0] + a[i]) % 2 == 0) {
        cout << i + 1 << " " << n << '\n';
      } else {
        cout << 1 << " " << i + 1 << '\n';
      }
    }
  }
  return 0;
}