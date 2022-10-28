#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
      --i;
    }

    int k = n - 1;
    for ( ; k >= 0 && a[k] == k; --k);

    double ans = (k >= 0);
    while (m--) {
      int r;
      double p;
      cin >> r >> p;
      if (r > k) {
        ans *= 1.0 - p;
      }
    }

    cout << 1.0 - ans << "\n";
  }
}