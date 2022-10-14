/**
 *    author:  wxhtzdy
 *    created: 22.08.2022 16:11:14
**/
#include <bits/stdc++.h>

using namespace std;

struct Line {
  mutable long long m, b, p;
  bool operator<(const Line& o) const { return m < o.m; }
  bool operator<(long long x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  const long long inf = LLONG_MAX;
  long long div(long long a, long long b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b); 
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) { x->p = inf; return false; }
    if (x->m == y->m) x->p = x->b > y->b ? inf : -inf;
    else x->p = div(y->b - x->b, x->m - y->m);
    return x->p >= y->p;
  }
  void add(long long m, long long b) {
    auto z = insert({m, b, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
  }
  long long query(long long x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.m * x + l.b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  const long long inf = 1e18;
  vector<long long> d(n, inf);
  d[0] = 0;
  for (int step = 0; step < k + 1; step++) {    
    set<pair<long long, int>> st;
    for (int i = 0; i < n; i++) {
      st.emplace(d[i], i);
    }
    while (!st.empty())  {
      auto it = st.begin();
      int i = it->second;
      st.erase(it);
      for (auto& p : g[i]) {
        int to = p.first;
        int w = p.second;
        if (d[to] > d[i] + w) {     
          if (st.find({d[to], to}) == st.end()) {
            st.erase(st.find({d[to], to}));
          }
          d[to] = d[i] + w;
          st.emplace(d[to], to);
        }
      }
    }
    if (step == k) {
      break;
    }
    LineContainer ch;
    for (int i = 0; i < n; i++) {
      ch.add(2 * i, -i * 1LL * i - d[i]);
    }
    for (int i = 0; i < n; i++) {
      d[i] = i * 1LL * i - ch.query(i);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << d[i] << " \n"[i == n - 1]; 
  }                              
  return 0;
}