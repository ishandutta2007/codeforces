#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  vector<int> ans(n + 1);
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    while (true) {
      auto it = s.lower_bound(l);
      if (it == s.end()) {
        break;
      }
      int pos = *it;
      if (pos < l || pos > r) {
        break;
      }
      ans[pos] = x;
      s.erase(it);
    }
    s.insert(x);
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] == i) {
      ans[i] = 0;
    }
    cout << ans[i] << " ";
  }
  return 0;
}