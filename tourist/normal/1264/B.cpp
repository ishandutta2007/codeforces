/**
 *    author:  tourist
 *    created: 05.12.2019 17:38:01       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> a(4);
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  for (int rot = 0; rot < 2; rot++) {
    vector<int> backup_a = a;
    int even = a[0] + a[2];
    int odd = a[1] + a[3];
    if (odd == even || odd == even - 1) {
      vector<int> b(a[0] + a[1] + a[2] + a[3], - 1);
      for (int i = 0; i < (int) b.size(); i += 2) {
        if (a[0] > 0) {
          b[i] = 0;
          --a[0];
        } else {
          b[i] = 2;
          --a[2];
        }
      }
      for (int i = 1; i < (int) b.size(); i += 2) {
        if (a[1] > 0) {
          b[i] = 1;
          --a[1];
        } else {
          b[i] = 3;
          --a[3];
        }
      }                                            
      bool ok = true;
      for (int i = 0; i < (int) b.size() - 1; i++) {
        ok &= (abs(b[i] - b[i + 1]) == 1);
      }
      if (ok) {
        cout << "YES" << '\n';
        for (int i = 0; i < (int) b.size(); i++) {
          if (i > 0) {
            cout << " ";
          }
          cout << (rot == 0 ? b[i] : 3 - b[i]);
        }
        cout << '\n';
        return 0;
      }
    }
    a = backup_a;
    reverse(a.begin(), a.end());
  }
  cout << "NO" << '\n';
  return 0;
}