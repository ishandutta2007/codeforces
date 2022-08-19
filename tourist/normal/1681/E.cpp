/**
 *    author:  tourist
 *    created: 23.05.2022 18:54:06       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

vector<array<array<int, 2>, 2>> dist;

class segtree {
 public:
  struct node {
    array<long long, 4> a;
    int L;
    int R;

    void apply(int l, int r, array<long long, 4> v) {
      a = v;
      L = l;
      R = r;
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.L = a.L;
    res.R = b.R;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        long long best = (long long) 1e18;
        for (int k = 0; k < 2; k++) {
          for (int t = 0; t < 2; t++) {
            long long cur = a.a[i * 2 + k] + b.a[t * 2 + j];
            cur += dist[b.L][k][t];
            best = min(best, cur);
          }
        }
        res.a[i * 2 + j] = best;
      }
    }
    return res;
  }

  inline void push(int x, int l, int r) {
  }

  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }

  int n;
  vector<node> tree;

  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }

  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }

  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }

  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }

  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> bot(n - 1);
  vector<pair<int, int>> lft(n - 1);
  vector<pair<int, int>> top(n - 1);
  vector<pair<int, int>> rgt(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> bot[i].first >> bot[i].second >> lft[i].first >> lft[i].second;
    top[i] = bot[i];
    top[i].first += 1;
    rgt[i] = lft[i];
    rgt[i].second += 1;
  }
  vector<array<long long, 4>> p(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int d = abs(bot[i].first - lft[i].first) + abs(bot[i].second - lft[i].second);
    p[i] = {1, d + 1, d + 1, 1};
  }
  dist.resize(n - 1);
  for (int q = 1; q < n - 1; q++) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        auto ga = (i == 0 ? top[q - 1] : rgt[q - 1]);
        auto gb = (j == 0 ? bot[q] : lft[q]);
        dist[q][i][j] = abs(ga.first - gb.first) + abs(ga.second - gb.second);
      }
    }
  }
  segtree st(p);
  int tt;
  cin >> tt;
  while (tt--) {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    int ia = max(xa, ya) - 1;
    int ib = max(xb, yb) - 1;
    if (ia > ib) {
      swap(xa, xb);
      swap(ya, yb);
      swap(ia, ib);
    }
    if (ia == ib) {
      cout << abs(xa - xb) + abs(ya - yb) << '\n';
      continue;
    }
    auto nd = st.get(ia, ib - 1);
    long long ans = (long long) 1e18;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        auto ga = (i == 0 ? bot[ia] : lft[ia]);
        int da = abs(ga.first - xa) + abs(ga.second - ya);
        auto gb = (j == 0 ? top[ib - 1] : rgt[ib - 1]);
        int db = abs(gb.first - xb) + abs(gb.second - yb);
        ans = min(ans, da + db + nd.a[i * 2 + j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}