/**
 *    author:  tourist
 *    created: 16.08.2022 18:22:41       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

class segtree {
 public:
  struct node {
    int add = 0;
    int mn = 0;
    int pos = -1;

    void apply(int l, int r, int v) {
      if (l == r) {
        pos = l;
      }
      add += v;
      mn += v;
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.mn = min(a.mn, b.mn);
    res.pos = (a.mn == res.mn ? a.pos : b.pos);
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
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

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
    }
    vector<int> a(n);
    vector<int> nums;
    int k = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
      if (a[i] != -1) {
        nums.push_back(a[i]);
      } else {
        k += 1;
      }
    }
    assert(k >= 2);
    vector<int> s(k - 1);
    for (int i = 0; i < k - 1; i++) {
      cin >> s[i];
      --s[i];
      nums.push_back(s[i]);
    }
    vector<int> d(q);
    for (int i = 0; i < q; i++) {
      cin >> d[i];
      --d[i];
      nums.push_back(d[i]);
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    int sz = (int) nums.size();  
    for (int i = 0; i < n; i++) {
      if (a[i] != -1) {
        a[i] = (int) (lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin());
      }
    }
    for (int i = 0; i < k - 1; i++) {
      s[i] = (int) (lower_bound(nums.begin(), nums.end(), s[i]) - nums.begin());
    }
    for (int i = 0; i < q; i++) {
      d[i] = (int) (lower_bound(nums.begin(), nums.end(), d[i]) - nums.begin());
    }
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    SparseTable<int> ts(ind, [&](int i, int j) { return (p[i] > p[j] ? i : j); });
    vector<int> pv(n);
    vector<int> order;
    function<void(int, int, int)> Dfs = [&](int l, int r, int pr) {
      if (l > r) {
        return;
      }
      int i = ts.get(l, r);
      order.push_back(i);
      pv[i] = pr;
      Dfs(l, i - 1, i);
      Dfs(i + 1, r, i);
    };
    Dfs(0, n - 1, -1);
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
      if (a[i] == -1) {
        L[i] = 0;
        R[i] = sz - 1;
      } else {
        L[i] = a[i];
        R[i] = a[i];
      }
    }
    for (int it = 1; it < n; it++) {
      int i = order[it];
      R[i] = min(R[i], R[pv[i]] - 1);
    }
    for (int it = n - 1; it >= 1; it--) {
      int i = order[it];
      L[pv[i]] = max(L[pv[i]], L[i] + 1);
    }
    bool fail = false;
    for (int i = 0; i < n; i++) {
      if (L[i] > R[i]) {
        fail = true;
        break;
      }
    }
    if (fail) {
      for (int i = 0; i < q; i++) {
        cout << "NO" << '\n';
      }
      continue;
    }
    vector<int> have(sz);
    for (int i = 0; i < n; i++) {
      if (a[i] != -1) {
        have[a[i]] += 1;
      }
    }
    for (int i = 0; i < k - 1; i++) {
      have[s[i]] += 1;
    }
    vector<vector<int>> at(sz);
    for (int i = 0; i < n; i++) {
      at[L[i]].push_back(i);
    }
    int low = 0;
    int high = sz - 1;
    vector<int> zeros(sz);
    segtree st(zeros);
    for (int i = sz - 1; i >= 0; i--) {
      for (int j : at[i]) {
        st.modify(R[j], sz - 1, -1);
      }
      if (have[i] != 0) {
        st.modify(i, sz - 1, have[i]);
      }
      auto nd = st.get(i, sz - 1);
      if (nd.mn < -1) {
        low = 1;
        high = 0;
        break;
      }
      if (nd.mn == -1) {
        int j = nd.pos;
        low = max(low, i);
        high = min(high, j);
      }
    }
    for (int i = 0; i < q; i++) {
      cout << ((low <= d[i] && d[i] <= high) ? "YES" : "NO") << '\n';
    }
  }
  return 0;
}