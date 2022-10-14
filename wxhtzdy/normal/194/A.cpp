/**
 *  author: milos
 *  created: 13.12.2020 18:53:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  cout << max(0, 3 * n - k) << '\n';
  return 0;
}