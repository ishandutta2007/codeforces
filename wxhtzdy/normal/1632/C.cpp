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
    int ans = b - a;
    for (int i = 0; i < b - a; i++) {
      int new_a = a + i;
      new_a = new_a | b;
      ans = min(ans, i + 1 + new_a - b);
    }
    for (int new_b = b; new_b <= 3 * b; new_b++) {
      int new_a = a | new_b;
      ans = min(ans, new_b - b + 1 + new_a - new_b);
    }
    cout << ans << '\n';
  }
  return 0;
}