#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int ans[N];
int a[N];

struct node {

  int mn, ndx, lazy;

  void apply(int a, bool b) {
    if (b) {
      mn += a;
      lazy += a;
    } else {
      mn = a;
      lazy = 0;
    }
  }

  node combine(const node& oth) {
    if (mn < oth.mn) {
      return {mn, ndx, 0};
    }
    return {oth.mn, oth.ndx, 0};
  }

  void push(node& a, node& b) {
    a.apply(lazy, true);
    b.apply(lazy, true);
    lazy = 0;
  }

};

template <class T>
struct segment_tree {

  T tree[4 * N];

  void build(int v, int l, int r) {
    if (l == r) {
      tree[v] = T();
      tree[v].ndx = l;
    } else {
      int m = (l + r) / 2;
      build(v * 2, l, m);
      build(v * 2 + 1, m + 1, r);
      tree[v] = tree[v * 2].combine(tree[v * 2 + 1]);
    }
  }

  template <class... S>
  void update(int v, int l, int r, int a, int b, const S&... val) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      tree[v].apply(val...);
    } else {
      tree[v].push(tree[v * 2], tree[v * 2 + 1]);
      int m = (l + r) / 2;
      update(v * 2, l, m, a, b, val...);
      update(v * 2 + 1, m + 1, r, a, b, val...);
      tree[v] = tree[v * 2].combine(tree[v * 2 + 1]);
    }
  }

  T query(int v, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return tree[v];
    } else {
      tree[v].push(tree[v * 2], tree[v * 2 + 1]);
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return query(v * 2, l, m, a, b).combine(query(v * 2 + 1, m + 1, r, a, b));
      } else if (a <= m) {
        return query(v * 2, l, m, a, b);
      } else {
        return query(v * 2 + 1, m + 1, r, a, b);
      }
    }
  }

  T query(int l, int r) {
    return query(1, 1, N, l, r);
  }

  void update(int l, int r, int a) {
    update(1, 1, N, l, r, a, true);
  }

  void update(int l, int a) {
    update(1, 1, N, l, l, a, false);
  }

};

segment_tree<node> st;

template <class T>
struct fenwick {

  T tree[N];

  void update(int a, T val) {
    for ( ; a < N; a += a & -a) {
      tree[a] += val;
    }
  }

  T query(int a) {
    T res = 0;
    for ( ; a; a -= a & -a) {
      res += tree[a];
    }
    return res;
  }

};

fenwick<int> fenw;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = i - a[i];
    if (a[i] < 0) {
      a[i] = n + 1;
    }
  }

  vector<array<int, 3>> queries;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    queries.push_back({x, y, i});
  }
  sort(queries.begin(), queries.end());

  int cnt = 0;
  st.build(1, 1, N);
  for (int i = 1; i <= n; ++i) {
    a[i] = cnt - a[i];
    if (a[i] >= 0) {
      ++cnt;
      fenw.update(i, 1);
      st.update(i, a[i]);
    } else {
      st.update(i, n + 1);
    }
  }

  int ptr = 0;
  for (int i = 0; i < n; ++i) {
    while (ptr < q && queries[ptr][0] == i) {
      auto [x, y, j] = queries[ptr];
      ans[j] = fenw.query(n - y);
      ++ptr;
    }

    if (fenw.query(i + 1) - fenw.query(i) > 0) {
      st.update(i + 1, n + 1);
      fenw.update(i + 1, -1);
      st.update(i + 1, n, -1);
    }

    while (true) {
      auto res = st.query(1, n);
      if (res.mn >= 0) {
        break;
      }
      st.update(res.ndx, n + 1);
      fenw.update(res.ndx, -1);
      st.update(res.ndx, n, -1);
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}