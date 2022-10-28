#include <bits/stdc++.h>
using namespace std;

struct node {

  node* right;
  node* left;
  int lazy;
  int cnt;
  int mn;

  void apply(int val) {
    lazy += val;
    mn += val;
  }

  void pull() {
    mn = min(left->mn, right->mn);
    cnt = 0;
    for (auto c : {left, right}) {
      if (c->mn == mn) {
        cnt += c->cnt;
      }
    }
  }

  void push() {
    if (left == nullptr) {
      right = new node();
      left = new node();
    }
    right->apply(lazy);
    left->apply(lazy);
    lazy = 0;
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
      u->cnt = 1;
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

  array<int, 2> query(node* u, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return {u->mn, u->cnt};
    } else {
      u->push();
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        auto res_l = query(u->left, l, m, a, b);
        auto res_r = query(u->right, m + 1, r, a, b);
        if (res_l[0] < res_r[0]) {
          return res_l;
        } else if (res_l[0] > res_r[0]) {
          return res_r;
        } else {
          return {res_l[0], res_l[1] + res_r[1]};
        }
      } else if (a <= m) {
        return query(u->left, l, m, a, b);
      } else {
        return query(u->right, m + 1, r, a, b);
      }
    }
  }

  void update(int a, int b, int val) {
    update(root, 0, n - 1, a, b, val);
  }

  array<int, 2> query(int a, int b) {
    return query(root, 0, n - 1, a, b);
  }

};

const int N = 500'000;

vector<int> pos[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }

  fill(pos, pos + n, vector<int>{-1});
  long long ans = 0;
  segtree st(n);

  for (int i = 0; i < n; ++i) {
    int sz = pos[a[i]].size();
    if (sz >= 3) {
      st.update(pos[a[i]][sz - 3] + 1, pos[a[i]][sz - 2], -1);
      if (sz >= 4) {
        st.update(pos[a[i]][sz - 4] + 1, pos[a[i]][sz - 3], 1);
      }
    }
    st.update(pos[a[i]][sz - 1] + 1, i, 1);
    pos[a[i]].push_back(i);

    auto [mn, cnt] = st.query(0, i);
    if (mn == 0) {
      ans += cnt;
    }
  }

  cout << ans << "\n";
}