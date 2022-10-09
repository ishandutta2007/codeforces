#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, g, b, f, tt, res;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    cin >> n >> g >> b;
    f = ((n + 1) / 2) / g;
    tt = g + b;
    if (((n + 1) / 2) % g != 0) {
      res = f * tt + (((n + 1) / 2) % g);
    } else {
      res = f * tt - b;
    }
    res = max(res, n);
    cout << res << endl;
  }

  return 0;
}