#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int ans = abs(x - a) + abs(y - b);
    if (x != a && y != b) ans += 2;
    cout << ans << '\n';
  }
  return 0;
}