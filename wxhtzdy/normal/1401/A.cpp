/**
 *  author: milos
 *  created: 04.01.2021 04:02:12
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
    if (n <= k) {
      cout << k - n << '\n';
    } else {
      cout << (n + k) % 2 << '\n';
    }
  }
  return 0;
}