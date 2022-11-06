#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n), c(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i] >> c[i];
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (i > 0) {
        ok &= p[i] >= p[i - 1];
        ok &= c[i] >= c[i - 1];
        ok &= c[i] - c[i - 1] <= p[i] - p[i - 1];
      }
      ok &= p[i] >= c[i];
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
}