/**
 *    author:  milos
 *    created: 22.03.2021 20:51:56       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, R, r;
  cin >> n >> R >> r;
  if (r > R) {
    cout << "NO" << '\n';
    return 0;
  }
  if (r * 2 > R) {
    if (n == 1) {
      cout << "YES" << '\n';
      return 0;
    }
    cout << "NO" << '\n';
    return 0;
  }
  double angle = 2 * asin((double) r / (R - r));
  const double eps = 1e-10;
  cout << (2 * acos(-1.0) + eps >= n * angle ? "YES" : "NO") << '\n';
  return 0;
}