/**
 *    author:  tourist
 *    created: 14.09.2019 16:09:30       
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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = (int) (s[i] - '0');
    }
    bool found = false;
    for (int split = 0; split <= 9; split++) {
      vector<int> color(n, 0);
      int max1 = -1;
      for (int i = 0; i < n; i++) {
        if (a[i] < split) {
          color[i] = 1;
          max1 = max(max1, i);
        }
        if (a[i] > split) {
          color[i] = 2;
        }
      }
      for (int i = 0; i < n; i++) {
        if (a[i] == split) {
          if (i > max1) {
            color[i] = 1;
          } else {
            color[i] = 2;
          }
        }
      }
      int last = -1;
      bool ok = true;
      for (int r = 1; r <= 2; r++) {
        for (int i = 0; i < n; i++) {
          if (color[i] == r) {
            if (a[i] < last) {
              ok = false;
            }
            last = a[i];
          }
        }
      }
      if (ok) {
        for (int i = 0; i < n; i++) {
          cout << color[i];
        }
        cout << '\n';
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "-" << '\n';
    }
  }
  return 0;
}