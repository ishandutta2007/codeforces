#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, a, b, g, res, er[100010];

long long gcdv(long long x, long long y) {
  if (x == y) {
    return x;
  } else if (x > y) {
    return gcdv(((x - 1) % y) + 1, y);
  } else {
    return gcdv(x, ((y - 1) % x) + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  for (i = 2; i < 100010; i++) {
    er[i] = 0;
  }

  for (i = 2; i < 100010; i++) {
    if (er[i] == 0) {
      for (j = 2 * i; j < 100010; j = j + i) {
        er[j] = 1;
      }
    }
  }

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    cin >> a >> b;
    g = gcdv(a, b);
    a /= g;
    b /= g;
    res = b;
    k = b;
    for (i = 2; i <= sqrt(k); i++) {
      if (er[i] == 0) {
        if (b % i == 0) {
          while (b % i == 0) {
            b = b / i;
          }
          res = res / i;
          res = res * (i - 1);
        }
      }
    }

    if (b > sqrt(k)) {
      res = res / b;
      res = res * (b - 1);
    }

    cout << res << endl;
  }

  return 0;
}