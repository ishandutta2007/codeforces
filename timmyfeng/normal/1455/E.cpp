#include <bits/stdc++.h>
using namespace std;

long long x[4], y[4], p[4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    for (int i = 0; i < 4; ++i) {
      cin >> x[i] >> y[i];
    }

    long long ans = 0;
    iota(p, p + 4, 0);
    do {
      long long pos_x = min(x[p[0]], x[p[2]]) - max(x[p[1]], x[p[3]]);
      long long neg_x = max(x[p[0]], x[p[2]]) - min(x[p[1]], x[p[3]]);
      long long pos_y = min(y[p[0]], y[p[1]]) - max(y[p[2]], y[p[3]]);
      long long neg_y = max(y[p[0]], y[p[1]]) - min(y[p[2]], y[p[3]]);
      pos_x = max(0LL, min(pos_x, neg_y));
      pos_y = max(0LL, min(pos_y, neg_x));
      ans = min(ans, -2 * (pos_x + pos_y));
    } while (next_permutation(p, p + 4));

    sort(x, x + 4);
    sort(y, y + 4);
    for (int i = 0; i < 4; ++i) {
      ans += abs(x[i] - x[1]);
      ans += abs(y[i] - y[1]);
    }

    cout << ans << "\n";
  }
}