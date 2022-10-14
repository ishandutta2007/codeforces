/**
 *  author: milos
 *  created: 06.01.2021 17:25:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int sum = a + b - c;
  if (sum < 0 || sum >= n || a < c || b < c) {
    cout << -1 << '\n';
  } else {
    cout << n - sum << '\n';
  }
  return 0;
}