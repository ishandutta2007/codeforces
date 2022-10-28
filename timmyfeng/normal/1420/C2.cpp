#include <bits/stdc++.h>
using namespace std;

const int N = 300'000;

int a[N];

struct node {

  node* right;
  node* left;

  long long best[2][2];

  void apply(int a) {
    best[0][0] = 0;
    best[0][1] = a; 
    best[1][0] = -a;
    best[1][1] = 0;
  }

  void pull() {
    for (auto i : {0, 1}) {
      for (auto j : {0, 1}) {
        best[i][j] = LLONG_MIN;
        for (auto k : {0, 1}) {
          best[i][j] = max(best[i][j], left->best[i][k] + right->best[k][j]);
        }
      }
    }
  }

  void push() {
    if (left == nullptr) {
      right = new node();
      left = new node();
    }
  }

};

struct segtree {

  node* root;
  int n;

  segtree(int n) : n(n) {
    root = new node();
    build(root, 0, n - 1);
  }

  void build(node* u, int l, int r) {
    if (l == r) {
      u->apply(a[l]);
    } else {
      u->push();
      int m = (l + r) / 2;
      build(u->left, l, m);
      build(u->right, m + 1, r);
      u->pull();
    }
  }

  template <class... S>
  void update(node* u, int l, int r, int a, int b, const S&... args) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      u->apply(args...);
    } else {
      u->push();
      int m = (l + r) / 2;
      update(u->left, l, m, a, b, args...);
      update(u->right, m + 1, r, a, b, args...);
      u->pull();
    }
  }

  void update(int a, int x) {
    update(root, 0, n - 1, a, a, x);
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    segtree army(n);

    for (int i = 0; i <= q; ++i) {
      if (i > 0) {
        int l, r;
        cin >> l >> r;
        swap(a[--l], a[--r]);
        army.update(l, a[l]);
        army.update(r, a[r]);
      }
      cout << max(army.root->best[0][0], army.root->best[0][1]) << "\n";
    }
  }
}