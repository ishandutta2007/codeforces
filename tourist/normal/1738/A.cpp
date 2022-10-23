/**
 *    author:  tourist
 *    created: 30.09.2022 17:27:31       
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
    vector<int> cnt(2);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]] += 1;
    }            
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    if (cnt[0] == cnt[1]) {
      long long ans = 0;
      int mn = b[0];
      for (int i = 0; i < n; i++) {
        ans += b[i];
        mn = min(mn, b[i]);
      }
      ans = 2 * ans - mn;
      cout << ans << '\n';
      continue;
    }
    if (cnt[0] > cnt[1]) {
      swap(cnt[0], cnt[1]);
      for (int i = 0; i < n; i++) {
        a[i] ^= 1;
      }
    }
    vector<int> all;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += b[i];
      if (a[i] == 0) {
        ans += b[i];
      } else {
        all.push_back(b[i]);
      }
    }
    sort(all.rbegin(), all.rend());
    for (int i = 0; i < cnt[0]; i++) {
      ans += all[i];
    }
    cout << ans << '\n';
  }
  return 0;
}