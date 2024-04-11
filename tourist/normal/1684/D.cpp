/**
 *    author:  tourist
 *    created: 19.05.2022 18:46:17       
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i] + i > a[j] + j;
    });
    vector<bool> skip(n, false);
    for (int i = 0; i < k; i++) {
      skip[order[i]] = true;
    }
    int bonus = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (skip[i]) {
        bonus += 1;
      } else {
        ans += a[i] + bonus;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}