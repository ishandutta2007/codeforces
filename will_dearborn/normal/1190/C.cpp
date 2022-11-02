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

bool check(int n, int k, const string& s) {
  vvi c(n + 1, vi(2));
  for (int i = 0; i < n; ++i) {
    c[i + 1] = c[i];
    c[i + 1][s[i] - '0']++;
  }
  for (int i = 0; i + k <= n; ++i) {
    for (int t : {0, 1}) {
      if (c[i][t] + c[n][t] - c[i + k][t] == n - k) {
        return true;
      }
    }
  }
  return false; 
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  vvi c(n + 1, vi(2));
  for (int i = 0; i < n; ++i) {
    c[i + 1] = c[i];
    c[i + 1][s[i] - '0']++;
  }
  if (check(n, k, s)) {
    cout << "tokitsukaze\n";
    return 0;
  }
  bool even = false;
  for (int i = 0; i + k <= n; ++i) {
    bool emp = i == 0 || i + k == n;
    int l1 = i, l2 = n - i - k;
    if (emp) {
      for (int t : {0, 1}) {
        string s1 = s;
        for (int j = i; j < i + k; ++j) s1[j] = t + '0';
        if (!check(n, k, s1)) even = true;
      }
      continue;
    }
    if (max(c[i][0], c[i][1]) != l1 || max(c[n][0] - c[i + k][0], c[n][1] - c[i + k][1]) != l2) {
      even = true; break;
    }
    if (max(l1, l2) > k || max(c[i][0] + c[n][0] - c[i + k][0], c[i][1] + c[n][1] - c[i + k][1]) == n - k) {
      even = true; break;
    }
  }
  if (even) {
    cout << "once again\n";
  } else {
    cout << "quailty\n";
  }
  return 0;
}