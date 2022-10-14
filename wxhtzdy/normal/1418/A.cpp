/**
 *  author: milos
 *  created: 15.09.2020 00:32:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long x, y, k;
    cin >> x >> y >> k;
    // give 1 and get x = + (x - 1)                                   
    long long s = y * k + k - 1;
    long long ans = s / (x - 1) + k;
    if (s % (x - 1) != 0) {
      ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}