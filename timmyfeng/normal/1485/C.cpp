#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int x, y;
    cin >> x >> y;

    int i = 2;
    long long ans = 0;
    for ( ; i <= y && i - 1 <= x / (i + 1); ++i) {
      ans += i - 1;
    }

    while (i <= y) {
      int q = x / (i + 1);
      if (q == 0) {
        break;
      }

      int j = min(x / q, y + 1);
      ans += (long long) (j - i) * q;
      i = j;
    }

    cout << ans << "\n";
  }
}