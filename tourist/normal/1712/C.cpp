/**
 *    author:  tourist
 *    created: 13.08.2022 17:37:45       
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
      --a[i];
    }
    vector<int> last(n, -1);
    for (int i = 0; i < n; i++) {
      last[a[i]] = i;
    }
    int L = n - 1;
    while (L > 0 && a[L - 1] <= a[L]) {
      L -= 1;
    }
    if (L == 0) {
      cout << 0 << '\n';
      continue;
    }
    set<int> s;
    int ans = n + 1;
    int R = 0;
    for (int i = 0; i < n; i++) {
      R = max(R, last[a[i]]);
      s.insert(a[i]);
      if (R == i && i + 1 >= L) {
        ans = min(ans, (int) s.size());
      }
    }
    cout << ans << '\n';
  }
  return 0;
}