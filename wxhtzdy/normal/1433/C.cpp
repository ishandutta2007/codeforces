#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (a[i] != mx) {
        continue;
      }
      if ((i > 0 && a[i - 1] < a[i]) || (i < n - 1 && a[i + 1] < a[i])) {
        cout << i + 1 << '\n';
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    }
  }
  return 0;
}