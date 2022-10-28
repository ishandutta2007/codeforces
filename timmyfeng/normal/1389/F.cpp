#include <bits/stdc++.h>
using namespace std;

const int N = 4e5;

struct segment_tree {

  struct node {
    int lazy, val;
    void apply(int l, int r, int a, bool range) {
      if (range) {
        lazy += a;
        val += a;
      } else {
        val = max(val, a);
      }
    }
  } tree[4 * N];

  node combine(const node& a, const node& b) {
    node c;
    c.val = max(a.val, b.val);
    return c;
  }

  void push(int v, int l, int r) {
    int m = (l + r) / 2;
    tree[v * 2].apply(l, m, tree[v].lazy, true);
    tree[v * 2 + 1].apply(m + 1, r, tree[v].lazy, true);
    tree[v].lazy = 0;
  }

  void pull(int v) {
    tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
  }

  template <class... T>
  void update(int v, int l, int r, int a, int b, const T&... val) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      tree[v].apply(l, r, val...);
    } else {
      push(v, l, r);
      int m = (l + r) / 2;
      update(v * 2, l, m, a, b, val...);
      update(v * 2 + 1, m + 1, r, a, b, val...);
      pull(v);
    }
  }

  node query(int v, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return tree[v];
    } else {
      push(v, l, r);
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return combine(query(v * 2, l, m, a, b), query(v * 2 + 1, m + 1, r, a, b));
      } else if (a <= m) {
        return query(v * 2, l, m, a, b);
      } else {
        return query(v * 2 + 1, m + 1, r, a, b);
      }
    }
  }

  void update(int a, int b, int val, bool range) {
    update(1, 1, N, a, b, val, range);
  }

  node query(int a, int b) {
    if (a > b)
      return node();
    return query(1, 1, N, a, b);
  }

} st[2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> ndx;
  vector<tuple<int, int, int>> segments;
  for (int i = 0; i < n; ++i) {
    int l, r, t;
    cin >> l >> r >> t;
    ndx.push_back(l);
    ndx.push_back(r);
    segments.emplace_back(l, r, t - 1);
  }

  sort(ndx.begin(), ndx.end());
  ndx.resize(unique(ndx.begin(), ndx.end()) - ndx.begin());

  for (auto& [l, r, t] : segments) {
    l = lower_bound(ndx.begin(), ndx.end(), l) - ndx.begin() + 1;
    r = lower_bound(ndx.begin(), ndx.end(), r) - ndx.begin() + 1;
  }
  sort(segments.begin(), segments.end());

  for (auto [l, r, t] : segments) {
    int val = max(st[t].query(1, r - 1).val, st[t ^ 1].query(1, l - 1).val) + 1;
    st[t].update(r, ndx.size(), 1, true);
    st[t].update(r, r, val, false);
  }

  cout << max(st[0].tree[1].val, st[1].tree[1].val) << "\n";
}