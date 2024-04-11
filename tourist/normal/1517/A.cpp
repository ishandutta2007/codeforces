/**
 *    author:  tourist
 *    created: 23.04.2021 17:29:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    if (n % 2050 != 0) {
      cout << -1 << '\n';
      continue;
    }
    n /= 2050;
    long long ans = 0;
    while (n > 0) {
      ans += n % 10;
      n /= 10;
    }
    cout << ans << '\n';
  }
  return 0;
}