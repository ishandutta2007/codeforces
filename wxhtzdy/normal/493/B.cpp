#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x, y;
  long long a = 0, b = 0;
  bool lst = true;
  for (int i = 0; i < n; i++) {
    int foo;
    cin >> foo;
    if (foo > 0) {
      x.push_back(foo);
      a += foo;
      lst = true;
    } else {
      y.push_back(abs(foo));
      b -= foo;
      lst = false;
    }
  }
  if (a > b) {
    cout << "first" << '\n';
  } else {
    if (a < b) {
      cout << "second" << '\n';
    } else {
      if ((int) x.size() == (int) y.size()) {
        for (int i = 0; i < (int) x.size(); i++) {
          if (x[i] < y[i]) {
            cout << "second" << '\n';
            return 0;
          }
          if (x[i] > y[i]) {
            cout << "first" << '\n';
            return 0;
          }
        }
        cout << (lst ? "first" : "second") << '\n';
        return 0;
      }
      bool ok = true;
      if ((int) x.size() > (int) y.size()) {
        for (int i = 0; i < (int) y.size(); i++) {
          if (x[i] < y[i]) {
            ok = false;
            break;
          }
          if (x[i] > y[i]) {
            break;
          }
        }
      } else {
        ok = false;
        for (int i = 0; i < (int) x.size(); i++) {
          if (x[i] > y[i]) {
            ok = true;
            break;
          }
          if (x[i] < y[i]) {
            break;
          }
        }
      }
      cout << (ok ? "first" : "second") << '\n';
    }
  }
  return 0;
}