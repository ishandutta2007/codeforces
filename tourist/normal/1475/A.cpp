/**
 *    author:  tourist
 *    created: 25.01.2021 17:59:10       
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
    while (n % 2 == 0) {
      n /= 2;
    }
    cout << (n == 1 ? "NO" : "YES") << '\n';
  }
  return 0;
}