/**
 *    author:  tourist
 *    created: 23.02.2022 13:04:00       
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<bool> used(n, false);
    int ans = 0;
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (used[i]) {
        continue;
      }
      if (a[i] % x == 0) {
        int f = a[i] / x;
        while (j >= 0 && (used[j] || a[j] > f)) {
          j -= 1;
        }
        if (j >= 0 && !used[j] && a[j] == f) {
          used[i] = true;
          used[j] = true;
          ans += 1;
        }
      }
    }
    cout << n - 2 * ans << '\n';
  }
  return 0;
}