/**
 *    author:  tourist
 *    created: 19.05.2022 19:05:26       
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
    int mx = -1;

    void apply(int l, int r, int v) {
      mx = max(mx, v);
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.mx = max(a.mx, b.mx);
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> xs = a;
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    for (int i = 0; i < n; i++) {
      a[i] = (int) (lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin());
    }
    vector<int> l(m), r(m);
    for (int i = 0; i < m; i++) {
      cin >> l[i] >> r[i];
      --l[i]; --r[i];
    }
    const int inf = (int) 1e9;
    int L = -1, R = -1;
    for (int rot = 0; rot < 2; rot++) {
      vector<int> last(n, -1);
      vector<int> pred(n, -1);
      for (int i = 0; i < n; i++) {
        pred[i] = last[a[i]];
        last[a[i]] = i;
      }
      segtree st(pred);
      int mn = inf;
      for (int i = 0; i < m; i++) {
        int id = st.find_first(l[i], r[i], [&](const segtree::node& nd) {
          return nd.mx >= l[i];
        });
        if (id != -1) {
          mn = min(mn, id);
        }
      }
      if (mn == inf) {
        break;
      }
      if (rot == 0) {
        L = mn;
      } else {
        R = n - 1 - mn;
      }
      reverse(a.begin(), a.end());
      for (int i = 0; i < m; i++) {
        swap(l[i], r[i]);
        l[i] = n - 1 - l[i];
        r[i] = n - 1 - r[i];
      }
    }
    if (L == -1) {
      cout << 0 << '\n';
      continue;
    }
    vector<int> lft(n, -1);
    vector<int> rgt(n, -1);
    for (int i = 0; i < L; i++) {
      lft[a[i]] = i;
    }
    for (int i = n - 1; i > R; i--) {
      rgt[a[i]] = i;
    }
    segtree st(n);
    for (int i = 0; i < m; i++) {
      st.modify(l[i], l[i], r[i]);
    }
    segtree sf(n);
    for (int i = 0; i < n; i++) {
      if (lft[i] != -1 && rgt[i] != -1 && lft[i] != rgt[i]) {
        if (st.get(0, lft[i]).mx >= rgt[i]) {
          sf.modify(lft[i], lft[i], rgt[i]);
        }
      }
    }
    int ans = n;
    for (int from = 0; from <= L; from++) {
      int to = R;
      if (from > 0) {
        to = max(to, sf.get(0, from - 1).mx);
      }
      ans = min(ans, to - from + 1);
    }
    ans = max(ans, 1);
    cout << ans << '\n';
  }
  return 0;
}