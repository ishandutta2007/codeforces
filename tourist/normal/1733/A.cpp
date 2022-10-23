/**
 *    author:  tourist
 *    created: 19.09.2022 17:34:05       
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
    vector<int> mx(k);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx[i % k] = max(mx[i % k], a[i]);
    }
    cout << accumulate(mx.begin(), mx.end(), 0LL) << '\n';
  }
  return 0;
}