#include <bits/stdc++.h>
using namespace std;

long long c[6 + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int x, y;
    cin >> x >> y;
    x *= -1;
    y *= -1;

    for (int i = 1; i <= 6; ++i) {
      cin >> c[i];
    }

    long long ans = LLONG_MAX;

    // using diagonal
    if (x > y) {
      ans = min(ans, (x - y) * c[3] + (y < 0 ? -y * c[1] : y * c[4]));
      ans = min(ans, (x - y) * c[2] + (x < 0 ? -x * c[1] : x * c[4]));
    } else {
      ans = min(ans, (y - x) * c[6] + (y < 0 ? -y * c[1] : y * c[4]));
      ans = min(ans, (y - x) * c[5] + (x < 0 ? -x * c[1] : x * c[4]));
    }

    // using orthogonal
    if (x < 0) {
      ans = min(ans, -x * c[6] + (y < 0 ? -y * c[2] : y * c[5]));
    } else {
      ans = min(ans, x * c[3] + (y < 0 ? -y * c[2] : y * c[5]));
    }

    cout << ans << "\n";
  }
}