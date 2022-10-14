/**
 *    author:  milos
 *    created: 01.08.2021 07:36:51       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    if (n <= 6) {
      cout << 15 << '\n';
      continue;
    }
    if (n % 2 == 0) {
      cout << n / 2 * 5 << '\n';
    } else {
      cout << (n + 1) / 2 * 5 << '\n';
    }
  }
  return 0;
}