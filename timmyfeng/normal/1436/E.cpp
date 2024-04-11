#include <bits/stdc++.h>
using namespace std;

struct segtree {

  struct node {

    node *right = nullptr;
    node *left = nullptr;
    int max_a;

    void apply(int a) {
      max_a = a;
    }

    void pull() {
      max_a = max(right->max_a, left->max_a);
    }

    void push() {
      if (left == nullptr) {
        right = new node();
        left = new node();
      }
    }

  };

  node *root;
  int n;

  segtree(int n, int x) : n(n) {
    root = new node();
    build(root, 0, n - 1, x);
  }

  void build(node *u, int l, int r, int x) {
    if (l == r) {
      u->apply(x);
    } else {
      u->push();
      int m = (l + r) / 2;
      build(u->left, l, m, x);
      build(u->right, m + 1, r, x);
      u->pull();
    }
  }

  template <class... S>
  void update(node *u, int l, int r, int a, int b, const S&... args) {
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

  int query(node *u, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return u->max_a;
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

  void update(int a, int x) {
    update(root, 0, n - 1, a, a, x);
  }

  int query(int a) {
    return query(root, 0, n - 1, 0, a);
  }

};

const int N = 100000 + 1;

vector<int> indices[N];
bool ok[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int max_a = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    max_a = max(max_a, a[i]);
    indices[--a[i]].push_back(i);
  }

  vector<array<int, 3>> queries;
  for (int i = 0; i <= max_a; ++i) {
    if (indices[i].empty()) {
      queries.push_back({0, n, i});
    } else {
      queries.push_back({0, indices[i][0], i});
      for (int j = 1; j < (int) indices[i].size(); ++j) {
        queries.push_back({indices[i][j - 1], indices[i][j], i});
      }
      queries.push_back({indices[i].back(), n, i});
    }
  }
  sort(queries.rbegin(), queries.rend());

  int index = n;
  segtree nxt(max_a + 1, n);
  for (auto [l, r, x] : queries) {
    while (index > l) {
      --index;
      nxt.update(a[index], index);
    }
    ok[x] |= ((x == 0 && l + 1 < r) || (x != 0 && nxt.query(x - 1) < r));
  }

  int ans = 0;
  while (ans <= max_a && ok[ans]) {
    ++ans;
  }

  cout << ans + 1 << "\n";
}