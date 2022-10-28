#include <bits/stdc++.h>
using namespace std;

struct node {

  int lazy, mx = INT_MIN / 2;
  node* right;
  node* left;

  void apply(int a, bool range) {
    if (range) {
      lazy += a;
      mx += a;
    } else {
      mx = a;
    }
  }

  void pull() {
    mx = max(left->mx, right->mx);
  }

  void push() {
    if (left == nullptr) {
      right = new node();
      left = new node();
    }
    right->apply(lazy, true);
    left->apply(lazy, true);
    lazy = 0;
  }

};

struct segtree {

  node* root;
  int n;

  segtree() {}

  segtree(int n) : n(n) {
    root = new node();
    build(root, 0, n - 1);
  }

  void build(node* u, int l, int r) {
    if (l == r) {
      return;
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

  int query(node* u, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return u->mx;
    } else {
      u->push();
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return max(query(u->left, l, m, a, b), query(u->right, m + 1, r, a, b));
      } else if (a <= m) {
        return query(u->left, l, m, a, b);
      } else {
        return query(u->right, m + 1, r, a, b);
      }
    }
  }

  int query(int a, int b) {
    return query(root, 0, n - 1, a, b);
  }

  void update(int a, int x) {
    update(root, 0, n - 1, a, a, x, false);
  }

  void update(int a, int b, int x) {
    update(root, 0, n - 1, a, b, x, true);
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
    --i;
  }

  vector<segtree> st(k);
  for (auto &i : st) {
    i = segtree(n);
  }
  st[0].update(0, 0);

  vector<int> pre(n);
  for (int i = 1; i <= n; ++i) {
    if (pre[a[i - 1]] != 0) {
      for (auto &j : st) {
        j.update(0, pre[a[i - 1]] - 1, -1);
      }
    }
    pre[a[i - 1]] = i;

    if (i < n) {
      for (int j = 1; j < k; ++j) {
        st[j].update(i, st[j - 1].query(0, i - 1));
      }
    }
  }

  cout << st[k - 1].root->mx + n << "\n";
}