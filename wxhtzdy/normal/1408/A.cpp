/**
 *  author: milos
 *  created: 30.09.2020 21:29:50
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
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    vector<int> p = a;
    for (int i = 0; i < n; i++) {
      if (p[i] == p[(i + 1) % n]) {
        p[i] = b[i];
        int k = i - 1;
        if (k == -1) k = n - 1;
        if (p[i] == p[k]) {
          p[i] = c[i];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << p[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}