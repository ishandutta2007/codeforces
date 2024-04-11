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
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }

    bool ok = false;
    for (int i = 0; i < n; ++i) {
      int res = 0;
      for (int j = 0; j < n; ++j) {
        res = max(res, abs(x[i] - x[j]) + abs(y[i] - y[j]));
      }
      ok |= (res <= k);
    }

    cout << (ok ? 1 : -1) << "\n";
  }
}