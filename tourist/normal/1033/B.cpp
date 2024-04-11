/**
 *    author:  tourist
 *    created: 07.10.2018 20:07:38       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b;
    cin >> a >> b;
    if (a - b > 1) {
      cout << "NO" << '\n';
      continue;
    }
    long long x = a + b;
    bool prime = (x >= 2);
    for (long long i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        prime = false;
        break;
      }
    }
    cout << (prime ? "YES" : "NO") << '\n';
  }
  return 0;
}