#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<long long> p(n);
    for (auto &i : p) {
      cin >> i;
    }

    long long l = 0, r = 1000000000000LL;
    while (l < r) {
      long long m = (l + r) / 2;

      bool ok = true;
      long long x = p[0] + m;
      for (int i = 1; i < n; ++i) {
        ok &= (100 * p[i] <= k * x);
        x += p[i];
      }

      if (ok) {
        r = m;
      } else {
        l = m + 1;
      }
    }

    cout << l << "\n";
  }
}