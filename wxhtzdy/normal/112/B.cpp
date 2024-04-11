/**
 *  author: milos
 *  created: 13.12.2020 16:35:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  if (n == 2) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << ((x == n / 2 || x == n / 2 + 1) && (y == n / 2 || y == n / 2 + 1) ? "NO" : "YES") << '\n'; 
  return 0;
}