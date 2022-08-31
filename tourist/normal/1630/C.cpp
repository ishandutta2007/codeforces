/**
 *    author:  tourist
 *    created: 27.01.2022 17:55:11       
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
  vector<int> L(n, n);
  vector<int> R(n, -1);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    L[a[i]] = min(L[a[i]], i);
    R[a[i]] = max(R[a[i]], i);
  }
  vector<pair<int, int>> segs;
  segs.emplace_back(0, R[a[0]]);
  int ans = 1 + (0 < R[a[0]]);
  while (segs.back().second < n - 1) {
    int mx = -1;
    for (int i = segs.back().first; i <= segs.back().second; i++) {
      mx = max(mx, R[a[i]]);
    }
    if (mx > segs.back().second) {
      segs.emplace_back(L[a[mx]], mx);
      ans += 1;
    } else {
      int i = segs.back().second + 1;
      segs.emplace_back(i, R[a[i]]);
      ans += 1 + (i < R[a[i]]);
    }
  }
  cout << n - ans << '\n';
  return 0;
}