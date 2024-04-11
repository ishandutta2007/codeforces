#include <bits/stdc++.h>
using namespace std;

template <int M>
struct modint {

  int val = 0;

  modint() {}

  modint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }

  modint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
  }

  modint operator+=(modint oth) {
    val += oth.val;
    if (val >= M) {
      val -= M;
    }
    return *this;
  }

  modint operator-=(modint oth) {
    val -= oth.val;
    if (val < 0) {
      val += M;
    }
    return *this;
  }

  modint operator*=(modint oth) {
    val = 1LL * val * oth.val % M;
    return *this;
  }

  void operator++() {
    ++val;
    if (val == M) {
      val = 0;
    }
  }

  void operator--() {
    --val;
    if (val == -1) {
      val = M - 1;
    }
  }

  modint operator-() {
    modint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }

  int mod() {
    return M;
  }

  modint pow(int e) {
    modint base = val;
    modint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= base;
      }
      base *= base;
      e /= 2;
    }
    return res;
  }

  modint inv() {
    return pow(M - 2);
  }

  friend modint operator+(modint a, modint b) {
    return modint(a) += b;
  }

  friend modint operator-(modint a, modint b) {
    return modint(a) -= b;
  }

  friend modint operator*(modint a, modint b) {
    return modint(a) *= b;
  }

  friend bool operator==(modint a, modint b) {
    return a.val == b.val;
  }

  friend bool operator!=(modint a, modint b) {
    return a.val != b.val;
  }

};

using mint = modint<1'000'000'007>;
const int A = 200'000 + 1;
const int N = 100'000;
const int P = 86;

int index_p[A];
int sieve[A];

struct max_segtree {

  struct node {

    node *right = nullptr;
    node *left = nullptr;

    vector<int> powers;

    node() : powers(P) {}

    void apply(int a) {
      while (a > 1 && index_p[sieve[a]] < P) {
        ++powers[index_p[sieve[a]]];
        a /= sieve[a];
      }
    }

    void pull() {
      for (int i = 0; i < P; ++i) {
        powers[i] = max(left->powers[i], right->powers[i]);
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

  max_segtree(int n, int *a) : n(n) {
    root = new node();
    build(root, 0, n - 1, a);
  }

  void build(node *u, int l, int r, int *a) {
    if (l == r) {
      u->apply(a[l]);
    } else {
      u->push();
      int m = (l + r) / 2;
      build(u->left, l, m, a);
      build(u->right, m + 1, r, a);
      u->pull();
    }
  }

  vector<int> query(node *u, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return u->powers;
    } else {
      u->push();
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        vector<int> right = query(u->right, m + 1, r, a, b);
        vector<int> left = query(u->left, l, m, a, b);
        for (int i = 0; i < P; ++i) {
          left[i] = max(left[i], right[i]);
        }
        return left;
      } else if (a <= m) {
        return query(u->left, l, m, a, b);
      } else {
        return query(u->right, m + 1, r, a, b);
      }
    }
  }

  vector<int> query(int a, int b) {
    return query(root, 0, n - 1, a, b);
  }

};

struct product_segtree {

  struct node {

    node *right = nullptr;
    node *left = nullptr;

    mint product;

    node() : product(1) {}

    node * apply(mint a) {
      node *v = new node();
      v->product = product * a;
      return v;
    }

    void pull() {
      product = left->product * right->product;
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

  product_segtree(int n) : n(n) {
    root = new node();
  }

  template <class... S>
  node * update(node *u, int l, int r, int a, int b, const S&... args) {
    if (b < l || r < a) {
      return u;
    } else if (a <= l && r <= b) {
      return u->apply(args...);
    } else {
      u->push();
      int m = (l + r) / 2;
      node *v = new node();
      v->left = update(u->left, l, m, a, b, args...);
      v->right = update(u->right, m + 1, r, a, b, args...);
      v->pull();
      return v;
    }
  }

  mint query(node *u, int l, int r, int a, int b) {
    if (a <= l && r <= b) {
      return u->product;
    } else {
      u->push();
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return query(u->left, l, m, a, b) * query(u->right, m + 1, r, a, b);
      } else if (a <= m) {
        return query(u->left, l, m, a, b);
      } else {
        return query(u->right, m + 1, r, a, b);
      }
    }
  }

  void update(int a, mint x) {
    root = update(root, 0, n - 1, a, a, x);
  }

  mint query(node *v, int a, int b) {
    return query(v, 0, n - 1, a, b);
  }

};

product_segtree::node *root[N];

int prv[A];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> primes;
  int max_a = *max_element(a, a + n);
  for (int i = 2; i <= max_a; ++i) {
    if (sieve[i] == 0) {
      sieve[i] = i;
      index_p[i] = primes.size();
      primes.push_back(i);
    }
    for (auto j : primes) {
      if (j > max_a / i) {
        break;
      }
      sieve[i * j] = j;
      if (j == sieve[i]) {
        break;
      }
    }
  }

  fill(prv, prv + max_a + 1, -1);
  max_segtree small(n, a);
  product_segtree big(n);

  for (int i = 0; i < n; ++i) {
    while (a[i] > 1 && index_p[a[i]] < P) {
      a[i] /= sieve[a[i]];
    }

    if (a[i] != 1) {
      if (prv[a[i]] != -1) {
        big.update(prv[a[i]], mint(a[i]).inv());
      }
      big.update(i, a[i]);
      prv[a[i]] = i;
    }
    root[i] = big.root;
  }

  int q;
  cin >> q;
  mint ans = 0;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l = (ans.val + l) % n;
    r = (ans.val + r) % n;
    if (l > r) {
      swap(l, r);
    }

    ans = 1;
    vector<int> powers = small.query(l, r);
    for (int i = 0; i < min(P, (int) primes.size()); ++i) {
      ans *= mint(primes[i]).pow(powers[i]);
    }
    ans *= big.query(root[r], l, r);

    cout << ans.val << "\n";
  }
}