/**
 *    author:  wxhtzdy
 *    created: 16.10.2022 16:49:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);       
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long p = a * 1LL * b;
    bool found = false;
    for (long long x = a + 1; x <= c; x++) {
      // x * y % p == 0
      long long k = (x * p) / __gcd(x, p);
      long long z = ((b + 1) * 1LL * x + k - 1) / k;
      k = k * z;
      long long y = k / x;
      if (y > b && y <= d) {
        cout << x << " " << y << '\n';
        found = true;
        break;
      }
    }
    if (!found) {
      cout << -1 << " " << -1 << '\n';
    }
  }                                                                    
  return 0;
}