#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, x, y, l, r, xp, yp, res, check1;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> s >> x >> y;
  xp = 0;
  yp = 0;
  l = 0;
  r = -1;
  res = 6942069420;
  check1 = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == 'U') {
      y--;
    } else if (s[i] == 'L') {
      x++;
    } else if (s[i] == 'D') {
      y++;
    } else if (s[i] == 'R') {
      x--;
    }
  }
  if (x == 0 && y == 0) {
    cout << 0;
    return 0;
  }
  if ((x + y) % 2 != 0) {
    cout << -1;
    return 0;
  }
  while (r < n - 1) {
    while (check1 == 0 && r < n - 1) {
      r++;
      if (s[r] == 'U') {
        yp--;
      } else if (s[r] == 'L') {
        xp++;
      } else if (s[r] == 'D') {
        yp++;
      } else if (s[r] == 'R') {
        xp--;
      }
      if (abs(xp - x) + abs(yp - y) <= r - l + 1) {
        res = min(res, r - l + 1);
        check1 = 1;
      }
      // cout << l << ' ' << r << ' ' << xp << ' ' << x << ' ' << yp << ' ' << y << endl;
    }
    while (check1 == 1 && l < r) {
      if (s[l] == 'U') {
        yp++;
      } else if (s[l] == 'L') {
        xp--;
      } else if (s[l] == 'D') {
        yp--;
      } else if (s[l] == 'R') {
        xp++;
      }
      l++;
      if (abs(xp - x) + abs(yp - y) <= r - l + 1) {
        res = min(res, r - l + 1);
      } else if (abs(xp - x) + abs(yp - y) > r - l + 1) {
        check1 = 0;
      }
      // cout << l << ' ' << r << ' ' << res << endl;
    }
    check1 = 0;
  }

  if (res == 6942069420) {
    res = -1;
  }
  cout << res;

  return 0;
}