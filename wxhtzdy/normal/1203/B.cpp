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
    vector<long long> a(4 * n);
    for (int i = 0; i < 4 * n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[2 * i] != a[2 * i + 1] || a[4 * n - 2 * i - 2] != a[4 * n - 2 * i - 1] || a[2 * i] * a[4 * n - i * 2 - 1] != a[0] * a[4 * n - 1]) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}