/**
 *    author:  milos
 *    created: 25.03.2021 13:55:18       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
class segtree {
  public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    int a = 0;
    void apply(int l, int r, int v) {
      a = max(a, v);
    }
  };
  node unite(const node &a, const node &b) const {
    node res;
    res.a = max(a.a, b.a);
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
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }     
  function<void(vector<int>&)> Compress = [&](vector<int>& x) {
    vector<int> all;
    for (int i : x) {
      all.push_back(i);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int& i : x) {
      i = lower_bound(all.begin(), all.end(), i) - all.begin();    
    }
  };
  Compress(a);
  Compress(b);
  Compress(c);
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) {
    return a[i] > a[j];  
  });
  segtree st(n + 2);
  int ans = 0;
  for (int j = 0; j < n; j++) {
    int x = j;
    for (int i = j; i < n; i++) {
      if (a[id[i]] != a[id[j]]) {
        break;
      }        
      int mx = st.get(b[id[i]] + 1, n).a;
      if (mx > c[id[i]]) {
        ans += 1;
      }
      x++;
    }
    for (int i = j; i < x; i++) {
      st.modify(b[id[i]], b[id[i]], c[id[i]]);
    }
    j = x - 1;
  }
  cout << ans << '\n';
  return 0;
}