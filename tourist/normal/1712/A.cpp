/**
 *    author:  tourist
 *    created: 13.08.2022 17:35:09       
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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
      if (p[i] >= k) {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}