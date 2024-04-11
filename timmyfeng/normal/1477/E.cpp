#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct treap {

  treap *left, *right;
  int weight, size;
  long long sum;
  int value;

  treap(int x) {
    left = right = nullptr;
    sum = value = x;
    weight = rng();
    size = 1;
  }

};

int size(treap *u) {
  return u ? u->size : 0;
}

long long sum(treap *u) {
  return u ? u->sum : 0;
}

void pull(treap *u) {
  u->size = size(u->left) + 1 + size(u->right);
  u->sum = sum(u->left) + u->value + sum(u->right);
}

void split(treap *u, treap *&l, treap *&r, int x) {
  if (!u) {
    l = r = nullptr;
    return;
  }

  if (u->value < x) {
    split(u->right, u->right, r, x);
    l = u;
  } else {
    split(u->left, l, u->left, x);
    r = u;
  }
  pull(u);
}

void merge(treap *&u, treap *l, treap *r) {
  if (!l || !r) {
    u = l ? l : r;
    return;
  }

  if (l->weight > r->weight) {
    merge(l->right, l->right, r);
    u = l;
  } else {
    merge(r->left, l, r->left);
    u = r;
  }
  pull(u);
}

const int N = 200000 + 1;

treap *one, *two;
int a[N], b[N];

int begin(treap *u) {
  return u->left ? begin(u->left) : u->value;
}

int end(treap *u) {
  return u->right ? end(u->right) : u->value;
}

int before(treap *u, int x) {
  treap *l;
  split(u, l, u, x + 1);
  int res = end(l);
  merge(u, l, u);
  return res;
}

int after(treap *u, int x) {
  treap *l;
  split(u, l, u, x);
  int res = begin(u);
  merge(u, l, u);
  return res;
}

void insert(treap *&u, int x) {
  treap *l;
  split(u, l, u, x);
  merge(u, new treap(x), u);
  merge(u, l, u);
}

void erase(treap *&u, int x) {
  if (u->value == x) {
    merge(u, u->left, u->right);
  } else {
    erase((x < u->value) ? u->left : u->right, x);
    pull(u);
  }
}

long long calc(int k, int s, bool o) {
  long long res = 0;
  int delta = s - k;
  treap *temp;

  split(two, temp, two, delta);
  res -= sum(two) - (long long) size(two) * delta;
  merge(two, temp, two);

  delta = min({delta, begin(one), begin(two)});
  res += sum(one) - (long long) size(one) * delta;

  if (o) {
    res -= s - delta;
    res += k;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    insert(one, a[i]);
  }

  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    insert(two, b[i]);
  }

  while (q--) {
    int t;
    cin >> t;

    if (t == 1) {
      int p, x;
      cin >> p >> x;
      erase(one, a[p]);
      a[p] = x;
      insert(one, a[p]);
    } else if (t == 2) {
      int p, x;
      cin >> p >> x;
      erase(two, b[p]);
      b[p] = x;
      insert(two, b[p]);
    } else {
      int x;
      cin >> x;

      long long ans = LLONG_MIN;
      ans = max(ans, calc(x, begin(one), true));
      ans = max(ans, calc(x, begin(two), false));

      int mini = min(begin(one), begin(two));
      if (begin(one) <= mini + x) {
        ans = max(ans, calc(x, before(one, mini + x), true));
      }
      if (begin(two) <= mini + x) {
        ans = max(ans, calc(x, before(two, mini + x), false));
      }

      ans = max(ans, calc(x, end(two), false));
      if (begin(one) <= end(two) + x) {
        ans = max(ans, calc(x, before(one, end(two) + x), true));
      }
      if (end(one) >= end(two) + x) {
        ans = max(ans, calc(x, after(one, end(two) + x), true));
      }

      cout << ans << "\n";
    }
  }
}