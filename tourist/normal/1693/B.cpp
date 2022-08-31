/**
 *    author:  tourist
 *    created: 16.06.2022 18:39:47       
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
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
      cin >> p[i];
      --p[i];
    }
    vector<long long> l(n), r(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
    }
    vector<long long> sum(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (l[i] > sum[i]) {
        ans += 1;
        sum[p[i]] += r[i];
      } else {
        sum[p[i]] += min(sum[i], r[i]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}