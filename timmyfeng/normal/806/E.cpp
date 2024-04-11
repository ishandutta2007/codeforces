#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned long long) new char);

struct treap {
  int weight, size, lazy, min, key, val;
  treap *right = nullptr, *left = nullptr;

  treap(int k) : weight(rng()), size(1), min(k), key(k), val(k) {}
};

int size(treap *v) {
  return (v == nullptr) ? 0 : v->size;
}

int min(treap *v) {
  return (v == nullptr) ? INT_MAX : v->min;
}

void apply(treap *v, int k) {
  if (v != nullptr) {
    v->lazy += k;
    v->val += k;
    v->min += k;
  }
}

void push(treap *v) {
  if (v->lazy != 0) {
    apply(v->left, v->lazy);
    apply(v->right, v->lazy);
    v->lazy = 0;
  }
}

void pull(treap *v) {
  v->size = size(v->left) + size(v->right) + 1;
  v->min = min({v->val, min(v->left), min(v->right)});
}

void split(treap *v, treap *&l, treap *&r, int k) {
  if (v == nullptr) {
    l = nullptr;
    r = nullptr;
  } else {
    push(v);
    if (k < v->key) {
      split(v->left, l, v->left, k);
      r = v;
    } else {
      split(v->right, v->right, r, k);
      l = v;
    }
    pull(v);
  }
}

void merge(treap *&v, treap *l, treap *r) {
  if (l == nullptr) {
    v = r;
  } else if (r == nullptr) {
    v = l;
  } else {
    push(l);
    push(r);
    if (l->weight > r->weight) {
      merge(l->right, l->right, r);
      v = l;
    } else {
      merge(r->left, l, r->left);
      v = r;
    }
    pull(v);
  }
}

void split_zero(treap *v, treap *&l, treap *&r, int index) {
  if (v == nullptr) {
    l = nullptr;
    r = nullptr;
  } else {
    push(v);
    if (v->key < -index - size(v->left)) {
      split_zero(v->right, v->right, r, index + size(v->left) + 1);
      l = v;
    } else {
      split_zero(v->left, l, v->left, index);
      r = v;
    }
    pull(v);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  treap *root = nullptr, *left, *right;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    split(root, root, right, a);
    apply(root, 1);
    left = new treap(a);
    apply(left, size(right));
    merge(root, root, left);
    merge(root, root, right);

    split_zero(root, left, right, 0);
    cout << min(size(right) - size(left), min(right)) << "\n";
    merge(root, left, right);
  }
}