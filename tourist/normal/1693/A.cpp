/**
 *    author:  tourist
 *    created: 16.06.2022 18:35:58       
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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> b(n);
    bool ok = true;
    bool zero = false;
    for (int i = 0; i < n - 1; i++) {
      b[i] = a[i];
      ok &= (b[i] >= 0);
      if (b[i] == 0) {
        zero = true;
      }
      if (zero && b[i] > 0) {
        ok = false;
      }
      a[i + 1] += a[i];
      a[i] = 0;
    }
    if (a[n - 1] != 0 || !ok) {
      cout << "No" << '\n';
      continue;
    }
    cout << "Yes" << '\n';
  }
  return 0;
}