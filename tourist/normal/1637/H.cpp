/**
 *    author:  tourist
 *    created: 12.02.2022 19:31:15       
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
    int val = -1;
    int mn = -1;

    void apply(int l, int r, int v) {
      val = v;
      mn = v;
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.mn = min(a.mn, b.mn);
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
  int tt;
  cin >> tt;
  while (tt--) {
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
    fenwick<int> fenw(n + 2);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      int below = fenw.get(a[i]);
      int above = i - 1 - below;
      ans += above;
      val[i] = below - above;
      fenw.modify(a[i], 1);
    }
    segtree st(a);
    set<pair<int, int>> s;
    int shift = 0;
    vector<int> pr(n + 2, -1);
    vector<int> ne(n + 2, -1);
    fenwick<int> fenw_pos(n + 2);
    fenwick<int> fenw_val(n + 2);
    vector<int> delta(n + 2);
    vector<int> shift_when(n + 2);
    ne[0] = n + 1;
    pr[n + 1] = 0;
    int step = 0;
    function<void(int, int)> Add = [&](int x, int y) {
      assert(ne[x] == y && pr[y] == x);
      if (x + 1 <= y - 1) {
        int z = st.get(x + 1, y - 1).mn;
        if (z > n) {
          return;
        }
        z = pos[z];
        assert(a[z] > a[x]);
        if (a[z] < a[y]) {
          pr[z] = x;
          ne[z] = y;
          pr[ne[z]] = z;
          ne[pr[z]] = z;

          delta[z] = delta[x] + (shift - shift_when[x]);
          delta[z] -= 2 * (fenw_pos.get(z - 1) - fenw_pos.get(x));
          delta[z] += 2 * (fenw_val.get(a[z] - 1) - fenw_val.get(a[x]));
          shift_when[z] = shift;
          s.emplace(val[z] + delta[z] - shift, z);
          
          Add(x, z);
          Add(z, y);
        }
      }
    };
    Add(0, n + 1);
    cout << ans;
    for (step = 1; step <= n; step++) {
//      debug(step, s, shift);
      assert(!s.empty());
      auto it = s.begin();
      ans += it->first + shift;
      cout << " " << ans;
      int i = it->second;
      s.erase(it);
      st.modify(i, i, 10 * n);
      shift -= 1;
      fenw_pos.modify(i, +1);
      fenw_val.modify(a[i], +1);
      pr[ne[i]] = pr[i];
      ne[pr[i]] = ne[i];
      Add(pr[i], ne[i]);
    }
    cout << '\n';
  }
  return 0;
}