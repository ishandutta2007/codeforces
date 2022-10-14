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
    m++;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      int bit = (1 << i);
      if ((n & bit) == (m & bit)) continue;
      if ((n & bit) > (m & bit)) break;
      ans += bit;
    }
    cout << ans << "\n";
  }
  return 0;
}