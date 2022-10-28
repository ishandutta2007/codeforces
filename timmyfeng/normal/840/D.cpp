#include <bits/stdc++.h>
using namespace std;

struct wavelet_tree {

  struct node {

    node *right = nullptr;
    node *left = nullptr;

    vector<int> sum;

    void apply(const vector<int> &v, int m) {
      sum.resize(v.size() + 1u);
      for (int i = 0; i < (int) v.size(); ++i) {
        sum[i + 1] = sum[i] + (v[i] <= m);
      }
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

  wavelet_tree(const vector<int> &a) : n(a.size()) {
    root = new node();
    build(root, 1, n, a);
  }

  void build(node *u, int l, int r, const vector<int> &v) {
    if (v.empty()) {
      return;
    }

    int m = (l + r) / 2;
    u->apply(v, m);
    if (l == r) {
      return;
    }

    vector<int> vl, vr;
    for (auto i : v) {
      if (i <= m) {
        vl.push_back(i);
      } else {
        vr.push_back(i);
      }
    }

    u->push();
    build(u->left, l, m, vl);
    build(u->right, m + 1, r, vr);
  }

  int query(node *u, int l, int r, int a, int b, int k) {
    if (b - a <= k) {
      return -1;
    } else if (l == r) {
      return l;
    } else {
      int m = (l + r) / 2;
      int x = query(u->left, l, m, u->sum[a], u->sum[b], k);
      if (x == -1) {
        return query(u->right, m + 1, r, a - u->sum[a], b - u->sum[b], k);
      } else {
        return x;
      }
    }
  }

  int query(int a, int b, int k) {
    return query(root, 1, n, a, b, k);
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }

  wavelet_tree tree(a);

  for (int i = 0; i < q; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << tree.query(l - 1, r, (r - l + 1) / k) << "\n";
  }
}