/**
 *    author:  tourist
 *    created: 24.09.2020 20:27:54       
**/
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
    auto Get = [&](int i) {
      if (i < 0 || i >= n) {
        return 0;
      }
      int cur = a[i];
      int nxt = (i == n - 1 ? 0 : a[i + 1]);
      return max(cur - nxt, 0);
    };
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += Get(i);
    }
    cout << ans << '\n';
    for (int i = 0; i < q; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      if (x < y) {
        ans -= Get(x - 1);
        ans -= Get(x);
        if (x != y - 1) {
          ans -= Get(y - 1);
        }
        ans -= Get(y);
        swap(a[x], a[y]);
        ans += Get(x - 1);
        ans += Get(x);
        if (x != y - 1) {
          ans += Get(y - 1);
        }
        ans += Get(y);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}