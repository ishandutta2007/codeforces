#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<long long> a(2 * n);
    for (auto &i : a) {
      cin >> i;
    }
    sort(a.begin(), a.end());

    bool ok = true;
    long long diff = 0, sum = 0;
    for (int i = 0; i < n && ok; ++i) {
      ok &= (a[2 * i] == a[2 * i + 1]);
      ok &= (a[2 * i] % 2 == 0);

      if (i > 0) {
        long long d = a[2 * i] - a[2 * i - 1];
        ok &= (d % (2 * i) == 0 && d > 0);
        diff += d / (2 * i);
        sum += diff;
      }
    }

    ok &= (a[0] / 2 > sum && (a[0] / 2 - sum) % n == 0);

    cout << (ok ? "YES" : "NO") << "\n";
  }
}