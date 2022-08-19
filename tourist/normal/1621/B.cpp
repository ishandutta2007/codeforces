/**
 *    author:  tourist
 *    created: 03.01.2022 17:36:55       
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
    vector<int> l(n), r(n);
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i] >> c[i];
    }
    const long long inf = (long long) 1e18;
    long long minL = inf;
    long long minR = inf;
    long long minLR = inf;
    int L = (int) 1e9 + 1;
    int R = -1;
    for (int i = 0; i < n; i++) {
      if (l[i] < L) {
        minL = inf;
        minLR = inf;
        L = l[i];
      }
      if (r[i] > R) {
        minR = inf;
        minLR = inf;
        R = r[i];
      }
      if (l[i] == L) {
        minL = min(minL, c[i]);
      }
      if (r[i] == R) {
        minR = min(minR, c[i]);
      }
      if (l[i] == L && r[i] == R) {
        minLR = min(minLR, c[i]);
      }
      cout << min(minL + minR, minLR) << '\n';
    }
  }
  return 0;
}