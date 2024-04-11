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

    vector<long long> d(n);
    for (auto &i : d) {
      cin >> i;
    }

    bool ok = true;
    sort(d.begin(), d.end());
    long long ans = d[0] * d[n - 1];
    for (int i = 0; i < n; ++i) {
      ok &= (d[i] * d[n - 1 - i] == ans);
    }

    int c = 0;
    for (long long i = 2; i * i <= ans; ++i) {
      if (ans % i == 0) {
        c += 1 + (i * i < ans);
      }
    }
    ok &= (c == n);

    cout << (ok ? ans : -1) << "\n";
  }
}