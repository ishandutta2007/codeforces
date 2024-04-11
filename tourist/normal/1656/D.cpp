/**
 *    author:  tourist
 *    created: 24.03.2022 17:45:38       
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
    long long n;
    cin >> n;
    long long ans = -1;
    long long k = 2;
    while (true) {
      long long s = k * (k + 1) / 2;
      if (s > n) {
        break;
      }
      if ((n - s) % k == 0) {
        ans = k;
        break;
      }
      k *= 2;
    }
    if (ans == -1) {
      k = n;
      while (k % 2 == 0) {
        k /= 2;
      }
      if (k > 1 && k < (long long) 3e9) {
        long long s = k * (k + 1) / 2;
        if (n >= s && (n - s) % k == 0) {
          ans = k;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}