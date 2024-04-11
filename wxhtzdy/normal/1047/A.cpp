/**
 *  author: milos
 *  created: 14.01.2021 23:15:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 3 == 2) {
    cout << n - 3 << " " << 2 << " " << 1 << '\n';
  } else {
    cout << n - 2 << " " << 1 << " " << 1 << '\n';
  }
  return 0;
}