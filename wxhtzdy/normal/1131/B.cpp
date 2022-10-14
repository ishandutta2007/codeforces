/**
 *  author: milos
 *  created: 15.01.2021 03:56:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int ans = min(a[0], b[0]) + 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1] && b[i] == b[i - 1]) {
      continue;
    }
    ans += max(0, min(a[i], b[i]) - max(a[i - 1], b[i - 1]) + 1);
    if (a[i - 1] == b[i - 1]) {
      ans--;
    }
  }
  cout << ans << '\n';
  return 0;
}