#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    int ans = (x % 10 - 1) * 10, cnt = 1;
    while (x > 0) {
      ans += cnt;
      cnt++;
      x /= 10;
    }
    cout << ans << '\n';
  }
  return 0;
}