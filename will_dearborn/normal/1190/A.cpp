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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, m, k;
  cin >> n >> m >> k;
  vl a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
  }
  sort(a.begin(), a.end());
  ll p = 0, res = 0;
  while (p < n) {
    int i = lower_bound(a.begin(), a.end(), p) - a.begin();
    if (i >= a.size()) break;
    p += (a[i] - p) / k * k;
    int c = 0;
    while (i + c < a.size() && a[i + c] < p + k + c) {
      ++res;
      int j = lower_bound(a.begin(), a.end(), p + k + c) - a.begin();
      c = j - i;
    }
    p += k + c;
  }
  cout << res << endl;
  return 0;
}