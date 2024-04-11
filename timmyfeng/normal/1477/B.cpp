#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *left = nullptr, *right = nullptr;
  int ones, lazy;

  segtree() {
    ones = 0, lazy = -1;
  }

  void apply(int x, int l, int r) {
    ones = x * (r - l + 1);
    lazy = x;
  }

  void pull() {
    ones = left->ones + right->ones;
  }

  void push(int l, int r) {
    if (left == nullptr) {
      left = new segtree();
      right = new segtree();
    }

    int m = (l + r) / 2;
    if (lazy != -1) {
      left->apply(lazy, l, m);
      right->apply(lazy, m + 1, r);
      lazy = -1;
    }
  }

  void update(int a, int b, int x, int l, int r) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      apply(x, l, r);
    } else {
      push(l, r);
      int m = (l + r) / 2;
      left->update(a, b, x, l, m);
      right->update(a, b, x, m + 1, r);
      pull();
    }
  }

  int query(int a, int b, int l, int r) {
    if (b < l || r < a) {
      return 0;
    } else if (a <= l && r <= b) {
      return ones;
    } else {
      push(l, r);
      int m = (l + r) / 2;
      return left->query(a, b, l, m) + right->query(a, b, m + 1, r);
    }
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    string s, f;
    cin >> n >> q >> s >> f;

    segtree *nezzar = new segtree();
    for (int i = 0; i < n; ++i) {
      nezzar->update(i, i, f[i] - '0', 0, n - 1);
    }

    vector<array<int, 2>> queries(q);
    for (auto &[l, r] : queries) {
      cin >> l >> r;
      --l, --r;
    }

    bool ok = true;
    for (int i = q - 1; i >= 0; --i) {
      auto [l, r] = queries[i];
      int ones = nezzar->query(l, r, 0, n - 1);
      ok &= (2 * ones != r - l + 1);
      nezzar->update(l, r, (2 * ones > r - l + 1), 0, n - 1);
    }

    for (int i = 0; i < n; ++i) {
      ok &= (s[i] - '0' == nezzar->query(i, i, 0, n - 1));
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }
}