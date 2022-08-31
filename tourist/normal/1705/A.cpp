/**
 *    author:  tourist
 *    created: 15.07.2022 17:34:53       
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
    int n, x;
    cin >> n >> x;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i + n] - a[i] < x) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}