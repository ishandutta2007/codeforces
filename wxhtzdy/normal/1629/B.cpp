#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r, k;
    cin >> l >> r >> k;
    if (l == r) {
      cout << (l == 1 ? "NO" : "YES") << '\n';
      continue;
    }
    if (l % 2 == 0) l += 1;
    if (r % 2 == 0) r -= 1;
    int len = r - l + 2;
    len /= 2;
    if (len <= k) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}