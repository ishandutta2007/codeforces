/**
 *  author: milos
 *  created: 29.09.2020 19:28:08
**/
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
    int ans = 1e8, k = sqrt(n);
    for (int i = max(1, k - 5); i <= min(n, k + 5); i++) {
      int tmp = i - 1 + (n - 1) / i;  
      ans = min(ans, tmp);
    }
    cout << ans << '\n';
  }
  return 0;
}