#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;
const int L = 18;

pair<int, int> range[N];
int respect[N];
int n;

struct segment_tree {

  struct node {
    int l, r;
    void apply(int _l, int _r, int a, int b) {
      l = max(0, a);
      r = min(3 * n - 1, b);
      range[_l] = {l, r};
    }
  } tree[N * 4];

  node combine(const node& a, const node& b) {
    node c;
    c.l = min(a.l, b.l);
    c.r = max(a.r, b.r);
    return c;
  }

  void push(int v, int l, int r) {
    int m = (l + r) / 2;
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

  template <class... T>
  void update(int a, const T&... val) {
    update(1, 0, N - 1, a, a, val...);
  }

  node query(int a, int b) {
    return query(1, 0, N - 1, a, b);
  }

} st[L];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> respect[i];
  }

  if (n == 1) {
    cout << 0 << "\n";
    exit(0);
  }

  for (int i = 0; i < 3 * n; ++i) {
    st[0].update(i, i - respect[i % n], i + respect[i % n]);
  }

  int log_n = 1;
  for ( ; (1 << log_n) < 2 * n; ++log_n) {
    for (int i = 0; i < 3 * n; ++i) {
      auto res = st[log_n - 1].query(range[i].first, range[i].second);
      st[log_n].update(i, res.l, res.r);
    }
  }

  for (int i = 0; i < n; ++i) {
    int l = n + i;
    int r = n + i;
    int ans = 0;
    for (int j = log_n - 1; j >= 0; --j) {
      auto res = st[j].query(l, r);
      if (res.r - res.l + 1 < n) {
        l = res.l;
        r = res.r;
        ans += 1 << j;
      }
    }
    cout << ans + 1 << " ";
  }
  cout << "\n";
}