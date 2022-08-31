/**
 *    author:  tourist
 *    created: 24.03.2022 18:06:27       
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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    const long long inf = (long long) 9e18;
    long long ans = -(long long) 9e18;
    bool any = false;
    for (int v = 0; v <= n; v++) {
      long long k = 0;
      long long b = 0;
      {
        int L = max(v, 1);
        int R = n - 2;
        if (L <= R) {
          b += a[0] * (pref[R + 1] - pref[L]);
          k += a[0] * (R - L + 1) + (pref[R + 1] - pref[L]);
        }
      }
      {
        int L = 1;
        int R = min(n - 2, v - 1);
        if (L <= R) {
          b += a[n - 1] * (pref[R + 1] - pref[L]);
          k += a[n - 1] * (R - L + 1) + (pref[R + 1] - pref[L]);
        }
      }
      {
        b += a[0] * a[n - 1];
        k += a[0] + a[n - 1];
      }
      long long L = -inf;
      long long R = +inf;
      if (v < n) {
        // a[v] + t >= 0
        // t >= -a[v]
        L = max(L, -a[v]);
      }
      if (v > 0) {
        // a[v - 1] + t <= 0
        // t <= -a[v - 1]
        R = min(R, -a[v - 1]);
      }
//      debug(v, k, b, L, R);
      if (R == inf && k > 0) {
        any = true;
        break;
      }
      if (L == -inf && k < 0) {
        any = true;
        break;
      }
      if (R != inf) {
        ans = max(ans, R * k + b);
      }
      if (L != -inf) {
        ans = max(ans, L * k + b);
      }
    }
    if (any) {
      cout << "INF" << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}