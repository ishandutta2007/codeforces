/**
 *    author:  tourist
 *    created: 27.09.2020 18:48:59       
**/
#include <bits/stdc++.h>

using namespace std;

class segtree {
 public:
  struct node {
    int mx = -1;

    void apply(int l, int r, int v) {
      mx = v;
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

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> p(n);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
    pos[p[i]] = i;
  }
  vector<int> from(m);
  vector<int> to(m);
  for (int i = 0; i < m; i++) {
    cin >> from[i] >> to[i];
    --from[i]; --to[i];
  }
  vector<int> op(q);
  vector<int> id(q);
  for (int i = 0; i < q; i++) {
    cin >> op[i] >> id[i];
    --id[i];
  }
  vector<bool> removed(m, false);
  for (int i = 0; i < q; i++) {
    if (op[i] == 2) {
      removed[id[i]] = true;
    }
  }
  dsu d(n);
  vector<int> head(n);
  vector<int> tail(n);
  iota(head.begin(), head.end(), 0);
  iota(tail.begin(), tail.end(), 0);
  vector<int> nxt(n, -1);
  for (int i = 0; i < m; i++) {
    if (!removed[i]) {
      int x = d.get(from[i]);
      int y = d.get(to[i]);
      if (x != y) {
        d.unite(x, y);
        nxt[tail[x]] = head[y];
        head[y] = head[x];
      }
    }
  }
  vector<int> start(q, -1);
  vector<int> finish(q, -1);
  for (int i = q - 1; i >= 0; i--) {
    if (op[i] == 2) {
      int x = d.get(from[id[i]]);
      int y = d.get(to[id[i]]);
      if (x != y) {
        d.unite(x, y);
        nxt[tail[x]] = head[y];
        head[y] = head[x];
      }
    } else {
      int x = d.get(id[i]);
      start[i] = head[x];
      finish[i] = tail[x];
    }
  }
  vector<int> seq;
  for (int i = 0; i < n; i++) {
    if (d.get(i) == i) {
      int u = head[i];
      while (true) {
        seq.push_back(u);
        if (u == tail[i]) {
          break;
        }
        u = nxt[u];
      }
    }
  }
  assert((int) seq.size() == n);
  vector<int> in_seq(n, -1);
  for (int i = 0; i < n; i++) {
    in_seq[seq[i]] = i;
  }
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = p[seq[i]];
  }
  segtree st(arr);
  for (int i = 0; i < q; i++) {
    if (op[i] == 1) {
      int L = in_seq[start[i]];
      int R = in_seq[finish[i]];
      int res = st.get(L, R).mx;
      cout << res + 1 << '\n';
      if (res != -1) {
        st.modify(in_seq[pos[res]], in_seq[pos[res]], -1);
      }
    }
  }
  return 0;
}