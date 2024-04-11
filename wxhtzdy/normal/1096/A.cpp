/**
 *    author:  milos
 *    created: 09.08.2021 21:36:48       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;
    cout << r / 2 << " " << r - r % 2 << '\n';
  }
  return 0;
}