#include <bits/stdc++.h>
using namespace std;

const int A = 100'000'000;

set<int> v;

int query(int x, int y) {
  cout << 0 << " " << x << " " << y << endl;
  int d;
  cin >> d;
  return d;
}

void solve(int l, int r) {
  if (r - l <= 1) {
    return;
  }

  if ((r - l) % 2 == 1) {
    if (query(l + 1, l + 1) == 0) {
      v.insert(l + 1);
    }
    ++l;
  }

  int m = l + (r - l) / 2;
  int d = query(m, m);
  if (d == (r - l) / 2) {
    return;
  }

  if (d == 0 || query(m + d, m + d) == 0) {
    v.insert(m + d);
    solve(l, m + d);
    solve(m + d, r);
  } else {
    v.insert(m - d);
    solve(l, m - d);
    solve(m - d, r);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  v.insert(A - query(A, A));
  v.insert(-A + query(-A, -A));
  solve(*v.begin(), *(--v.end()));

  int u = -A;
  while (v.count(u) > 0) {
    ++u;
  }

  set<int> x;
  set<int> y;
  for (auto i : v) {
    if (query(i, u) == 0) {
      x.insert(i);
    }
    if (query(u, i) == 0) {
      y.insert(i);
    }
  }

  cout << 1 << " " << x.size() << " " << y.size() << endl;
  for (auto i : x) {
    cout << i << " ";
  }
  cout << endl;
  for (auto i : y) {
    cout << i << " ";
  }
  cout << endl;
}