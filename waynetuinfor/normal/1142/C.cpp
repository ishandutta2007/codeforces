#include <bits/stdc++.h>
using namespace std;

struct Line {
  mutable int64_t a, b, p;
  bool operator<(const Line &rhs) const { return a < rhs.a; }
  bool operator<(int64_t x) const { return p < x; }
};

struct DynamicHull : multiset<Line, less<>> {
  static const int64_t kInf = 1e18;
  int64_t Div(int64_t a, int64_t b) { return a / b - ((a ^ b) < 0 && a % b); }
  bool Isect(iterator x, iterator y) {
    if (y == end()) { x->p = kInf; return false; }
    if (x->a == y->a) x->p = x->b > y->b ? kInf : -kInf;
    else x->p = Div(y->b - x->b, x->a - y->a);
    return x->p >= y->p;
  }
  void Insert(int64_t a, int64_t b) {
    auto z = insert({a, b, 0}), y = z++, x = y;
    while (Isect(y, z)) z = erase(z);
    if (x != begin() && Isect(--x, y)) Isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p) Isect(x, erase(y));
  }
  int64_t Query(int64_t x) {
    auto l = *lower_bound(x);
    return l.a * x + l.b; 
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  vector<int64_t> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    a[i] = -2 * x[i];
    b[i] = y[i] - 1LL * x[i] * x[i];
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    if (a[i] == a[j]) return b[i] > b[j];
    return a[i] < a[j];
  });

  deque<int> dq;
  for (int i = 0; i < n; ++i) {
    if (!dq.empty() && a[dq.back()] == a[ord[i]]) continue;
    while (dq.size() >= 2) {
      int u = dq[dq.size() - 2];
      int v = dq[dq.size() - 1];
      if ((b[u] - b[v]) * (a[ord[i]] - a[v]) >= (b[v] - b[ord[i]]) * (a[v] - a[u])) dq.pop_back();
      else break;
    }
    dq.push_back(ord[i]);
  }
  cout << dq.size() - 1 << "\n";
  return 0;
}