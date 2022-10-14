/**
 *    author:  milos
 *    created: 08.02.2021 11:18:44       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, x, y, z, p;
  cin >> n >> m >> x >> y >> z >> p;
  x %= 4, y %= 2, z %= 4; 
  for (int i = 0; i < p; i++) {
    int a, b;
    cin >> a >> b;
    int md = 0;
    for (int j = 0; j < x; j++) {
      if (md == 0) {
        a = n - a + 1;
      } else {
        b = m - b + 1;
      }
      md ^= 1;
    }
    for (int j = 0; j < y; j++) {
      if (md == 0) {
        b = m - b + 1;
      } else {
        a = n - a + 1;
      }
    }              
    for (int j = 0; j < z; j++) {
      for (int rot = 0; rot < 3; rot++) {
        if (md == 0) {
          a = n - a + 1;
        } else {
          b = m - b + 1;
        }
        md ^= 1;
      }
    }
    if (md) {
      swap(a, b);
    }
    cout << a << " " << b << '\n';
  }
  return 0;
}