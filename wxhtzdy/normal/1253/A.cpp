/**
 *  author: milos
 *  created: 07.01.2021 16:45:27
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    bool was = false;
    bool ok = true;
    int diff = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        if (was && a[i - 1] - b[i - 1] != a[i] - b[i]) {
          ok = false;
        }
        was = true;
      }
      if (a[i] > b[i]) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}