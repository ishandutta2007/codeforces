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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
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
  while (a.size() > 3) {
    int sz = (int) a.size();
    vector<int> x;
    for (int i = 0; i < sz; i++) {
      if (i & 1) {
        x.push_back(a[i]);
      }
    }
    int r0 = Ask(x);
    vector<int> y;
    for (int i = 0; i < sz; i++) {
      if (i & 2) {
        y.push_back(a[i]);
      }
    }
    int r1 = Ask(y);
    vector<int> na;
    for (int i = 0; i < sz; i++) {
      if ((i & 1) == r0 || (i & 2) == 2 * r1) {
        na.push_back(a[i]);
      }
    }
    swap(a, na);
  }
  if (a.size() == 1) {
    Report(a[0]);
  }
  if (a.size() == 2) {
    Report(a[0]);
    Report(a[1]);
  }
  if (a.size() == 3) {
    int bad = -1;
    int x = Ask(vector<int>{a[0]});
    int y = Ask(vector<int>{a[1]});
    if (x == 1 && y == 1) bad = 2;
    if (x == 1 && y == 0) bad = 1;
    if (x == 0 && y == 1) bad = 0;
    if (x == 0 && y == 0) {
      int w = Ask(vector<int>{a[1]});
      if (w == 0) {
        bad = 1;
      } else {
        int q = Ask(vector<int>{a[2]});
        if (q == 1) {
          bad = 0;
        } else {
          bad = 2;
        }
      }
    }
    assert(bad != -1);
    for (int i = 0; i < 3; i++) {
      if (i != bad) {
        Report(a[i]);
      }
    }
  }
  assert(false);
  return 0;
}