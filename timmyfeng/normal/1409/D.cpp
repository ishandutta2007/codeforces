#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n, s;
    cin >> n >> s;

    int64_t base = 1;
    int64_t ans = 1e18;

    for (int i = 0; i < 19; ++i) {
      int64_t n_new = ((n - 1) / base + 1) * base;
      int64_t diff = n_new - n;
      int sum = 0;
      while (n_new > 0) {
        sum += n_new % 10;
        n_new /= 10;
      }
      if (sum <= s) {
        ans = min(ans, diff);
      }
      base *= 10;
    }
    cout << ans << "\n";
  }
}