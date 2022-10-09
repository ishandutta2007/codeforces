#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a[200010], mod, sm;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  mod = 998244353;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
      cin >> a[i];
  }

  res = 1;
  j = -1;
  for (i = 0; i < n; i++) {
      //cout << i << ' ' << j << endl;
      if (a[i] > n - k) {
          if (j != -1) {
              res = (res * j) % mod;
          }
          j = 1;
      } else if (j != -1) {
          j++;
      }
  }

  sm = 0;
  for (i = n - k + 1; i <= n; i++) {
      sm += i;
  }
  cout << sm << ' ' << res;

  return 0;
}