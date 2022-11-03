#include <bits/stdc++.h>

using namespace std;

string res[256][3];
bool changed;

void update(string &a, string &b) {
  if (a == "" || (b.length() < a.length() || (b.length() == a.length() && b < a))) {
    changed = true;
    a = b;
  }
}

int main() {
  res[(1 << 4) + (1 << 5) + (1 << 6) + (1 << 7)][0] = "x";
  res[(1 << 2) + (1 << 3) + (1 << 6) + (1 << 7)][0] = "y";
  res[(1 << 1) + (1 << 3) + (1 << 5) + (1 << 7)][0] = "z";
  changed = true;
  while (changed) {
    changed = false;
    for (int i = 0; i < 256; i++) {
      for (int j = 0; j < 3; j++) {
        if (res[i][j] == "") {
          continue;
        }
        { // op == 0
          string s = res[i][j];
          if (j > 0) {
            s = "(" + s + ")";
          }
          s = "!" + s;
          update(res[i ^ 255][0], s);
        }
        for (int ii = 0; ii < 256; ii++) {
          for (int jj = 0; jj < 3; jj++) {
            if (res[ii][jj] == "") {
              continue;
            }
            for (int op = 1; op <= 2; op++) {
              string s = res[i][j];
              if (j >= op) {
                s = "(" + s + ")";
              }
              string t = res[ii][jj];
              if (jj > op) {
                t = "(" + t + ")";
              }
              string w = s + (op == 1 ? '&' : '|') + t;
              update(res[op == 1 ? (i & ii) : (i | ii)][op], w);
            }
          }
        }
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    string z;
    cin >> z;
    int mask = 0;
    for (int i = 0; i < 8; i++) {
      mask |= (z[i] - '0') << i;
    }
    string best = "";
    for (int j = 0; j < 3; j++) {
      update(best, res[mask][j]);
    }
    cout << best << endl;
  }
  return 0;
}