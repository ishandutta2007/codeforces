#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < 30; i++) {
      if (((1 << i) & a) != ((1 << i) & b)) {
        ans += 1 << i;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}