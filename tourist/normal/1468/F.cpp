/**
 *    author:  tourist
 *    created: 25.12.2020 14:48:48       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      int x = c - a;
      int y = d - b;
      int g = __gcd(abs(x), abs(y));
      x /= g;
      y /= g;
      ans += mp[make_pair(x, y)];
      mp[make_pair(-x, -y)] += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}