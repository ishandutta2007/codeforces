/**
 *  author: milos
 *  created: 15.01.2021 03:15:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());
  cout << max(0, a[2] - (a[0] + a[1] - 1)) << '\n';
  return 0;
}