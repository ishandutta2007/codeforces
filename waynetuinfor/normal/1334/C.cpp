#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
      c[(i + 1) % n] = max(0LL, a[(i + 1) % n] - b[i]);
    }
    int64_t k = 1e18;
    for (int i = 0; i < n; ++i) k = min(k, a[i] - c[i]);
    int64_t res = k;
    for (int i = 0; i < n; ++i) res += c[i];
    cout << res << "\n";
  }
}