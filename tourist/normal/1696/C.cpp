/**
 *    author:  tourist
 *    created: 25.06.2022 18:24:34       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

vector<pair<int, long long>> Process(vector<int> a, int m) {
  int n = (int) a.size();
  vector<pair<int, long long>> b;
  for (int x : a) {
    int y = 1;
    while (x % m == 0) {
      x /= m;
      y *= m;
    }
    if (!b.empty() && x == b.back().first) {
      b.back().second += y;
    } else {
      b.emplace_back(x, y);
    }
  }
  return b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto pa = Process(a, m);
    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
      cin >> b[i];
    }
    auto pb = Process(b, m);
    cout << (pa == pb ? "Yes" : "No") << '\n';
  }
  return 0;
}