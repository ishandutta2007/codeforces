/**
 *  author: milos
 *  created: 15.12.2020 15:44:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    if (x > 45) {
      cout << -1 << '\n';
      continue;
    }
    long long ans = 1e18;
    for (int i = 0; i < (1 << 10); i++) {
      vector<int> all;
      int sum = 0;
      for (int j = 0; j < 10; j++) {
        if ((i & (1 << j)) != 0) {
          all.push_back(j);
          sum += j;
        }
      }
      if (sum == x) {
        long long r = 0;
        for (int c : all) {
          r = r * 10 + c;
        }
        ans = min(ans, r);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}