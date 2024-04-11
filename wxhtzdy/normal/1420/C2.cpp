#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    function<bool(int)> is_min = [&](int i) {
      return i > 0 && i + 1 < n && a[i] < a[i - 1] && a[i] < a[i + 1];
    };
    function<bool(int)> is_max = [&](int i) {
      return i >= 0 && i < n && (i == 0 || a[i] > a[i - 1]) && (i + 1 == n || a[i] > a[i + 1]);
    };
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (is_min(i)) {
        ans -= a[i];
      }
      if (is_max(i)) {
        ans += a[i];
      }
    }
    cout << ans << '\n';
    while (q--) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      vector<int> ids;
      for (int i = x - 1; i <= x + 1; i++) {
        if (i >= 0 && i < n) {
          ids.push_back(i);
        }
      }
      for (int i = y - 1; i <= y + 1; i++) {
        if (i >= 0 && i < n) {
          ids.push_back(i);
        }
      }
      sort(ids.begin(), ids.end());
      ids.erase(unique(ids.begin(), ids.end()), ids.end());
      for (int id : ids) {
        if (is_min(id)) {
          ans += a[id];
        }
        if (is_max(id)) {
          ans -= a[id];
        }
      }
      swap(a[x], a[y]);
      for (int id : ids) {
        if (is_min(id)) {
          ans -= a[id];
        }
        if (is_max(id)) {
          ans += a[id];
        }
      }
      cout << ans << '\n';
    }
  }                                                                    
  return 0;
}