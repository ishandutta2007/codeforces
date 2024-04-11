/**
 *    author:  tourist
 *    created: 25.01.2021 18:01:09       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    while (n >= 2020 && n % 2021 != 0) {
      n -= 2020;
    }
    cout << (n % 2021 == 0 ? "YES" : "NO") << '\n';
  }
  return 0;
}