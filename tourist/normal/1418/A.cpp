/**
 *    author:  tourist
 *    created: 14.09.2020 19:57:05       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y, k;
    cin >> x >> y >> k;
    // we need k sticks and k coals
    // k coals <= k*y sticks
    // we need k + k*y = k * (y + 1) sticks
    // we have 1 stick, and one trade creates x-1 extra sticks
    long long need = (long long) k * (y + 1) - 1;
    // ceil(a / b) = (a + b - 1) / b
    long long ans = (need + (x - 2)) / (x - 1) + k;
    cout << ans << '\n';
  }
  return 0;
}