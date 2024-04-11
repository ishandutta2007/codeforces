/**
 *    author:  tourist
 *    created: 08.05.2022 18:52:51       
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
    long long add_k = 0;
    long long add_b = 0;
    long long sum_k = 0;
    long long sum_b = 0;

    void apply(int l, int r, long long vk, long long vb) {
      add_k += vk;
      add_b += vb;
      sum_k += vk * (r - l + 1);
      sum_b += vb * (r - l + 1);
    }
  };

  node unite(const node &a, const node &b) const {
    node res;
    res.sum_k = a.sum_k + b.sum_k;
    res.sum_b = a.sum_b + b.sum_b;
    return res;
  }

  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].add_k != 0 || tree[x].add_b) {
      tree[x + 1].apply(l, y, tree[x].add_k, tree[x].add_b);
      tree[z].apply(y + 1, r, tree[x].add_k, tree[x].add_b);
      tree[x].add_k = tree[x].add_b = 0;
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
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
    pos[p[i]] = i;
  }
  vector<int> ql(q), qr(q);
  vector<vector<int>> at(n + 1);
  vector<long long> res(q);
  for (int i = 0; i < q; i++) {
    cin >> ql[i] >> qr[i];
    --ql[i]; --qr[i];
    at[ql[i]].push_back(~i);
    at[qr[i] + 1].push_back(i);
  }
  vector<int> cl(n, -1);
  {
    vector<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && p[st.back()] < p[i]) {
        st.pop_back();
      }
      cl[i] = (st.empty() ? -1 : st.back());
      st.push_back(i);
    }
  }
  vector<int> cr(n, n);
  {
    vector<int> st;
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && p[st.back()] < p[i]) {
        st.pop_back();
      }
      cr[i] = (st.empty() ? n : st.back());
      st.push_back(i);
    }
  }
  vector<vector<pair<int, int>>> all(n);
  for (int x = 1; x < n; x++) {
    for (int y = 0; y < x && (x + 1) * (y + 1) <= n; y++) {
      int z = (x + 1) * (y + 1) - 1;
      int L = min(pos[x], min(pos[y], pos[z]));
      int R = max(pos[x], max(pos[y], pos[z]));
      if (cl[pos[z]] < L && cr[pos[z]] > R) {
        all[pos[z]].emplace_back(L, ~R);
      }
    }
  }
  vector<vector<array<int, 3>>> ev(n + 1);
  for (int i = 0; i < n; i++) {
    sort(all[i].begin(), all[i].end());
    for (auto& s : all[i]) {
      s.second = ~s.second;
    }
    int ptr = 0;
    for (int j = 0; j < (int) all[i].size(); j++) {
      while (ptr > 0 && all[i][ptr - 1].second >= all[i][j].second) {
        ptr -= 1;
      }
      all[i][ptr++] = all[i][j];
    }
    all[i].resize(ptr);
    int last = cl[i];
    for (auto& s : all[i]) {
      ev[last + 1].push_back({s.second, cr[i] - 1, +1});
      ev[s.first + 1].push_back({s.second, cr[i] - 1, -1});
      last = s.first;
    }
  }
  segtree st(n);
  for (int i = 0; i <= n; i++) {
    for (auto& s : ev[i]) {
      st.modify(s[0], s[1], +1 * s[2], -i * s[2]);
    }
    for (int id : at[i]) {
      int coeff = 1;
      if (id < 0) {
        id = ~id;
        coeff = -1;
      }
      auto nd = st.get(ql[id], qr[id]);
      res[id] += coeff * (nd.sum_k * i + nd.sum_b);
    }
  }
  for (int i = 0; i < q; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}