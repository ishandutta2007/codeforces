#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int lst = 0, mn = m, mx = m;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int t, l, r;
      cin >> t >> l >> r;
      int can_add = t - lst;
      mn -= can_add;
      mx += can_add;
      if (l > mx || r < mn) {
        ok = false;
      }
      mn = max(mn, l);
      mx = min(mx, r);
      lst = t;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}