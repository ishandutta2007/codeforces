#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned long long) new char);

const int N = 100000 + 1;
const int M = 1000000007;

long long base[N];

struct treap_node {

  shared_ptr<treap_node> left, right;
  int weight, size;
  int value, code;

  treap_node(int x) {
    left = right = nullptr;
    value = code = x;
    weight = rng();
    size = 1;
  }

};

using treap = shared_ptr<treap_node>;

int size(const treap &u) {
  return (u == nullptr) ? 0 : u->size;
}

int code(const treap &u) {
  return (u == nullptr) ? 0 : u->code;
}

void pull(const treap &u) {
  u->size = size(u->left) + 1 + size(u->right);
  u->code = code(u->left) + base[size(u->left)] * (u->value + base[1] * code(u->right) % M) % M;
  if (u->code >= M) {
    u->code -= M;
  }
}

void split(treap u, treap &l, treap &r, int x, int b = 0) {
  if (u == nullptr) {
    l = r = nullptr;
    return;
  }

  treap v = make_shared<treap_node>(0);
  *v = *u;
  b += size(v->left);
  if (b < x) {
    split(v->right, v->right, r, x, b + 1);
    l = v;
  } else {
    split(v->left, l, v->left, x, b - size(v->left));
    r = v;
  }
  pull(v);
}

void merge(treap &u, treap l, treap r) {
  if (l == nullptr || r == nullptr) {
    u = (l == nullptr) ? r : l;
    return;
  }

  treap v = make_shared<treap_node>(0);
  if (l->weight > r->weight) {
    *v = *l;
    merge(v->right, v->right, r);
  } else {
    *v = *r;
    merge(v->left, l, v->left);
  }
  u = v;
  pull(v);
}

struct cbs {

  treap prefix, suffix;
  bool ok;

  cbs() {
    prefix = suffix = nullptr;
    ok = true;
  }

  void set(int x) {
    prefix = suffix = nullptr;
    if (x < 0) {
      prefix = make_shared<treap_node>(-x);
    } else {
      suffix = make_shared<treap_node>(x);
    }
    ok = true;
  }

} segtree[2 * N];

cbs concat(cbs a, cbs b) {
  cbs res;
  if (!a.ok || !b.ok) {
    res.ok = false;
    return res;
  }

  int l = min(size(a.suffix), size(b.prefix));

  treap c, d;
  split(a.suffix, c, a.suffix, l);
  split(b.prefix, d, b.prefix, l);

  if (code(c) == code(d)) {
    merge(res.prefix, a.prefix, b.prefix);
    merge(res.suffix, b.suffix, a.suffix);
  } else {
    res.ok = false;
  }

  return res;
}

int n;

void update(int a, int x) {
  a += n - 1;
  segtree[a].set(x);
  for (a /= 2; a > 0; a /= 2) {
    segtree[a] = concat(segtree[2 * a], segtree[2 * a + 1]);
  }
}

cbs query(int a, int b) {
  cbs prefix, suffix;
  for (a += n - 1, b += n - 1; a <= b; a /= 2, b /= 2) {
    if (a % 2 == 1) {
      prefix = concat(prefix, segtree[a++]);
    }
    if (b % 2 == 0) {
      suffix = concat(segtree[b--], suffix);
    }
  }
  return concat(prefix, suffix);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  base[0] = 1;
  base[1] = uniform_int_distribution<int>(N, M - 1)(rng);
  for (int i = 2; i < N; ++i) {
    base[i] = base[i - 1] * base[1] % M;
  }

  int k;
  cin >> n >> k;

  for (int i = n; i < 2 * n; ++i) {
    int s;
    cin >> s;
    segtree[i].set(s);
  }

  for (int i = n - 1; i > 0; --i) {
    segtree[i] = concat(segtree[2 * i], segtree[2 * i + 1]);
  }

  int q;
  cin >> q;

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, t;
      cin >> i >> t;
      update(i, t);
    } else {
      int l, r;
      cin >> l >> r;
      cbs res = query(l, r);
      cout << (res.prefix == nullptr && res.suffix == nullptr && res.ok ? "Yes" : "No") << "\n";
    }
  }
}