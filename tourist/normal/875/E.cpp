/**
 *    author:  tourist
 *    created: 18.10.2017 01:01:24       
**/
#include <bits/stdc++.h>

using namespace std;

class segtree {
  public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    int mx = -1;
    int mn = -1;

    void apply(int l, int r, int v) {
      mx = mn = v;
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.mn = min(a.mn, b.mn);
    res.mx = max(a.mx, b.mx);
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    // push from x into (x + 1) and z
/*
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
*/
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
  void modify(int x, int l, int r, int ll, int rr, M... v) {
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

  function<bool(const node&)> f;

  int find_first(int x, int l, int r, int ll, int rr, bool know) {
    if (!know && ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      know = true;
    }
    if (know && l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y && (!know || f(tree[x + 1]))) {
      res = find_first(x + 1, l, y, ll, rr, know);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, know);
    }
    pull(x, z);
    return res;
  }

  int find_last(int x, int l, int r, int ll, int rr, bool know) {
    if (!know && ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      know = true;
    }
    if (know && l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y && (!know || f(tree[z]))) {
      res = find_last(z, y + 1, r, ll, rr, know);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, know);
    }
    pull(x, z);
    return res;
  }

  segtree(int n) : n(n) {
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

  template <typename... M>
  void modify(int ll, int rr, M... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ll, int rr, const function<bool(const node&)> &ff) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    f = ff;
    return find_first(0, 0, n - 1, ll, rr, false);
  }

  int find_last(int ll, int rr, const function<bool(const node&)> &ff) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    f = ff;
    return find_last(0, 0, n - 1, ll, rr, false);
  }
};

int main() {
  int n, s1, s2;
  scanf("%d %d %d", &n, &s1, &s2);
  n += 2;
  vector<int> x(n);
  x[0] = s1;
  x[1] = s2;
  for (int i = 2; i < n; i++) {
    scanf("%d", &x[i]);
  }
  segtree st(x);
  int low = abs(s1 - s2), high = (int) 1e9;
  while (low < high) {
    int mid = (low + high) >> 1;
    bool found = false;
    int up = 0;
    for (int i = 0; i < n - 1; i++) {
      if (abs(x[i] - x[i + 1]) > mid) {
        continue;
      }
      if (i > up) {
        break;
      }
      int xi = x[i];
      int nxt = st.find_first(i + 1, n - 1, [&mid, &xi](const auto &t) {
        return (t.mx > xi + mid || t.mn < xi - mid);
      });
      if (nxt == -1) {
        found = true;
        break;
      } else {
        up = max(up, nxt - 1);
      }
    }
    if (found) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  printf("%d\n", low);
  return 0;
}