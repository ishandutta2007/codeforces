/**
 *  author: milos
 *  created: 04.01.2021 15:38:43
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        x += 1;
      } else {
        y += 1;
      }
    }
    y %= 2;
    if (y == 0) {
      if (x % 2 == 0) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    } else {
      if (x <= 1) {
        cout << "NO" << '\n';
      } else {
        x -= 2;
        if (x % 2 == 0) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
      }
    }
  }
  return 0;
}