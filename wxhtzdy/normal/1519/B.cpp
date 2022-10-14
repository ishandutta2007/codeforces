/**
 *    author:  milos
 *    created: 29.04.2021 19:37:46       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    cout << (k == n * m - 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}