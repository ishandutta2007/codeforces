#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, res, a[40], b, check1, s, c;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    s = 0;
    cin >> n >> k1;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    k = 1;
    c = 0;
    while (s != 0) {
      c = 0;
      for (i = 0; i < n; i++) {
        if (a[i] % (k * k1) == 0) {
          continue;
        } else if (a[i] % (k * k1) == k) {
          c++;
          a[i] -= k;
          s -= k;
        } else {
          c = 2;
        }
        if (c == 2) {
          s = 0;
          break;
        }
      }
      k *= k1;
    }
    if (c == 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}