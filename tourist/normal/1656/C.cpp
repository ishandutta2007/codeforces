/**
 *    author:  tourist
 *    created: 24.03.2022 17:37:50       
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
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = (int) a.size();
    bool k0 = false;
    bool k1 = false;
    bool k2 = false;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) k0 = true;
      if (a[i] == 1) k1 = true;
      if (a[i] == 2) k2 = true;
    }
    if (k1) {
      if (k0 || k2) {
        cout << "NO" << '\n';
      } else {
        bool ok = true;
        for (int i = 1; i < n - 1; i++) {
          if (a[i] + 1 == a[i + 1]) {
            ok = false;
            break;
          }
        }
        cout << (ok ? "YES" : "NO") << '\n';
      }
    } else {
      cout << "YES" << '\n';
    }
  }
  return 0;
}