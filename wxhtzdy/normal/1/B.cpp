#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    vector<int> a;
    int x = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        x *= 10;
        x += (int) (s[i] - '0');
      } else {
        if (x != 0) {
          a.push_back(x);
          x = 0;
        }
      }
    }
    if (x != 0) {
      a.push_back(x);
      x = 0;
    }
    assert((int) a.size() == 1 || (int) a.size() == 2);
    if ((int) a.size() == 1) {
      string row = "";
      for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
          break;
        } else {
          row += s[i];
        }
      }
      reverse(row.begin(), row.end());
      int r = 0, pw = 1;
      for (int i = 0; i < (int) row.size(); i++) {
        r += (int) (row[i] - 'A' + 1) * pw;
        pw *= 26;
      }
      cout << 'R' << a[0] << 'C' << r << '\n';
    } else {
      string row = "";
      while (a[1] > 0) {
        int p = a[1] % 26;
        if (p == 0) {
            p = 26;
            a[1]--;
        }
        row += (char) ('A' + p - 1);
        a[1] /= 26;
      }
      reverse(row.begin(),row.end());
      cout << row << a[0] << '\n';
    }
  }
  return 0;
}