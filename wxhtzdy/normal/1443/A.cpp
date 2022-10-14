/**
 *  author: milos
 *  created: 02.11.2020 15:37:13
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
    for (int i = 2 * n; i < 4 * n; i += 2) {
      cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}