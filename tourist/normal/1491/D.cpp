/**
 *    author:  tourist
 *    created: 28.02.2021 16:50:18       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    vector<int> bx;
    vector<int> by;
    for (int bit = 0; bit < 30; bit++) {
      if (x & (1 << bit)) {
        bx.push_back(bit);
      }
      if (y & (1 << bit)) {
        by.push_back(bit);
      }
    }
    bool ok = true;
    if (bx.size() < by.size()) {
      ok = false;
    } else {
      for (int i = 0; i < (int) by.size(); i++) {
        if (bx[i] > by[i]) {
          ok = false;
        }
      }
    }
    ok &= (x <= y);
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}