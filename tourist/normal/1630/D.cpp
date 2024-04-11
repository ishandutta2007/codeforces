/**
 *    author:  tourist
 *    created: 27.01.2022 18:04:52       
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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    int g = 0;
    for (int x : b) {
      g = __gcd(g, x);
    }
    long long ans = 0;
    for (int flip = 0; flip < 2; flip++) {
      long long cur = 0;
      for (int r = 0; r < g; r++) {
        vector<long long> c;
        for (int i = r; i < n; i += g) {
          c.push_back(a[i]);
        }
        if (flip && !c.empty()) {
          c[0] *= -1;
        }
        int negs = 0;
        long long sum = 0;
        long long mn = (long long) 1e18;
        for (long long x : c) {
          negs += (x < 0);
          sum += abs(x);
          mn = min(mn, abs(x));
        }
        if (negs % 2 == 1) {
          sum -= 2 * mn;
        }
        cur += sum;
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}