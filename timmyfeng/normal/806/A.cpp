#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int x, y, p, q;
    cin >> x >> y >> p >> q;

    int lo = 0;
    int hi = INT_MAX;
    long long ans = LLONG_MAX;

    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      long long res = (long long) q * mid - y;
      if (x + res >= (long long) p * mid && (long long) p * mid >= x) {
        hi = mid;
        ans = min(ans, res);
      } else {
        lo = mid + 1;
      }
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
  }
}