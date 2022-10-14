/**
 *  author: milos
 *  created: 13.12.2020 18:17:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> can;
  for (int i = 1; (i * (i + 1) / 2) <= n; i++) {
    can[i * (i + 1) / 2] = 1;
  }
  for (int i = 1; (i * (i + 1) / 2) <= n; i++) {
    if (can[n - (i * (i + 1) / 2)] == 1) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
  return 0;
}