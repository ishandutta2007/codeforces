#include <bits/stdc++.h>
using namespace std;

const int F[] = {0, 1, 2, 0, 2, 1, 0};

int a[3], b[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
  }

  long long w = min({a[0] / 3, a[1] / 2, a[2] / 2});
  a[0] -= w * 3, a[1] -= w * 2, a[2] -= w * 2;

  long long ans = 0;
  for (int i = 0; i < 7; ++i) {
    copy(a, a + 3, b);
    int d = 0;
    for ( ; b[F[(i + d) % 7]] > 0; ++d) {
      --b[F[(i + d) % 7]];
    }
    ans = max(ans, 7 * w + d);
  }

  cout << ans << "\n";
}