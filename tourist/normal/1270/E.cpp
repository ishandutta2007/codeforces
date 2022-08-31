/**
 *    author:  tourist
 *    created: 29.12.2019 17:09:49       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    x[i] -= x[0];
    y[i] -= y[0];
  }
  while (true) {
    vector<int> ret;
    for (int i = 1; i < n; i++) {
      if ((x[i] + y[i]) % 2 != 0) {
        ret.push_back(i);
      }
    }
    if (!ret.empty()) {
      cout << (int) ret.size() << '\n';
      for (int i = 0; i < (int) ret.size(); i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << ret[i] + 1;
      }
      cout << '\n';
      return 0;
    }
    for (int i = 1; i < n; i++) {
      if (x[i] % 2 != 0) {
        ret.push_back(i);
      }
    }
    if (!ret.empty()) {
      cout << (int) ret.size() << '\n';
      for (int i = 0; i < (int) ret.size(); i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << ret[i] + 1;
      }
      cout << '\n';
      return 0;
    }
    for (int i = 0; i < n; i++) {
      x[i] /= 2;
      y[i] /= 2;
    }
  }
  return 0;
}