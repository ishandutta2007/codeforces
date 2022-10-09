// numero coppie con prodotto potenza k-esima
// idee:

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, p, t, n, res, m, a[100010], er[100010], x;
map<long long, long long> fact[100010];
vector<pair<long long, long long>> pr[100010];
vector<pair<long long, long long>> prr[100010];
// map<vector<pair<long long, long long>>, long long> hs;
map<vector<pair<long long, long long>>, long long> hsr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (i = 0; i < 100010; i++) {
    er[i] = 0;
  }
  for (i = 2; i < 100010; i++) {
    if (er[i] == 0) {
      for (j = 2 * i; j < 100010; j = j + i) {
        er[j] = i;
      }
    }
  }

  for (i = 0; i < n; i++) {
    x = a[i];
    while (er[x] != 0) {
      fact[i][er[x]]++;
      x /= er[x];
    }
    if (x != 1) {
      fact[i][x]++;
    }
    fact[i][1] = 1;
  }

  for (i = 0; i < n; i++) {
    for (auto u : fact[i]) {
      // cout << i << ' ' << u.first << ' ' << u.second << endl;
      if (u.second % k != 0) {
        pr[i].push_back({u.first, u.second % k});
        if (u.first == 1) {
          prr[i].push_back({1, 1});
        } else {
          prr[i].push_back({u.first, k - (u.second % k)});
        }
      }
    }
    hsr[prr[i]]++;
  }

  res = 0;
  for (i = 0; i < n; i++) {
    res += hsr[pr[i]];
    if (pr[i] == prr[i]) {
      res--;
    }
  }

  cout << res / 2;

  /* cout << endl;
  for (auto u : hsr) {
    cout << u.second << endl;
    for (auto v : u.first) {
      cout << v.first << ' ' << v.second << endl;
    }
  } */

  return 0;
}