#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

vi fen(3e5);

void add(int i, int val) {
  for (; i < fen.size(); i |= i + 1)
    fen[i] += val;
}

int getsum(int i) {
  int s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    s += fen[i];
  return s;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vii x(n);
  vi ts(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i].second >> x[i].first;
    ts[i] = x[i].second;
  }
  sort(ts.begin(), ts.end());
  ts.erase(unique(ts.begin(), ts.end()), ts.end());
  for (int i = 0; i < n; ++i) {
    x[i].second = lower_bound(ts.begin(), ts.end(), x[i].second) - ts.begin();
  }
  sort(x.rbegin(), x.rend());
  vi was(n);
  ll res = 0;
  for (int i = 0; i < x.size(); ++i) {
    int L = 0;
    if (i + 1 < x.size() && x[i].first == x[i + 1].first) L = x[i + 1].second + 1;
    if (!was[x[i].second]) {
      add(x[i].second, 1);
    }
    was[x[i].second] = 1;
    ll cntl = getsum(x[i].second) - getsum(L - 1);
    ll cntr = getsum(n) - getsum(x[i].second - 1);
    res += cntl * cntr;
  }
  cout << res << endl;
  return 0;
}