#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int a[1 << N];
bool lazy[N];

struct node {
  int64_t sum = 0;

  void apply(int x) {
    sum = x;
  }

  node combine(const node& oth) {
    node res;
    res.sum = sum + oth.sum;
    return res;
  }

  void push(node& a, node& b) {}
};

template <class T>
struct dynamic_tree {

  dynamic_tree<T>* left;
  dynamic_tree<T>* right;
  bool orientation = false;
  int layer = 0;
  T data;

  void build(int l, int r) {
    if (l == r) {
      data.apply(a[l]);
    } else {
      int m = (l + r) / 2;

      left = new dynamic_tree<T>();
      left->layer = layer - 1;
      left->build(l, m);

      right = new dynamic_tree<T>();
      right->layer = layer - 1;
      right->build(m + 1, r);

      data = left->data.combine(right->data);
    }
  }

  template <class... S>
  void update(int l, int r, int a, int b, const S&... val) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      data.apply(val...);
    } else {
      int m = (l + r) / 2;
      data.push(left->data, right->data);

      if (orientation != lazy[layer]) {
        swap(left, right);
        orientation ^= true;
      }

      left->update(l, m, a, b, val...);
      right->update(m + 1, r, a, b, val...);
      data = left->data.combine(right->data);
    }
  }

  T query(int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return data;
    } else {
      data.push(left->data, right->data);

      if (orientation != lazy[layer]) {
        swap(left, right);
        orientation ^= true;
      }

      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return left->query(l, m, a, b).combine(right->query(m + 1, r, a, b));
      } else if (a <= m) {
        return left->query(l, m, a, b);
      } else {
        return right->query(m + 1, r, a, b);
      }
    }
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= (1 << n); ++i) {
    cin >> a[i];
  }

  dynamic_tree<node>* st = new dynamic_tree<node>();
  st->layer = n;
  st->build(1, 1 << n);

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, k;
      cin >> x >> k;
      st->update(1, 1 << n, x, x, k);
    } else if (type == 2) {
      int k;
      cin >> k;
      for (int i = 1; i <= k; ++i) {
        lazy[i] ^= true;
      }
    } else if (type == 3) {
      int k;
      cin >> k;
      lazy[k + 1] ^= true;
    } else {
      int l, r;
      cin >> l >> r;
      cout << st->query(1, 1 << n, l, r).sum << "\n";
    }
  }
}