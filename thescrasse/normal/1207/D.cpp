// 1207D
// permutazioni buone di un vector di pair
// idee: inclusione-esclusione

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, a, b, m, check1, res, mod, c;
vector<pair<long long, long long>> vp;
vector<long long> va, vb;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  mod = 998244353;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    vp.push_back({a, b});
    va.push_back(a);
    vb.push_back(b);
  }

  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  sort(vp.begin(), vp.end());

  check1 = 1;
  for (i = 0; i < n; i++) {
    if (vb[i] != vp[i].second) {
      check1 = 0;
      break;
    }
  }

  res = 1;
  for (i = 2; i <= n; i++) {
    res = (res * i) % mod;
  }
  // cout << res << endl;

  c = 1;
  k = 1;
  for (i = 1; i < n; i++) {
    if (va[i] == va[i - 1]) {
      k++;
    } else {
      k = 1;
    }
    c = (c * k) % mod;
  }
  res = (res + mod - c) % mod;
  // cout << res << endl;

  c = 1;
  k = 1;
  for (i = 1; i < n; i++) {
    if (vb[i] == vb[i - 1]) {
      k++;
    } else {
      k = 1;
    }
    c = (c * k) % mod;
  }
  res = (res + mod - c) % mod;
  // cout << res << endl;

  if (check1 == 1) {
    c = 1;
    k = 1;
    for (i = 1; i < n; i++) {
      if (va[i] == va[i - 1] && vb[i] == vb[i - 1]) {
        k++;
      } else {
        k = 1;
      }
      c = (c * k) % mod;
    }
    res = (res + c) % mod;
  }
  // cout << res << endl;

  cout << res;

  return 0;
}