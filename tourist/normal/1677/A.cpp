/**
 *    author:  tourist
 *    created: 08.05.2022 18:35:23       
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
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
    }
    vector<vector<int>> s(n + 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
      s[i + 1] = s[i];
      for (int j = p[i]; j < n; j++) {
        s[i + 1][j] += 1;
      }
    }
    long long ans = 0;
    for (int b = 0; b < n; b++) {
      for (int c = b + 1; c < n; c++) {
        ans += s[b][p[c]] * (s[n][p[b]] - s[c + 1][p[b]]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}