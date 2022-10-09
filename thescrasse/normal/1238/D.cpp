#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, a, b, l, r, ta, tb, ta1, tb1;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> s;
  res = 0;
  l = 0;
  r = -1;
  a = 0;
  b = 0;
  ta = 0;
  tb = 0;

  for (i = 0; i < n; i++) {
    if (s[i] == 'A') {
      ta++;
    } else {
      tb++;
    }
  }

  ta1 = ta;
  tb1 = tb;

  while (r < n) {
    if (a >= 2 && b >= 2) {
      if (s[l] == 'A') {
        res += tb;
      } else {
        res += ta;
      }
      // cout << res << endl;
      l++;
      if (s[l - 1] == 'A') {
        a--;
      } else {
        b--;
      }
    } else {
      r++;
      if (r == n) {
        break;
      }
      if (s[r] == 'A') {
        a++;
      } else {
        b++;
      }
      if (r != 0) {
        if (s[r - 1] == 'A') {
          ta--;
        } else {
          tb--;
        }
      }
      // cout << ta << ' ' << tb << endl;
    }
  }

  res = res + ta1 * (ta1 - 1) / 2 + tb1 * (tb1 - 1) / 2;

  cout << res << endl;

  return 0;
}