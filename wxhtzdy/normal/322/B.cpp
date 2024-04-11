#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int x = min({a, b, c}), ans = 0;
  for (int take = 0; take <= min(3, min({a, b, c})); take++) {
    ans = max(ans, take + (a - take) / 3 + (b - take) / 3 + (c - take) / 3);
  }
  cout << ans << '\n';
  return 0;
}