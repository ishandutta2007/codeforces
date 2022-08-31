/**
 *    author:  tourist
 *    created: 22.04.2022 18:37:41       
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
    long long s = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      s += a[i];
      if (s <= x) {
        ans += (x - s) / (i + 1) + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}