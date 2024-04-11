#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, c, bsu, bsl, bsm, res, ch;
string a, b;
map<char, vector<long long>> pos;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    pos.clear();
    ch = 0;
    res = 1;
    cin >> a >> b;
    for (i = 0; i < a.size(); i++) {
      pos[a[i]].push_back(i);
    }
    c = -1;
    for (i = 0; i < b.size(); i++) {
      if (pos[b[i]].size() == 0) {
        ch = -1;
        continue;
      }
      bsu = pos[b[i]].size() - 1;
      bsl = 0;
      while (bsu != bsl) {
        bsm = (bsu + bsl) / 2;
        if (pos[b[i]][bsm] > c) {
          bsu = bsm;
        } else {
          bsl = bsm + 1;
        }
      }
      if (bsu != pos[b[i]].size() - 1) {
        c = pos[b[i]][bsu];
      } else if (pos[b[i]][pos[b[i]].size() - 1] > c) {
        c = pos[b[i]][bsu];
      } else {
        c = pos[b[i]][0];
        res++;
      }
      // cout << c << ' ';
    }
    // cout << endl;
    if (ch == -1) {
      cout << -1 << endl;
    } else {
      cout << res << endl;
    }
    // cout << endl;
  }
  return 0;
}