#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    long long n, k, l1, r1, l2, r2;
    cin >> n >> k >> l1 >> r1 >> l2 >> r2;

    long long all = max(r1, r2) - min(l1, l2);
    long long none = max(l1, l2) - min(r1, r2);

    if (all == 0) {
      cout << 2 * k << "\n";
      continue;
    }

    if (none < 0) {
      k = max(0LL, k + none * n);
      all += none;

      if (k <= all * n) {
        cout << k << "\n";
      } else {
        cout << all * n + (k - all * n) * 2 << "\n";
      }
    } else {
      if (k <= all) {
        cout << none + k << "\n";
      } else if (k > all * n) {
        cout << (all + none) * n + (k - all * n) * 2 << "\n";
      } else {
        long long a = k / all * (all + none);
        long long b = min(k % all * 2, none + k % all);
        cout << a + b << "\n";
      }
    }
  }
}