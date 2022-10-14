/**
 *    author:  milos
 *    created: 21.09.2021 08:59:18       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int mn = a + b + c - 1 - 2 * (a + b + c - max({a, b, c}));
    int mx = a + b + c - 3;
    cout << (mn <= m && m <= mx ? "YES" : "NO") << '\n';
  }
  return 0;
}