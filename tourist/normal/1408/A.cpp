/**
 *    author:  tourist
 *    created: 30.09.2020 17:35:20       
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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
      p[i] = a[i];
      if (p[i] == p[(i + 1) % n] || p[i] == p[(i + n - 1) % n]) {
        p[i] = b[i];
        if (p[i] == p[(i + 1) % n] || p[i] == p[(i + n - 1) % n]) {
          p[i] = c[i];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << p[i];
    }
    cout << '\n';
  }
  return 0;
}