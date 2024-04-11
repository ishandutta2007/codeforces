/**
 *    author:  tourist
 *    created: 05.10.2020 16:46:56       
**/
#include <bits/stdc++.h>

using namespace std;

class segtree {
 public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    int val = 0;
    int put = 0;

    void apply(int l, int r, int v) {
      val |= v;
      put |= v;
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.val = a.val | b.val;
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].put != 0) {
      tree[x + 1].apply(l, y, tree[x].put);
      tree[z].apply(y + 1, r, tree[x].put);
      tree[x].put = 0;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, q;
  cin >> k >> q;
  vector<long long> l(q);
  vector<long long> r(q);
  vector<int> v(q);
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i] >> v[i];
  }
  segtree msb(1 << k);
  segtree lsb(1 << k);
  for (int i = 0; i < q; i++) {
    {
      int from = l[i] >> k;
      int to = r[i] >> k;
      msb.modify(from, to, v[i]);
    }
    {
      if (r[i] - l[i] + 1 >= (1 << k)) {
        lsb.modify(0, (1 << k) - 1, v[i]);
      } else {
        int from = l[i] & ((1 << k) - 1);
        int to = r[i] & ((1 << k) - 1);
        if (from <= to) {
          lsb.modify(from, to, v[i]);
        } else {
          lsb.modify(from, (1 << k) - 1, v[i]);
          lsb.modify(0, to, v[i]);
        }
      }
    }
  }
  for (int i = 0; i < q; i++) {
    long long x = l[i];
    long long y = r[i];
    while (x <= y) {
      if ((x & ((1 << k) - 1)) == 0 && y - x + 1 >= (1 << k)) {
        int full = (y - x + 1) >> k;
        int a = msb.get(x >> k, (x >> k) + full - 1).val;
        int b = lsb.get(0, (1 << k) - 1).val;
        if ((a & b) != v[i]) {
          cout << "impossible" << '\n';
          return 0;
        }
        x += ((long long) full) << k;
        continue;
      }
      long long z = min(y, x | ((1 << k) - 1));
      int a = msb.get(x >> k, x >> k).val;
      int b = lsb.get(x & ((1 << k) - 1), z & ((1 << k) - 1)).val;
      if ((a & b) != v[i]) {
        cout << "impossible" << '\n';
        return 0;
      }
      x = z + 1;
    }
  }
  cout << "possible" << '\n';
  for (int i = 0; i < (1 << k); i++) {
    cout << lsb.get(i, i).val << '\n';
  }
  for (int i = 0; i < (1 << k); i++) {
    cout << msb.get(i, i).val << '\n';
  }
  return 0;
}