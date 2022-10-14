/**
 *    author:  milos
 *    created: 17.03.2021 15:56:29       
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
    for (int i = 0; i < k - 3; i++) {
      cout << 1 << " ";
    }
    n -= (k - 3);
    if (n % 2 == 1) {
      cout << 1 << " " << (n - 1) / 2 << " " << (n - 1) / 2 << '\n';
    } else {
      if (n % 4 == 0) {
        cout << n / 2 << " " << n / 4 << " " << n / 4 << '\n';
      } else {
        cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2 << '\n';  
      }
    }
  }
  return 0;
}