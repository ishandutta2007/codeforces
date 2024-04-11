/**
 *  author: milos
 *  created: 11.12.2020 00:31:04
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
    vector<int> a(n);
    long long x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      x = x + a[i];
      y = y ^ a[i];
    }
    cout << 2 << '\n' << y << " " << x + y << '\n';
  }
  return 0;
}