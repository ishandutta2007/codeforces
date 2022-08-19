/**
 *    author:  tourist
 *    created: 30.07.2021 17:34:28       
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
    while (n < 6 || n % 2 != 0) {
      n += 1;
    }
    cout << n / 2 * 5 << '\n';
  }
  return 0;
}