/**
 *  author: milos
 *  created: 04.01.2021 15:46:40
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
    sort(a.rbegin(), a.rend());
    long long x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (a[i] % 2 == 0) {
          x += a[i];
        }
      } else {
        if (a[i] % 2 == 1) {
          y += a[i];
        }
      }
    }
    if (x == y) {
      cout << "Tie" << '\n';
    } else {
      if (x > y) {
        cout << "Alice" << '\n';
      } else {
        cout << "Bob" << '\n';
      }
    }
  }
  return 0;
}