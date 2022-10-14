#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    bool ok = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == x) {
        ok = true;
      }
    }
    if (ok) {
      cout << 1 << '\n';
      continue;
    }
    int mx = *max_element(a.begin(), a.end());
    cout << max(2, (x + mx - 1) / mx) << '\n';
  }
  return 0;
}