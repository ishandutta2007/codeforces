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
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i];
    }
    bool ok = false;
    for (int s : {x[0] - 1, x[0], x[0] + 1}) {
      int prv = s;
      bool nok = true;
      for (int i = 1; i < n; i++) {
        if (prv == x[i] - 1) {
          prv = x[i];
        } else if (prv == x[i]) {
          prv = x[i] + 1;
        } else if (x[i] - 2 == prv) {
          prv = x[i] - 1;
        } else {
          nok = false;
        }
      }
      if (nok) {
        ok = true;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }                                                                    
  return 0;
}