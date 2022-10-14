/**
 *  author: milos
 *  created: 08.01.2021 12:53:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << 1 << '\n';
    return 0;
  }
  if (n == m) {
    cout << 0 << '\n';
    return 0;
  }
  if (m <= n / 2) {
    cout << m << '\n';
  } else {
    cout << n - m << '\n';
  }
  return 0;
}