// 1245D
// citt con stazioni e collegamenti
// idee: esiste sempre una configurazione con la stazione o il collegamento di costo minimo

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k1, n, m, res, check1, a, b, x[2010], y[2010], c[2010], k[2010], ch, s[2010], g;
vector<long long> v;
vector<pair<long long, long long>> e;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (i = 0; i < n; i++) {
    cin >> k[i];
    s[i] = -1;
  }

  res = 0;
  for (k1 = 0; k1 < n; k1++) {
    ch = -1;
    m = 1000000000000010;
    for (i = 0; i < n; i++) {
      if (c[i] < m && c[i] != -1) {
        m = c[i];
        ch = i;
      }
    }
    res += c[ch];
    c[ch] = -1;
    for (i = 0; i < n; i++) {
      if (c[i] != -1) {
        g = (k[ch] + k[i]) * (abs(x[ch] - x[i]) + abs(y[ch] - y[i]));
        if (g < c[i]) {
          c[i] = g;
          s[i] = ch;
        }
      }
    }
  }

  cout << res << endl;

  for (i = 0; i < n; i++) {
    if (s[i] == -1) {
      v.push_back(i);
    } else {
      e.push_back({s[i], i});
    }
  }

  cout << v.size() << endl;
  for (auto u : v) {
    cout << u + 1 << ' ';
  }
  cout << endl;
  cout << e.size() << endl;
  for (auto u : e) {
    cout << u.first + 1 << ' ' << u.second + 1 << endl;
  }

  return 0;
}