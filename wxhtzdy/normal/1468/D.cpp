#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> niz(m);
    for (int i = 0; i < m; i++) {
      cin >> niz[i];
    }
    sort(niz.begin(), niz.end());
    auto Check = [&](int x) {
      if (x >= abs(a - b)) {
        return false;
      }
      int y = abs(a - b);
      if (a < b) {
        y += a - 1;
      } else {
        y += n - a;
      }
      for (int i = 0; i < x; i++) {
        if (niz[i] + x - i > y) {
          return false;
        }
      }
      return true;
    };
    int bot = 1, top = m, ans = 0;
    while (bot <= top) {
      int mid = bot + top >> 1;
      if (Check(mid)) {
        ans = mid;
        bot = mid + 1;
      } else {
        top = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}