#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  long long sum = 0;
  int maximum = 0;
  int lazy = 0;

  void apply(int value, int l, int r) {
    sum = (long long) value * (r - l + 1);
    maximum = value;
    lazy = value;
  }

  void pull() {
    sum = right->sum + left->sum;
    maximum = max(right->maximum, left->maximum);
  }

  void push(int l, int r) {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }

    if (lazy != 0) {
      int m = (l + r) / 2;
      right->apply(lazy, m + 1, r);
      left->apply(lazy, l, m);
      lazy = 0;
    }
  }

  void update(int a, int b, int value, int l, int r) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      apply(value, l, r);
    } else {
      push(l, r);
      int m = (l + r) / 2;
      left->update(a, b, value, l, m);
      right->update(a, b, value, m + 1, r);
      pull();
    }
  }

  int find_max(int value, int l, int r) {
    if (l == r) {
      return maximum > value ? l + 1 : l;
    } else {
      push(l, r);
      int m = (l + r) / 2;
      if (right->maximum > value) {
        return right->find_max(value, m + 1, r);
      } else {
        return left->find_max(value, l, m);
      }
    }
  }

  int find_sum(int a, int &value, int l, int r) {
    if (a <= l && sum <= value) {
      value -= sum;
      return r;
    } else if (l == r) {
      return l - 1;
    }

    push(l, r);
    int m = (l + r) / 2;
    if (a <= m) {
      int b = left->find_sum(a, value, l, m);
      if (b < m) {
        return b;
      }
    }
    return right->find_sum(a, value, m + 1, r);
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  segtree *shops = new segtree();
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    shops->update(i, i, a, 1, n);
  }

  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;

    if (t == 1) {
      int z = shops->find_max(y, 1, n);
      if (z <= x) {
        shops->update(z, x, y, 1, n);
      }
    } else {
      int ans = 0;
      while (x <= n) {
        int z = max(x, shops->find_max(y, 1, n));
        if (z <= n) {
          int a = shops->find_sum(z, y, 1, n);
          ans += a - z + 1;
          x = a + 1;
        } else {
          break;
        }
      }
      cout << ans << "\n";
    }
  }
}