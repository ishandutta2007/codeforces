#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;
  int max_a;
  int lazy;

  void apply(int value) {
    max_a += value;
    lazy += value;
  }

  void pull() {
    max_a = max(left->max_a, right->max_a);
  }

  void push() {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }
    left->apply(lazy);
    right->apply(lazy);
    lazy = 0;
  }

  void update(int a, int b, int value, int l, int r) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      apply(value);
    } else {
      push();
      int m = (l + r) / 2;
      left->update(a, b, value, l, m);
      right->update(a, b, value, m + 1, r);
      pull();
    }
  }

  int query(int a, int b, int l, int r) {
    if (a <= l && r <= b) {
      return max_a;
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return max(left->query(a, b, l, m), right->query(a, b, m + 1, r));
      } else if (a <= m) {
        return left->query(a, b, l, m);
      } else {
        return right->query(a, b, m + 1, r);
      }
    }
  }

};

const int N = 100000 + 1;

int value[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  value[0] = -1;
  segtree *balance = new segtree();
  for (int i = 0; i < n; ++i) {
    int a, type;
    cin >> a >> type;

    if (type == 1) {
      balance->update(1, a, 1, 1, n);
      cin >> value[a];
    } else {
      balance->update(1, a, -1, 1, n);
    }

    int lo = 0;
    int hi = n;

    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      if (balance->query(mid, n, 1, n) > 0) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }

    cout << value[lo] << "\n";
  }
}