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

void first() {
  cout << "sjfnb\n";
  exit(0);
}

void second() {
  cout << "cslnb\n";
  exit(0);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vl a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  int c = 0;
  for (int i = 0; i + 1 < n; ++i) if (a[i] == a[i + 1]) {
    ++c;
    if (c > 1 || a[i] == 0 || (i && (a[i - 1] == a[i] || a[i - 1] == a[i] - 1))) second();
  }
  ll s = 0;
  for (int i = 0; i < n; ++i) s += a[i] - i;
  if (s % 2) first();
  else second();
  return 0;
}