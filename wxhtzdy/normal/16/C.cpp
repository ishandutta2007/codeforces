/**
 *    author:  milos
 *    created: 28.01.2021 07:52:56       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int g = __gcd(x, y);
  x /= g, y /= g;
  int c = min(a / x, b / y);
  cout << x * c << " " << y * c << '\n';
  return 0;
}