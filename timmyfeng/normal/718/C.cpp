#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
struct mint {

  int val = 0;

  mint() {}

  mint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }

  mint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
  }

  mint operator+=(mint oth) {
    val += oth.val;
    val -= (val >= M) ? M : 0;
    return *this;
  }

  mint operator-=(mint oth) {
    val -= oth.val;
    val += (val < 0) ? M : 0;
    return *this;
  }

  mint operator*=(mint oth) {
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

  mint operator-() {
    mint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }

  friend mint operator+(mint a, mint b) {
    return mint(a) += b;
  }

  friend mint operator-(mint a, mint b) {
    return mint(a) -= b;
  }

  friend mint operator*(mint a, mint b) {
    return mint(a) *= b;
  }

  friend bool operator==(mint a, mint b) {
    return a.val == b.val;
  }

  friend bool operator!=(mint a, mint b) {
    return a.val != b.val;
  }

  friend ostream& operator<<(ostream &out, mint a) {
    out << a.val;
    return out;
  }

  friend mint pow(mint b, long long e = M - 2) {
    mint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= b;
      }
      b *= b;
      e /= 2;
    }
    return res;
  }

};

const int L = 60;

mint matrix[L][2][2];

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  long long lazy;
  mint prv, sum;

  segtree() {
    lazy = 0;
    prv = 0;
    sum = 1;
  }

  void apply(long long value) {
    lazy += value;

    for (int i = 0; i < L; ++i) {
      if ((value & (1LL << i)) > 0) {
        mint new_sum = sum * matrix[i][0][0] + prv * matrix[i][0][1];
        mint new_prv = sum * matrix[i][1][0] + prv * matrix[i][1][1];
        sum = new_sum;
        prv = new_prv;
      }
    }
  }

  void pull() {
    sum = right->sum + left->sum;
    prv = right->prv + left->prv;
  }

  void push() {
    if (left == nullptr) {
      right = new segtree();
      left = new segtree();
    }
    right->apply(lazy);
    left->apply(lazy);
    lazy = 0;
  }

  void update(int a, int b, long long value, int l, int r) {
    if (b < l || r < a) {
      return;
    } else if (a <= l && r <= b) {
      apply(value);
    } else {
      push();
      int m = (l + r) / 2;
      left->update(a, b, value, l, m);
      right->update(a, b, value, m + 1, r);
      pull();
    }
  }

  mint query(int a, int b, int l, int r) {
    if (a <= l && r <= b) {
      return sum;
    } else {
      push();
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return left->query(a, b, l, m) + right->query(a, b, m + 1, r);
      } else if (a <= m) {
        return left->query(a, b, l, m);
      } else {
        return right->query(a, b, m + 1, r);
      }
    }
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  matrix[0][0][0] = 1;
  matrix[0][0][1] = 1;
  matrix[0][1][0] = 1;
  matrix[0][1][1] = 0;
  for (int x = 1; x < L; ++x) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          matrix[x][i][k] += matrix[x - 1][i][j] * matrix[x - 1][j][k];
        }
      }
    }
  }

  int n, m;
  cin >> n >> m;

  segtree *fibtree = new segtree();
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    fibtree->update(i, i, a - 1, 1, n);
  }

  while (m--) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      int x;
      cin >> x;
      fibtree->update(l, r, x, 1, n);
    } else {
      cout << fibtree->query(l, r, 1, n) << "\n";
    }
  }
}