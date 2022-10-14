#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int cnt = 0;
    while (x > 0) {
      if (x % 10 == 4 || x % 10 == 7) {
        cnt++;
      }
      x /= 10;
    }
    if (cnt <= k) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}