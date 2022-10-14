/**
 *    author:  wxhtzdy
 *    created: 07.09.2022 17:56:53
**/
#include <bits/stdc++.h>

using namespace std;

class segtree {
  public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    long long s = 0;
    void apply(int l, int r, int v) {
      s += v;
    }
  };
  node unite(const node &a, const node &b) const {
    node res;
    res.s = a.s + b.s;
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
  const int MAX = 4e5 + 5;
  vector<vector<int>> divs(MAX);
  for (int i = 1; i < MAX; i++) {
    for (int j = i + i; j < MAX; j += i) {
      divs[j].push_back(i);
    }
  }
  int qq;
  cin >> qq;
  vector<vector<pair<int, int>>> qs(MAX); 
  vector<long long> ans(qq);
  for (int i = 0; i < qq; i++) {
    int l, r;
    cin >> l >> r;
    qs[r].emplace_back(l, i);
    long long n = r - l + 1;
    ans[i] = n * (n - 1) * (n - 2) / 6;
  }                      
  segtree st(MAX);
  vector<vector<int>> qx(MAX);
  for (int i = 3; i < MAX / 2; i++) {
    { 
      vector<int> d;
      for (int k : divs[i]) {
        d.push_back(k);
      }                                     
      int sz = (int) d.size();
      for (int j = 0; j < sz; j++) {
        st.modify(d[j], d[j], sz - j - 1);
      }
    }
    {
      vector<int> d;
      for (int k : divs[2 * i]) {
        if (i != k) {
          d.push_back(k);
        }
      }
      reverse(d.begin(), d.end());
      while (!d.empty() && d.back() < i / 4) {
        d.pop_back();
      }
      reverse(d.begin(), d.end());
      int sz = (int) d.size();
      for (int i1 = 0; i1 < sz; i1++) {
        for (int i2 = i1 + 1; i2 < sz; i2++) {
          if ((i % d[i1] == 0) + (i % d[i2] == 0) != 2 && d[i1] + d[i2] > i) {
            assert(d[i1] < d[i2]);
            st.modify(d[i1], d[i1], +1);
          }
        }
      }
    }
    for (auto& p : qs[i]) {
      ans[p.second] -= st.get(p.first, i).s;
    }
  }
  for (int i = 0; i < qq; i++) {
    cout << ans[i] << '\n';
  }                                    
  return 0;
}