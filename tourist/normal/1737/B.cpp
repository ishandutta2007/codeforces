/**
 *    author:  tourist
 *    created: 07.10.2022 18:36:03       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

long long Count(long long n) {
  long long ret = 0;
  for (int x = 0; x <= 2; x++) {
    long long low = 0;
    long long high = (long long) 2e9;
    while (low < high) {
      long long mid = (low + high + 1) >> 1;
      if (mid * (mid + x) > n) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }
    ret += low;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long l, r;
    cin >> l >> r;
    cout << Count(r) - Count(l - 1) << '\n';
  }
  return 0;
}