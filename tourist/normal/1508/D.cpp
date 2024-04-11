/**
 *    author:  tourist
 *    created: 16.04.2021 18:40:49       
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> x(n), y(n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> a[i];
    --a[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return (y[i] < y[j] || (y[i] == y[j] && x[i] < x[j]));
  });
  vector<pair<int, int>> res;
  auto Do = [&](int x, int y) {
    res.emplace_back(x, y);
    swap(a[x], a[y]);
  };
  for (int it = 0; it < n; it++) {
    int st = order[it];
    if (a[st] == st) {
      continue;
    }
    sort(order.begin() + it + 1, order.end(), [&](int i, int j) {
      long long xi = x[i] - x[st];
      long long yi = y[i] - y[st];
      long long xj = x[j] - x[st];
      long long yj = y[j] - y[st];
      return xi * yj - xj * yi > 0;
    });
    dsu d(n);
    for (int i = 0; i < n; i++) {
      d.unite(i, a[i]);
    }
    for (int jt = it + 1; jt < n - 1; jt++) {
      if (d.unite(order[jt], order[jt + 1])) {
        Do(order[jt], order[jt + 1]);
      }
    }
    vector<int> cycle(1, st);
    while (true) {
      int nxt = a[cycle.back()];
      if (nxt == st) {
        break;
      }
      cycle.push_back(nxt);
    }
    assert((int) cycle.size() == n - it);
    for (int i = 1; i < (int) cycle.size(); i++) {
      Do(cycle[0], cycle[i]);
    }
    break;
  }
  for (int i = 0; i < n; i++) {
    assert(a[i] == i);
  }
  cout << res.size() << '\n';
  for (auto& p : res) {
    cout << p.first + 1 << " " << p.second + 1 << '\n';
  }
  return 0;
}