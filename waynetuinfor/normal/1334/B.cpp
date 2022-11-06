#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int64_t s = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      s += a[i];
      if (s >= 1LL * (i + 1) * x) res = i + 1;
    }
    cout << res << "\n";
  }
}