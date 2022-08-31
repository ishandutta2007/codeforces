/**
 *    author:  tourist
 *    created: 18.07.2022 18:25:01       
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    string s(m, 'B');
    for (int i = 0; i < n; i++) {
      a[i] = min(a[i], m - 1 - a[i]);
      if (s[a[i]] == 'B') {
        s[a[i]] = 'A';
        continue;
      }
      a[i] = m - 1 - a[i];
      if (s[a[i]] == 'B') {
        s[a[i]] = 'A';
      }
    }
    cout << s << '\n';
  }
  return 0;
}