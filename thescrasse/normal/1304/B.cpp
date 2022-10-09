#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, m, check1, p[110], c, check2;
string s[110];
vector<string> l, r;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m;
  check2 = 0;
  for (i = 0; i < n; i++) {
    cin >> s[i];
    p[i] = 0;
  }
  for (i = 0; i < n; i++) {
    check1 = 1;
    for (j = 0; j < m; j++) {
      if (s[i][j] != s[i][m - j - 1]) {
        check1 = 0;
      }
    }
    if (check1 == 1) {
      p[i] = 1;
    }
  }
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      check1 = 1;
      for (k = 0; k < m; k++) {
        if (s[i][k] != s[j][m - k - 1]) {
          check1 = 0;
        }
      }
      if (check1 == 1) {
        l.push_back(s[i]);
        r.push_back(s[j]);
        check2 = 1;
        p[i] = 0;
        p[j] = 0;
      }
    }
  }

  c = -1;
  for (i = 0; i < n; i++) {
    if (p[i] == 1) {
      c = i;
      break;
    }
  }

  if (c == -1) {
    cout << 2 * m * l.size() << endl;
  } else {
    cout << (2 * l.size() + 1) * m << endl;
  }
  if (check2 == 1) {
    for (i = 0; i < l.size(); i++) {
      cout << l[i];
    }
  }
  if (c != -1) {
    cout << s[c];
  }
  if (check2 == 1) {
    for (i = r.size() - 1; i >= 0; i--) {
      cout << r[i];
    }
  }
  cout << endl;

  return 0;
}