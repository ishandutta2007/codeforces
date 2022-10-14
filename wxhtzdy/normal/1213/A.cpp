/**
 *  author: milos
 *  created: 16.12.2020 01:42:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      x++;
    } else {
      y++;
    }
  }
  cout << min(x, y) << '\n';
  return 0;
}