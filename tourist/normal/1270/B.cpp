/**
 *    author:  tourist
 *    created: 29.12.2019 17:06:52       
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
    bool found = false;
    for (int i = 0; i < n - 1; i++) {
      if (abs(a[i] - a[i + 1]) > 1) {
        cout << "YES" << '\n';
        cout << i + 1 << " " << i + 2 << '\n';
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "NO" << '\n';
    }
  }
  return 0;
}