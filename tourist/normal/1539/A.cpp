/**
 *    author:  tourist
 *    created: 20.06.2021 13:50:51       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, x, t;
    cin >> n >> x >> t;
    // for i=0..n-1: ans += min(i, t / x)
    long long m = t / x;
    long long ans = n * (n - 1) / 2;
    if (n - 1 > m) {
      long long k = n - 1 - m;
      ans -= k * (k + 1) / 2;
    }
    cout << ans << '\n';
  }
  return 0;
}