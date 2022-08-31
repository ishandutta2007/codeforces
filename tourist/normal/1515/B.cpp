/**
 *    author:  tourist
 *    created: 02.05.2021 17:37:24       
**/
#include <bits/stdc++.h>

using namespace std;

bool is_sqr(int x) {
  int y = (int) (sqrt(x) + 0.5);
  return y * y == x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      if (is_sqr(n / 2)) {
        cout << "YES" << '\n';
        continue;
      }
    }
    if (n % 4 == 0) {
      if (is_sqr(n / 4)) {
        cout << "YES" << '\n';
        continue;
      }
    }
    cout << "NO" << '\n';
  }
  return 0;
}