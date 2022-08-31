/**
 *    author:  tourist
 *    created: 23.11.2021 17:35:00       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
      cout << 0 << '\n';
      continue;
    }
    if (n == 1 || m == 1) {
      cout << 1 << '\n';
      continue;
    }
    cout << 2 << '\n';
  }
  return 0;
}