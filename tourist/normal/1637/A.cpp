/**
 *    author:  tourist
 *    created: 12.02.2022 17:35:00       
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
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
      pref[i] = max(pref[i - 1], a[i]);
    }
    vector<int> suf(n);
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = min(suf[i + 1], a[i]);
    }
    bool any = false;
    for (int i = 0; i < n - 1; i++) {
      if (pref[i] > suf[i + 1]) {
        any = true;
        break;
      }
    }
    cout << (any ? "YES" : "NO") << '\n';
  }
  return 0;
}