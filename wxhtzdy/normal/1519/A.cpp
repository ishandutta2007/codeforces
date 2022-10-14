/**
 *    author:  milos
 *    created: 29.04.2021 19:35:44       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long r, b, d;
    cin >> r >> b >> d;
    if (r > b) {
      swap(r, b);
    }
    cout << (r * d >= b - r ? "YES" : "NO") << '\n';
  }
  return 0;
}