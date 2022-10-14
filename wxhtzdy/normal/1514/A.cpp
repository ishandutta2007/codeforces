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
    bool ok = false;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int y = sqrt(x);
      if (y * y != x) {
        ok = true;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}