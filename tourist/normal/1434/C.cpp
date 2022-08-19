/**
 *    author:  tourist
 *    created: 25.10.2020 14:23:37       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a - b * c > 0) {
      cout << -1 << '\n';
      continue;
    }
    long long step = b * d;
    long long last = a % step;
    long long first = a;
    long long cnt = (first - last) / step + 1;
    long long ans = (last + first) * cnt / 2;
    cout << ans << '\n';
  }
  return 0;
}