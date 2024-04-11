/**
 *    author: m371
 *    created: 09.10.2021 11:27:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x = 0;
  while (x + 1 < n && a[x + 1] > a[x]) {
    x++;
  }
  int y = n - 1;
  while (y > 0 && a[y - 1] > a[y]) {
    y--;
  }
  if (x % 2 == 0 || (n - y) % 2 == 1) {
    cout << "Alice" << '\n';
  } else {
    cout << "Bob" << '\n';
  }
  return 0;
}