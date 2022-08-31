/**
 *    author:  tourist
 *    created: 08.05.2022 18:44:09       
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      --b[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      p[a[i]] = b[i];
    }
    int cnt = 0;
    vector<bool> was(n, false);
    for (int i = 0; i < n; i++) {
      if (was[i]) {
        continue;
      }
      int len = 0;
      int x = i;
      while (!was[x]) {
        was[x] = true;
        x = p[x];
        len += 1;
      }
      cnt += len / 2;
    }
    long long ans = 0;
    for (int i = 0; i < cnt; i++) {
      ans += n - i;
      ans -= i + 1;
    }
    cout << 2 * ans << '\n';
  }
  return 0;
}