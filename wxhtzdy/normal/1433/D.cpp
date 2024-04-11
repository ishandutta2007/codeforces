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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (a[i] != a[0]) {
        ok = true;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    vector<int> c, d;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[0]) {
        c.push_back(i);
      } else {
        d.push_back(i);
      }
    }
    int j = 0, k = 0;
    for (int i = 0; i < n - 1; i++) {
      if (j < (int) d.size()) {
        cout << 1 << " " << d[j] + 1 << '\n';
        j++;
      } else {
        cout << d[0] + 1 << " " << c[k] + 1 << '\n';
        k++;
      }
    }
  }
  return 0;
}