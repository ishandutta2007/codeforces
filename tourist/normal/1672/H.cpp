/**
 *    author:  tourist
 *    created: 23.04.2022 18:35:26       
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
    int cnt = 0;
    int op = 0;
    int pl = 0;
    int pr = 0;
    int dl = 0;
    int dr = 0;

    void apply(int l, int r, int v) {
      cnt = 1;
      op = 0;
      pl = 1;
      pr = 1;
      dl = v;
      dr = v;
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.op = a.op + b.op;
    res.cnt = a.cnt + b.cnt;
    res.dl = a.dl;
    res.dr = b.dr;
    res.pl = a.pl;
    res.pr = b.pr;
    if (a.cnt == 1 && b.cnt == 1) {
      if (a.dr == b.dl) {
        res.cnt -= 1;
        res.pl ^= res.pr;
        res.pr = res.pl;
      }
      return res;
    }
    if (a.cnt == 1) {
      if (a.dr == b.dl) {
        res.cnt -= 1;
        res.pl ^= b.pl;
      } else {
        if (b.pl == 0) {
          res.op += 1;
          res.cnt -= 2;
          if (b.cnt >= 3) {
            res.pl ^= 1;
          } else {
            res.pl ^= res.pr;
            res.pr = res.pl;
          }
        }
      }
      return res;
    }
    if (b.cnt == 1) {
      if (b.dl == a.dr) {
        res.cnt -= 1;
        res.pr ^= a.pr;
      } else {
        if (a.pr == 0) {
          res.op += 1;
          res.cnt -= 2;
          if (a.cnt >= 3) {
            res.pr ^= 1;
          } else {
            res.pl ^= res.pr;
            res.pr = res.pl;
          }
        }
      }
      return res;
    }
    if (a.dr == b.dl) {
      res.cnt -= 1;
      if ((a.pr ^ b.pl) == 0) {
        if (a.cnt == b.cnt) {
          res.op += a.cnt - 1;
          res.cnt = 1;
          res.pl ^= res.pr;
          res.pr = res.pl;
        } else {
          if (a.cnt < b.cnt) {
            res.op += a.cnt - 1;
            res.cnt -= 2 * (a.cnt - 1);
            res.pl ^= 1;
          } else {
            res.op += b.cnt - 1;
            res.cnt -= 2 * (b.cnt - 1);
            res.pr ^= 1;
          }
        }
      }
      return res;
    }
    if (a.pr == 1 && b.pl == 1) {
      return res;
    }
    if (a.pr == 1 && b.pl == 0) {
      if (a.cnt == b.cnt - 1) {
        res.op += a.cnt;
        res.cnt = 1;
        res.pl ^= res.pr;
        res.pr = res.pl;
      } else {
        if (a.cnt < b.cnt - 1) {
          res.op += a.cnt;
          res.cnt -= 2 * a.cnt;
          res.pl ^= 1;
        } else {
          res.op += b.cnt - 1;
          res.cnt -= 2 * (b.cnt - 1);
          res.pr ^= 1;
        }
      }
      return res;
    }
    if (a.pr == 0 && b.pl == 1) {
      if (a.cnt - 1 == b.cnt) {
        res.op += b.cnt;
        res.cnt = 1;
        res.pl ^= res.pr;
        res.pr = res.pl;
      } else {
        if (a.cnt - 1 < b.cnt) {
          res.op += a.cnt - 1;
          res.cnt -= 2 * (a.cnt - 1);
          res.pl ^= 1;
        } else {
          res.op += b.cnt;
          res.cnt -= 2 * b.cnt;
          res.pr ^= 1;
        }
      }
      return res;
    }
    res.op += 1;
    res.cnt -= 2;
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
  int n, tt;
  cin >> n >> tt;
  string s;
  cin >> s;
  segtree st(n);
  for (int i = 0; i < n; i++) {
    int d = (s[i] == '1' ? 1 : 0);
    d ^= (i % 2 == 1);
    st.modify(i, i, d);
  }
  while (tt--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    auto nd = st.get(x, y);
    cout << nd.cnt + nd.op << '\n';
  }
  return 0;
}