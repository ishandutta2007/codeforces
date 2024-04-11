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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n >= 2 * x) {
      cout << "YES" << '\n';
      continue;
    }
    vector<int> c;
    vector<bool> was(n, false);
    for (int i = 0; i < n - x; i++) {
      c.push_back(a[i]);
      c.push_back(a[n - i - 1]);
      was[i] = true;
      was[n - i - 1] = true;
    }
    sort(c.begin(), c.end());
    auto b = a;
    for (int i = 0, j = 0; i < n; i++) {
      if (was[i]) {
        b[i] = c[j++];
      }
    }
    cout << (is_sorted(b.begin(), b.end()) ? "YES" : "NO") << '\n';
  }
  return 0;
}