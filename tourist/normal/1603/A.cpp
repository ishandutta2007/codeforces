/**
 *    author:  tourist
 *    created: 30.10.2021 17:35:01       
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
    while (n > 0) {
      int i = n - 1;
      while (i >= 0 && a[i] % (i + 2) == 0) {
        i -= 1;
      }
      if (i < 0) {
        break;
      }
      a.erase(a.begin() + i);
      n -= 1;
    }
    cout << (n == 0 ? "YES" : "NO") << '\n';
  }
  return 0;
}