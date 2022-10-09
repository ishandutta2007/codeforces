// 1311D
// cambiare gli interi in modo tale che a | b, b | c
// idee: forza bruta con bound

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, i2, k[2], k1, t, n, a, b, c, m, check1, res, a1, b1, c1, s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    res = 1000010;
    cin >> a >> b >> c;
    for (i = 1; i < 2 * a; i++) {
      for (j = i; j < 2 * b; j = j + i) {
        k[0] = (c / j) * j;
        k[1] = ((c + j - 1) / j) * j;
        for (i2 = 0; i2 < 2; i2++) {
          s = abs(a - i) + abs(b - j) + abs(c - k[i2]);
          if (s < res) {
            res = s;
            a1 = i;
            b1 = j;
            c1 = k[i2];
          }
        }
      }
    }
    cout << res << endl;
    cout << a1 << ' ' << b1 << ' ' << c1 << endl;
  }

  return 0;
}