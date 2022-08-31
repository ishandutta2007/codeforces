/**
 *    author:  tourist
 *    created: 02.05.2021 17:36:11       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }
    bool ok = true;
    int s = 0;
    for (int i = 0; i < n; i++) {
      s += w[i];
      if (s == x) {
        if (i == n - 1) {
          ok = false;
          break;
        }
        swap(w[i], w[i + 1]);
        break;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << w[i];
      }
      cout << '\n';
    }
  }
  return 0;
}