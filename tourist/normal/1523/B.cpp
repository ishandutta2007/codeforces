/**
 *    author:  tourist
 *    created: 30.05.2021 17:40:11       
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
    for (int i = 0; i < n; i++) {
      int foo;
      cin >> foo;
    }
    cout << 3 * n << '\n';
    for (int i = 1; i <= n; i += 2) {
      cout << "1 " << i << " " << i + 1 << '\n';
      cout << "2 " << i << " " << i + 1 << '\n';
      cout << "1 " << i << " " << i + 1 << '\n';
      cout << "2 " << i << " " << i + 1 << '\n';
      cout << "1 " << i << " " << i + 1 << '\n';
      cout << "2 " << i << " " << i + 1 << '\n';
    }
  }
  return 0;
}