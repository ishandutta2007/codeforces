#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    bool ok = true;
    set<int> s;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      for (int j = 0; a[i] > 0; ++j) {
        if (a[i] % k > 1) {
          ok = false;
          break;
        }
        if (a[i] % k == 1) {
          if (s.count(j)) ok = false;
          s.insert(j);
        }
        a[i] /= k;
      }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
}