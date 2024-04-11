#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(11);

  int a, b;
  cin >> a >> b;

  if (a < b) {
    cout << -1 << "\n";
  } else {
    double ans = HUGE_VAL;
    for (auto x : {a - b, a + b}) {
      if (2 * b <= x) {
        ans = min(ans, 0.5 * x / (x / (2 * b)));
      }
    }
    cout << ans << "\n";
  }
}