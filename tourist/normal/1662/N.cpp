/**
 *    author:  tourist
 *    created: 24.04.2022 16:19:35       
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
  int n;
  cin >> n;
  vector<pair<int, int>> at(n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      --a;
      at[a] = make_pair(i, j);
    }
  }
  vector<int> r(n), c(n);
  long long ans = 0;
  for (int i = 0; i < n * n; i++) {
    int x = at[i].first;
    int y = at[i].second;
    ans += r[x] * c[y];
    r[x] += 1;
    c[y] += 1;
  }
  ans = 2 * (n * (n - 1LL) / 2) * (n * (n - 1LL) / 2) - ans;
  cout << ans << '\n';
  return 0;
}