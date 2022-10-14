/**
 *  author: milos
 *  created: 15.12.2020 07:48:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a(4);
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  int bal = a[0] * 2 - a[3] * 2;
  if (a[0] == 0 && a[2] > 0) bal--;
  cout << (bal == 0 ? 1 : 0) << '\n';
  return 0;
}