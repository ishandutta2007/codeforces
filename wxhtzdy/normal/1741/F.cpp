/**
 *    author:  wxhtzdy
 *    created: 11.10.2022 16:51:23
**/
#include <bits/stdc++.h>

using namespace std;
        
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

class segtree {
  public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    long long s = 0;
    long long add = 0;
    void apply(int l, int r, long long v) {
      s += v * (r - l + 1);
      add += v;
    }
  };
  node unite(const node &a, const node &b) const {
    node res;
    res.s = a.s + b.s;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> l(n), r(n), c(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i] >> c[i];
      --c[i];
    }
    vector<vector<int>> qs(n);
    for (int i = 0; i < n; i++) {
      qs[c[i]].push_back(i);
    }
    vector<int> xs;
    xs.push_back(0);
    xs.push_back(1e9 + 5);
    for (int i = 0; i < n; i++) {
      xs.push_back(l[i]);
      xs.push_back(r[i]);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    auto Id = [&](int v) {
      return lower_bound(xs.begin(), xs.end(), v) - xs.begin();
    };
    int k = (int) xs.size();
    fenwick<int> fenw(k);      
    for (int i = 0; i < n; i++) {
      fenw.modify(Id(l[i]), +1);
      fenw.modify(Id(r[i]) + 1, -1);      
    }
    vector<int> ans(n);
    multiset<int> points;
    segtree st(k);
    for (int i = 0; i < n; i++) {
      points.insert(l[i]);
      points.insert(r[i]);
      st.modify(Id(l[i]), Id(r[i]), +1);
    }                              
    for (int q = 0; q < n; q++) {
      for (int i : qs[q]) {
        fenw.modify(Id(l[i]), -1);
        fenw.modify(Id(r[i]) + 1, +1);
        points.erase(points.find(l[i]));
        points.erase(points.find(r[i]));
        st.modify(Id(l[i]), Id(r[i]), -1);
      }
      for (int i : qs[q]) {
        if (st.get(Id(l[i]), Id(r[i])).s > 0) {
          ans[i] = 0;
        } else {
          ans[i] = 1e9;
          {
            auto it = points.lower_bound(r[i]);
            if (it != points.end() && *it >= r[i]) {
              assert(*it > r[i]);
              ans[i] = min(ans[i], *it - r[i]);
            }
          }
          {
            auto it = points.lower_bound(l[i]);
            if (it != points.begin()) {
              if (it == points.end() || *it >= l[i]) {
                it = prev(it);
              }
              assert(*it <= l[i]);
              ans[i] = min(ans[i], l[i] - *it);
            }
          }
        }
      }
      for (int i : qs[q]) {
        fenw.modify(Id(l[i]), +1);
        fenw.modify(Id(r[i]) + 1, -1);
        points.insert(l[i]);
        points.insert(r[i]);
        st.modify(Id(l[i]), Id(r[i]), +1);
      }
    } 
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }                                                                    
  return 0;
}