/**
 *    author:  milos
 *    created: 21.02.2021 15:46:11       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  if (y == 0 || (y == 1 && x != 0)) {
    cout << "No" << '\n';
    return 0;
  }
  x -= (y - 1);
  if (x < 0) {
    cout << "No" << '\n';
    return 0;
  }
  cout << (x % 2 == 0 ? "Yes" : "No") << '\n'; 
  return 0;
}