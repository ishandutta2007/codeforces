#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
struct mint {

  int value;

  mint() : value(0) {}

  template <class T>
  mint(T x) {
    value = x % M;
    if (value < 0) {
      value += M;
    }
  }

  mint & operator++() {
    if (++value == M) {
      value = 0;
    }
    return *this;
  }

  mint & operator--() {
    if (--value == -1) {
      value = M - 1;
    }
    return *this;
  }

  mint operator++(int) {
    mint res = *this;
    ++*this;
    return res;
  }

  mint operator--(int) {
    mint res = *this;
    --*this;
    return res;
  }

  mint & operator+=(mint oth) {
    value += oth.value;
    if (value >= M) {
      value -= M;
    }
    return *this;
  }

  mint & operator-=(mint oth) {
    value -= oth.value;
    if (value < 0) {
      value += M;
    }
    return *this;
  }

  mint & operator*=(mint oth) {
    value = (long long) value * oth.value % M;
    return *this;
  }

  mint operator+() const {
    return *this;
  }

  mint operator-() const {
    return mint() - *this;
  }

  mint pow(long long e = M - 2) const {
    mint res = 1, b = *this;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= b;
      }
      b *= b;
      e /= 2;
    }
    return res;
  }

  friend mint operator+(mint a, mint b) {
    return a += b;
  }

  friend mint operator-(mint a, mint b) {
    return a -= b;
  }

  friend mint operator*(mint a, mint b) {
    return mint(a) *= b;
  }

  friend bool operator==(mint a, mint b) {
    return a.value == b.value;
  }

  friend bool operator!=(mint a, mint b) {
    return a.value != b.value;
  }

  friend ostream & operator<<(ostream &out, mint a) {
    out << a.value;
    return out;
  }

};

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  mint sum, coeff, lazy;

  segtree() {
    lazy = coeff = 1;
    sum = 0;
  }

  void apply(mint x) {
    sum *= x, coeff *= x, lazy *= x;
  }

  void pull() {
    sum = left->sum + right->sum;
  }

  void push() {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }

    if (lazy != 1) {
      left->apply(lazy);
      right->apply(lazy);
      lazy = 1;
    }
  }

  void update(int a, int b, mint x, int l, int r) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      apply(x);
    } else {
      push();
      int m = (l + r) / 2;
      left->update(a, b, x, l, m);
      right->update(a, b, x, m + 1, r);
      pull();
    }
  }

  void update(int a, mint x, int l, int r) {
    if (l == r) {
      sum = x * coeff;
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m) {
        left->update(a, x, l, m);
      } else {
        right->update(a, x, m + 1, r);
      }
      pull();
    }
  }

  mint query(int a, int b, int l, int r) {
    if (b < l || r < a) {
      return 0;
    } else if (a <= l && r <= b) {
      return sum;
    } else {
      push();
      int m = (l + r) / 2;
      return left->query(a, b, l, m) + right->query(a, b, m + 1, r);
    }
  }

  mint query(int a, int l, int r) {
    if (l == r) {
      return coeff;
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m) {
        return left->query(a, l, m);
      } else {
        return right->query(a, m + 1, r);
      }
    }
  }

};

const int N = 200000 + 1;

int in[N], out[N], par[N], t;
vector<int> adj[N];

void dfs(int u) {
  in[u] = ++t;
  for (auto c : adj[u]) {
    if (c != par[u]) {
      dfs(c);
    }
  }
  out[u] = t;
}

array<int, 2> queries[N];
int degree[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int v1, q, n = 1;
  cin >> v1 >> q;

  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, v;
      cin >> p >> v;
      par[++n] = p;
      adj[p].push_back(n);
      queries[i] = {v, n};
    } else {
      int u;
      cin >> u;
      queries[i] = {-1, u};
    }
  }

  dfs(1);

  segtree *power_tree = new segtree();
  power_tree->update(1, v1, 1, n);

  for (int i = 0; i < q; ++i) {
    auto [v, u] = queries[i];
    if (v == -1) {
      cout << power_tree->query(in[u], out[u], 1, n) * power_tree->query(in[u], 1, n).pow() * (degree[u] + 1) << "\n";
    } else {
      int p = par[u];
      ++degree[p];
      power_tree->update(in[p], out[p], (degree[p] + 1) * mint(degree[p]).pow(), 1, n);
      power_tree->update(in[u], v, 1, n);
    }
  }
}