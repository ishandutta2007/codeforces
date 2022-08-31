/**
 *    author:  tourist
 *    created: 25.08.2019 17:33:16       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, n;
    cin >> a >> b >> n;
    n %= 3;
    if (n == 0) cout << a << '\n'; else
    if (n == 1) cout << b << '\n';
    else cout << (a ^ b) << '\n';
  }
  return 0;
}