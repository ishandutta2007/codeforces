/**
 *    author:  milos
 *    created: 29.01.2021 15:35:19       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    if (n < k) {
      cout << k / n + (k % n != 0 ? 1 : 0) << '\n';
      continue;
    }
    cout << (n % k == 0 ? 1 : 2) << '\n';
  }
  return 0;
}