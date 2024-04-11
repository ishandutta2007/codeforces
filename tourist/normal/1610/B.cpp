/**
 *    author:  tourist
 *    created: 23.11.2021 17:37:21       
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
    if (a == vector<int>(a.rbegin(), a.rend())) {
      cout << "YES" << "\n";
      continue;
    }
    bool ok = false;
    auto Test = [&](int x) {
      vector<int> b;
      for (int i = 0; i < n; i++) {
        if (a[i] != x) {
          b.push_back(a[i]);
        }
      }
      ok |= (b == vector<int>(b.rbegin(), b.rend()));
    };
    for (int i = 0; i < n; i++) {
      if (a[i] != a[n - 1 - i]) {
        Test(a[i]);
        Test(a[n - 1 - i]);
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}