/**
 *  author: milos
 *  created: 02.01.2021 00:42:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = min({a, b, c});
    a -= ans;
    b -= ans;
    c -= ans;
    ans += max(0, min({a, b, (a + b) / 3}));
    cout << ans << '\n';
  }
  return 0;
}