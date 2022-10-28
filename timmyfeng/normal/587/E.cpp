#include <bits/stdc++.h>
using namespace std;

const int L = 30;

struct parity_basis {

  vector<int> even, odd;
  int size;

  parity_basis() : even(L), size(0) {}

  bool basis(int y) {
    for (int i = 0; i < L; ++i) {
      if ((y & (1 << i)) > 0) {
        if (even[i] == 0) {
          even[i] = y;
          ++size;
          return false;
        }
        y ^= even[i];
      }
    }
    return true;
  }

  void update(int x) {
    bool add = true;
    for (auto y : odd) {
      add &= !basis(x ^ y);
    }

    if (add) {
      odd.push_back(x);
    }
  }

  void merge(parity_basis oth) {
    for (auto i : oth.even) {
      if (i > 0) {
        basis(i);
      }
    }

    for (auto i : oth.odd) {
      update(i);
    }
  }

};

struct segtree {

  segtree *left = nullptr, *right = nullptr;
  parity_basis value;
  int lazy = 0;

  void apply(int x) {
    for (auto &i : value.odd) {
      i ^= x;
    }
    lazy ^= x;
  }

  void pull() {
    value = left->value;
    value.merge(right->value);
  }

  void push() {
    if (lazy != 0) {
      left->apply(lazy);
      right->apply(lazy);
      lazy = 0;
    }
  }

  segtree(int l, int r, int *a) {
    if (l == r) {
      value.update(a[l]);
    } else {
      int m = (l + r) / 2;
      left = new segtree(l, m, a);
      right = new segtree(m + 1, r, a);
      pull();
    }
  }

  void update(int a, int b, int x, int l, int r) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      apply(x);
    } else {
      push();
      int m = (l + r) / 2;
      left->update(a, b, x, l, m);
      right->update(a, b, x, m + 1, r);
      pull();
    }
  }

  parity_basis query(int a, int b, int l, int r) {
    if (a <= l && r <= b) {
      return value;
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        parity_basis temp = left->query(a, b, l, m);
        temp.merge(right->query(a, b, m + 1, r));
        return temp;
      } else if (a <= m) {
        return left->query(a, b, l, m);
      } else {
        return right->query(a, b, m + 1, r);
      }
    }
  }

};

const int N = 200000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  segtree *tree = new segtree(0, n - 1, a);

  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l, --r;

    if (t == 1) {
      int k;
      cin >> k;
      tree->update(l, r, k, 0, n - 1);
    } else {
      parity_basis ans = tree->query(l, r, 0, n - 1);

      for (auto i : ans.odd) {
        ans.basis(i);
      }

      cout << (1 << ans.size) << "\n";
    }
  }
}