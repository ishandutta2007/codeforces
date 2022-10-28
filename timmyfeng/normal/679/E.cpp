#include <bits/stdc++.h>
using namespace std;

const int L = 10;

long long pow42[L];

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  array<long long, 2> mini, maxi;
  long long lazy_add, lazy_set;

  void apply_set(long long value) {
    lazy_add = 0;
    lazy_set = value;
    for (int i = 0; i < L; ++i) {
      if (value <= pow42[i]) {
        mini = maxi = {pow42[i] - value, i};
        break;
      }
    }
  }

  void apply_add(long long value) {
    lazy_add += value;
    mini[0] -= value;
    maxi[0] -= value;
  }

  void pull() {
    maxi = max(left->maxi, right->maxi);
    mini = min(left->mini, right->mini);
  }

  void push() {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }

    if (lazy_set > 0) {
      right->apply_set(lazy_set);
      left->apply_set(lazy_set);
      lazy_set = 0;
    }

    if (lazy_add > 0) {
      right->apply_add(lazy_add);
      left->apply_add(lazy_add);
      lazy_add = 0;
    }
  }

  void set(int a, int b, long long value, int l, int r) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      apply_set(value);
    } else {
      push();
      int m = (l + r) / 2;
      left->set(a, b, value, l, m);
      right->set(a, b, value, m + 1, r);
      pull();
    }
  }

  void add(int a, int b, long long value, int l, int r) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b && mini[0] >= value) {
      apply_add(value);
    } else if (a <= l && r <= b && mini == maxi) {
      set(a, b, value + pow42[mini[1]] - mini[0], l, r);
    } else {
      push();
      int m = (l + r) / 2;
      left->add(a, b, value, l, m);
      right->add(a, b, value, m + 1, r);
      pull();
    }
  }

  long long query(int a, int l, int r) {
    if (l == r) {
      return pow42[mini[1]] - mini[0];
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m) {
        return left->query(a, l, m);
      } else {
        return right->query(a, m + 1, r);
      }
    }
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  pow42[0] = 42;
  for (int i = 1; i < L; ++i) {
    pow42[i] = pow42[i - 1] * 42;
  }

  segtree *limak = new segtree();

  for (int i = 1; i <= n; ++i) {
    long long a;
    cin >> a;
    limak->set(i, i, a, 1, n);
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      cin >> i;
      cout << limak->query(i, 1, n) << "\n";
    } else if (t == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      limak->set(l, r, x, 1, n);
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      do {
        limak->add(l, r, x, 1, n);
      } while (limak->mini[0] == 0);
    }
  }
}