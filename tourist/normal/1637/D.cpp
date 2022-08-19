/**
 *    author:  tourist
 *    created: 12.02.2022 17:44:06       
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int s = accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);
    vector<bool> f(s + 1);
    f[0] = true;
    for (int i = 0; i < n; i++) {
      for (int j = s; j >= 0; j--) {
        if (f[j]) {
          if (j + a[i] <= s) {
            f[j + a[i]] = true;
          }
          if (j + b[i] <= s) {
            f[j + b[i]] = true;
          }
          f[j] = false;
        }
      }
    }
    int best = -1;
    for (int j = 0; j <= s; j++) {
      if (f[j]) {
        if (abs(2 * j - s) < abs(2 * best - s)) {
          best = j;
        }
      }
    }
    int sum_sq = 0;
    for (int i = 0; i < n; i++) {
      sum_sq += a[i] * a[i] + b[i] * b[i];
    }
    int ans = best * best + (s - best) * (s - best);
    ans += sum_sq * (n - 2);
    cout << ans << '\n';
  }
  return 0;
}