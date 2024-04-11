/**
 *  author: milos
 *  created: 04.01.2021 02:17:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  int x, y;
  cin >> x >> y;
  int ans = 0;
  for (int i = x - 1; i < y - 1; i++) {
    ans += a[i];
  }
  cout << ans << '\n';
  return 0;
}