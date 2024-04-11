/**
 *    author:  tourist
 *    created: 12.01.2022 17:51:12       
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
    int ans = -1;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      auto it = mp.find(a[i]);
      if (it != mp.end()) {
        ans = max(ans, n - (i - it->second));
      }
      mp[a[i]] = i;
    }
    cout << ans << '\n';
  }
  return 0;
}