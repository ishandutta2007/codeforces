/**
 *    author:  tourist
 *    created: 15.10.2022 18:58:09       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

map<pair<int, int>, int> mp;
map<pair<int, int>, pair<int, int>> mb;

int f(int a, int b) {
  if (a + b <= 2) {
    return 0;
  }
  auto p = make_pair(a, b);
  auto it = mp.find(p);
  if (it != mp.end()) {
    return it->second;
  }
  int res = (int) 1e9;
  int bx = -1, by = -1;
  for (int x = max(0, (a - 1) / 2); x <= min(a, (a + 3) / 2); x++) {
    for (int y = max(0, (b - 1) / 2); y <= min(b, (b + 3) / 2); y++) {
      if (x + y >= a && a - x >= b) continue;
      if ((a - x) + (b - y) >= a && x >= b) continue;
      if ((x + y) + (a - x) >= a + b && x + y >= a) continue;
      if ((a - x) + (b - y) + x >= a + b && (a - x) + (b - y) >= a) continue;
      int got = f(x + y, a - x) + 1;
      int go2 = f((a - x) + (b - y), x) + 1;
      int u = max(got, go2);
      if (u < res) {
        res = u;
        bx = x;
        by = y;
      }
    }
  }
  mb[p] = make_pair(bx, by);
  return mp[p] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  f(n, 0);
  auto Ask = [&](vector<int> v) {
    cout << "? " << v.size();
    for (int x : v) {
      cout << " " << x;
    }
    cout << endl;
    string foo;
    cin >> foo;
    return (foo == "YES" ? 1 : 0);
  };
  auto Report = [&](int x) {
    cout << "! " << x << endl;
    string foo;
    cin >> foo;
    if (foo == ":)") {
      exit(0);
    }
  };
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    a.push_back(i);
  }
  vector<int> b;
  while (a.size() + b.size() > 2) {
    auto it = mb.find(make_pair((int) a.size(), (int) b.size()));
    assert(it != mb.end());
    int x = it->second.first;
    int y = it->second.second;
    vector<int> q;
    for (int i = 0; i < x; i++) {
      q.push_back(a[i]);
    }
    for (int i = 0; i < y; i++) {
      q.push_back(b[i]);
    }
    int got = Ask(q);
    if (got == 1) {
      vector<int> na;
      for (int i = 0; i < x; i++) {
        na.push_back(a[i]);
      }
      for (int i = 0; i < y; i++) {
        na.push_back(b[i]);
      }
      vector<int> nb;
      for (int i = x; i < (int) a.size(); i++) {
        nb.push_back(a[i]);
      }
      swap(a, na);
      swap(b, nb);
    } else {
      vector<int> na;
      for (int i = x; i < (int) a.size(); i++) {
        na.push_back(a[i]);
      }
      for (int i = y; i < (int) b.size(); i++) {
        na.push_back(b[i]);
      }
      vector<int> nb;
      for (int i = 0; i < x; i++) {
        nb.push_back(a[i]);
      }
      swap(a, na);
      swap(b, nb);
    }
  }
  for (int x : b) {
    a.push_back(x);
  }
  if (a.size() == 1) {
    Report(a[0]);
  }
  if (a.size() == 2) {
    Report(a[0]);
    Report(a[1]);
  }
  assert(false);
  return 0;
}