/**
 *    author:  milos
 *    created: 10.02.2021 08:29:48       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << a * 10 << " " << b * 10 + 1 << '\n';
  } else {
    if (a == b - 1) {
      cout << a << " " << b << '\n';
    } else {
      if (a == 9 && b == 1) {
        cout << a << " " << 10 << '\n';
      } else {
        cout << -1 << '\n';
      }
    }
  }
  return 0;
}