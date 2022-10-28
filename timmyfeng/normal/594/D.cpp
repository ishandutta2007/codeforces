#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

struct segtree {

  segtree *left = nullptr, *right = nullptr;
  int product;

  void push() {
    if (left == nullptr) {
      left = new segtree();
      right = new segtree();
    }
  }

  void update(int a, int x, int l, int r) {
    if (l == r) {
      product = x;
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m) {
        left->update(a, x, l, m);
      } else {
        right->update(a, x, m + 1, r);
      }
      product = (long long) left->product * right->product % M;
    }
  }

  int query(int a, int b, int l, int r) {
    if (b < l || r < a) {
      return 1;
    } else if (a <= l && r <= b) {
      return product;
    } else {
      push();
      int m = (l + r) / 2;
      return (long long) left->query(a, b, l, m) * right->query(a, b, m + 1, r) % M;
    }
  }

};

const int A = 1000000 + 1;
const int N = 200000 + 1;

int sieve[A], prv[A], ans[N], a[N];
vector<array<int, 2>> queries[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i < A; ++i) {
    if (sieve[i] == 0) {
      for (int j = i; j < A; j += i) {
        sieve[j] = i;
      }
    }
  }

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    queries[r].push_back({l, i});
  }

  segtree *vovo = new segtree();

  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    while (x > 1) {
      int p = sieve[x];
      while (x % p == 0) {
        x /= p;
      }
      a[i] /= p;
      a[i] *= p - 1;

      if (prv[p] != 0) {
        a[prv[p]] /= p - 1;
        a[prv[p]] *= p;
        vovo->update(prv[p], a[prv[p]], 1, n);
      }
      prv[p] = i;
    }

    vovo->update(i, a[i], 1, n);

    for (auto [j, id] : queries[i]) {
      ans[id] = vovo->query(j, i, 1, n);
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}