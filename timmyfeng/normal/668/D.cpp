#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned long long) new char);

struct treap {

  treap *left, *right;
  int key, weight, size;

  treap(int x) {
    left = right = nullptr;
    weight = rng();
    key = x;
  }

};

int size(treap *u) {
  return (u == nullptr) ? 0 : u->size;
}

void pull(treap *u) {
  if (u != nullptr) {
    u->size = 1 + size(u->left) + size(u->right);
  }
}

void split(treap *u, int x, treap *&l, treap *&r) {
  if (u == nullptr) {
    l = r = nullptr;
  } else if (u->key < x) {
    split(u->right, x, u->right, r);
    l = u;
  } else {
    split(u->left, x, l, u->left);
    r = u;
  }
  pull(l), pull(r);
}

void merge(treap *&u, treap *l, treap *r) {
  if (l == nullptr || r == nullptr) {
    u = (l == nullptr) ? r : l;
  } else if (l->weight > r->weight) {
    merge(l->right, l->right, r);
    u = l;
  } else {
    merge(r->left, l, r->left);
    u = r;
  }
  pull(u);
}

void insert(treap *&u, treap *x) {
  if (u == nullptr) {
    u = x;
  } else if (x->weight > u->weight) {
    split(u, x->key, x->left, x->right);
    u = x;
  } else {
    insert((x->key < u->key) ? u->left : u->right, x);
  }
  pull(u);
}

void erase(treap *&u, int x) {
  if (u == nullptr) {
    return;
  } else if (u->key == x) {
    merge(u, u->left, u->right);
  } else {
    erase((x < u->key) ? u->left : u->right, x);
  }
  pull(u);
}

bool contains(treap *u, int x) {
  if (u == nullptr) {
    return false;
  } else if (u->key == x) {
    return true;
  } else {
    return contains((x < u->key) ? u->left : u->right, x);
  }
}

string to_string(treap *u) {
  if (u == nullptr) {
    return "";
  } else {
    return to_string(u->left) + to_string(u->key) + " " + to_string(u->right);
  }
}

const int N = 100000;

treap *insertions[N], *deletions[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<int, int> id;

  for (int i = 0; i < n; ++i) {
    int a, t, x;
    cin >> a >> t >> x;

    if (id.count(x) == 0) {
      int y = id.size();
      id[x] = y;
    }
    x = id[x];

    if (a == 1) {
      insert(insertions[x], new treap(t));
    } else if (a == 2) {
      insert(deletions[x], new treap(t));
    } else {
      int ans = 0;
      treap *l, *r;
      split(insertions[x], t, l, r);
      ans += size(l);
      merge(insertions[x], l, r);
      split(deletions[x], t, l, r);
      ans -= size(l);
      merge(deletions[x], l, r);
      cout << ans << "\n";
    }
  }
}