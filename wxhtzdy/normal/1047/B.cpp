/**
 *  author: milos
 *  created: 14.01.2021 23:35:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ans = max(ans, x + y);
  }
  cout << ans << '\n';
  return 0;
}