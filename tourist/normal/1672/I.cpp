/**
 *    author:  tourist
 *    created: 12.02.2022 19:31:15       
**/
//#undef _GLIBCXX_DEBUG

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
    int mn = -1;
    int add = 0;
    int id = -1;

    void apply(int l, int r, int v, bool to_add) {
      if (to_add) {
        add += v;
        mn += v;
      } else {
        mn = v;
        add = 0;
        id = l;
      }
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.mn = min(a.mn, b.mn);
    res.id = (res.mn == a.mn ? a.id : b.id);
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add, true);
      tree[z].apply(y + 1, r, tree[x].add, true);
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

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = 0;
  a[n + 1] = n + 1;
  vector<int> pos(n + 2);
  for (int i = 0; i <= n + 1; i++) {
    pos[a[i]] = i;
  }
  vector<int> val(n + 2);
  for (int i = 1; i <= n; i++) {
    val[i] = (a[i] >= i ? a[i] - i : i - a[i]);
  }
  segtree st1(n + 2);
  segtree st2(n + 2);
  segtree st3(n + 2);
  segtree st4(n + 2);
  for (int i = 0; i <= n + 1; i++) {
    st1.modify(i, i, a[i] >= i ? a[i] : 10 * n, false);
    st2.modify(i, i, a[i] >= i ? 10 * n : -a[i], false);
    st3.modify(i, i, 10 * n, false);
    st4.modify(i, i, 10 * n, false);
  }
  set<int> s1;
  set<int> s2;
  vector<int> pr1(n + 2, -1);
  vector<int> ne1(n + 2, -1);
  vector<int> pr2(n + 2, -1);
  vector<int> ne2(n + 2, -1);
  fenwick<int> fenw_pos(n + 2);
  fenwick<int> fenw_val(n + 2);
  vector<int> delta(n + 2);
  ne1[0] = n + 1;
  pr1[n + 1] = 0;
  ne2[0] = n + 1;
  pr2[n + 1] = 0;
  int step = 0;
  function<void(int, int, int, int, int)> Add1 = [&](int x, int y, int rx, int ry, int init) {
    assert(ne1[x] == y && pr1[y] == x);
    if (x + 1 <= y - 1) {
      int z = st1.get(x + 1, y - 1).mn;
      debug("1", x, y, z);
      if (z > n) {
        return;
      }
      z = pos[z];
      assert(a[z] > a[x]);
      if (a[z] < a[y]) {
        pr1[z] = x;
        ne1[z] = y;
        pr1[ne1[z]] = z;
        ne1[pr1[z]] = z;

        delta[z] = init;
        delta[z] -= (fenw_pos.get(rx - 1) - fenw_pos.get(z));
        delta[z] -= (fenw_val.get(a[z] - 1) - fenw_val.get(ry));
        debug("!!!", z);
        st3.modify(z, z, val[z] + delta[z], false);
        s1.insert(a[z]);
//        s.emplace(val[z] + delta[z], z);
        
        Add1(x, z, rx, ry, init);
        Add1(z, y, rx, ry, init);
      }
    }
  };
  Add1(0, n + 1, n, 1, 0);
  function<void(int, int, int, int, int)> Add2 = [&](int x, int y, int rx, int ry, int init) {
    assert(ne2[x] == y && pr2[y] == x);
    if (x + 1 <= y - 1) {
      int z = -st2.get(x + 1, y - 1).mn;
      debug("2", x, y, z);
      if (abs(z) > n) {
        return;
      }
      z = pos[z];
      assert(a[z] < a[y]);
      if (a[z] > a[x]) {
        pr2[z] = x;
        ne2[z] = y;
        pr2[ne2[z]] = z;
        ne2[pr2[z]] = z;

        delta[z] = init;
        delta[z] -= (fenw_pos.get(z - 1) - fenw_pos.get(rx));
        delta[z] -= (fenw_val.get(ry - 1) - fenw_val.get(a[z]));
        st4.modify(z, z, val[z] + delta[z], false);
        s2.insert(a[z]);
//        s.emplace(val[z] + delta[z], z);
        
        Add2(x, z, rx, ry, init);
        Add2(z, y, rx, ry, init);
      }
    }
  };
  Add2(0, n + 1, 1, n, 0);
  int ans = 0;
  for (step = 1; step <= n; step++) {
//      debug(step, s, shift);
    auto nd3 = st3.get(1, n);
    auto nd4 = st4.get(1, n);
    debug(step, nd3.mn, nd3.id, nd4.mn, nd4.id);
    debug(s1, s2);
    if (nd3.mn < nd4.mn) { 
      auto nd = nd3;
      ans = max(ans, nd.mn);
      int i = nd.id;
      st3.modify(i, i, 10 * n, false);
      fenw_pos.modify(i, +1);
      fenw_val.modify(a[i], +1);
      st1.modify(i, i, 10 * n, false);
      pr1[ne1[i]] = pr1[i];
      ne1[pr1[i]] = ne1[i];
      s1.erase(a[i]);
      Add1(pr1[i], ne1[i], i, a[i], nd.mn - val[i] - 1);
      auto iter = s2.lower_bound(a[i]);
      int L = i;
      int R = (iter == s2.end() ? n : pos[*iter] - 1);
      debug(L, R);
      if (L <= R) {
        st4.modify(L, R, -1, true);
      }
    } else {
      auto nd = nd4;
      ans = max(ans, nd.mn);
      int i = nd.id;
      st4.modify(i, i, 10 * n, false);
      fenw_pos.modify(i, +1);
      fenw_val.modify(a[i], +1);
      st2.modify(i, i, 10 * n, false);
      pr2[ne2[i]] = pr2[i];
      ne2[pr2[i]] = ne2[i];
      s2.erase(a[i]);
      Add2(pr2[i], ne2[i], i, a[i], nd.mn - val[i] - 1);
      debug(s2);
      auto iter = s1.lower_bound(a[i]);
      int L = (iter == s1.begin() ? 1 : pos[*prev(iter)] + 1);
      int R = i;
      debug(L, R);
      if (L <= R) {
        st3.modify(L, R, -1, true);
      }
    }
  }
  cout << ans << '\n';
  debug(clock());
  return 0;
}