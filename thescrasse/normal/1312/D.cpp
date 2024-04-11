#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, res, m, mod, c, r, r1, g;
bool er[200010];

long long padic(long long a, long long b) {
  r = 0;
  c = b;
  while (a >= b) {
    r = r + (a / b);
    b *= c;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> m;
  mod = 998244353;
  res = 1;
  for (i = 0; i < n - 3; i++) {
    res = (res * 2) % mod;
  }
  res = (res * (n - 2)) % mod;

  //cout << res << endl;

  for (i = 2; i < 200010; i++) {
    er[i] = false;
  }

  for (i = 2; i < 200010; i++) {
    if (er[i] == false) {
      for (j = 2 * i; j < 200010; j = j + i) {
        er[j] = true;
      }
    }
  }

  r1 = 1;
  for (i = 2; i < 200010; i++) {
    if (er[i] == false) {
      //cout << i << ' ' << padic(m, i) << ' ' << padic(m - n + 1, i) << ' ' << padic(n - 1, i) << endl;
      g = padic(m, i) - padic(m - n + 1, i) - padic(n - 1, i);
      for (j = 0; j < g; j++) {
        res = (res * i) % mod;
      }
    }
  }

  cout << res;

  return 0;
}