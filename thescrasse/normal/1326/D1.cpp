#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a[200010], mod, st, nd, l, r;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
      cin >> s;
      n = s.size();
      i = 0;
      while (2 * i < n) {
          if (s[i] != s[n - i - 1]) {
              break;
          }
          i++;
      }
      check1 = 0;
      st = i;
      nd = n - i - 1;
      // cout << st << ' ' << nd << endl;
      if (nd - st <= -1) {
          cout << s << endl;
          continue;
      }
      res = 0;
      l = st;
      r = nd;
      while (l < r) {
          // cout << l << ' ' << r << endl;
          // res = max(res, r - st);
          if (s[l] == s[r]) {
              l++;
              r--;
          } else {
              r = l + r - st - 1;
              l = st;
          }
      }
      res = l + r - 2 * st + 1;
      // cout << res << endl;

      st = i;
      nd = n - i - 1;
      l = st;
      r = nd;
      while (l < r) {
          /* if (nd - r > res) {
              check1 = 1;
          }
          res = max(res, nd - l); */
          if (s[l] == s[r]) {
              l++;
              r--;
          } else {
              l = l + r - nd + 1;
              r = nd;
          }
      }
      if (2 * nd - l - r + 1 > res) {
          check1 = 1;
          res = 2 * nd - l - r + 1;
      }
      /* res *= 2;
      if (l - r == 1) {
          res++;
      } */
      // cout << res << endl;
      for (i = 0; i < st; i++) {
          cout << s[i];
      }
      if (check1 == 0) {
          for (i = st; i < st + res; i++) {
              cout << s[i];
          }
      } else {
          for (i = nd - res + 1; i <= nd; i++) {
              cout << s[i];
          }
      }
      for (i = nd + 1; i < n; i++) {
          cout << s[i];
      }
      cout << endl;
  }

  return 0;
}