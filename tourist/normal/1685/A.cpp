/**
 *    author:  tourist
 *    created: 25.05.2022 21:34:07       
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
    if (n % 2 == 1) {
      cout << "NO" << '\n';
      continue;
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 0; i < n / 2; i++) {
      b[2 * i] = a[i];
    }
    for (int i = 0; i < n / 2; i++) {
      b[2 * i + 1] = a[i + n / 2];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (b[i] > b[(i + 1) % n] && b[i] > b[(i + n - 1) % n]) {
        continue;
      }
      if (b[i] < b[(i + 1) % n] && b[i] < b[(i + n - 1) % n]) {
        continue;
      }
      ok = false;
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      cout << b[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}