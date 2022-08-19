/**
 *    author:  tourist
 *    created: 15.07.2022 17:36:45       
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
    long long ans = 0;
    int k = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] == 0) {
        k += 1;
      } else {
        ans += k;
        k = 0;
      }
    }
    ans += accumulate(a.begin(), a.end() - 1, 0LL);
    cout << ans << '\n';
  }
  return 0;
}