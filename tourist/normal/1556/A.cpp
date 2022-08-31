/**
 *    author:  tourist
 *    created: 29.08.2021 17:34:38       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long c, d;
    cin >> c >> d;
    if (c % 2 != d % 2) {
      cout << -1 << '\n';
      continue;
    }
    cout << (c == 0 && d == 0 ? 0 : (c == d ? 1 : 2)) << '\n';
  }
  return 0;
}