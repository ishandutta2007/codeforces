#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a[100010], b;
map<long long, long long> f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
      cin >> n;
      res = 0;
      f.clear();
      for (i = 0; i < n; i++) {
          cin >> b;
          f[b]++;
          if (f[b] == 1) {
              res++;
          }
      }
      cout << res << endl;
  }

  return 0;
}