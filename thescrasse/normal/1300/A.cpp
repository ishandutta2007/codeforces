#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, c, res, a[110], s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    res = 0;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < n; i++) {
      if (a[i] == 0) {
        a[i] = 1;
        res++;
      }
    }
    s = 0;
    for (i = 0; i < n; i++) {
      s += a[i];
    }
    if (s == 0) {
      res++;
    }
    cout << res << endl;
  }

  return 0;
}