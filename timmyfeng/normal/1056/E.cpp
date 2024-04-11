#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned long long) new char);

int rand_int(int a, int b) {
  return uniform_int_distribution<int>(a, b)(rng);
}

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
const int N = 1'000'000;
const int H = 2;

mint pow_base[H][N];
mint inv_base[H][N];
mint base[H];

void init_hash() {
  for (int i = 0; i < H; ++i) {
    base[i] = rand_int(137, mint(0).mod() - 1);
    mint inv = base[i].inv();
    pow_base[i][0] = 1;
    inv_base[i][0] = 1;
    for (int j = 1; j < N; ++j) {
      pow_base[i][j] = pow_base[i][j - 1] * base[i];
      inv_base[i][j] = inv_base[i][j - 1] * inv;
    }
  }
}

struct poly_hash {

  vector<mint> prefix[H];

  poly_hash() {}

  poly_hash(const string& s) {
    int n = s.size();
    for (int i = 0; i < H; ++i) {
      prefix[i].resize(n + 1);
      for (int j = 0; j < n; ++j) {
        prefix[i][j + 1] = prefix[i][j] + s[j] * pow_base[i][j];
      }
    }
  }

  array<mint, H> query(int a, int b) {
    array<mint, H> res;
    for (int i = 0; i < H; ++i) {
      res[i] = (prefix[i][b + 1] - prefix[i][a]) * inv_base[i][a];
    }
    return res;
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  init_hash();

  string s, t;
  cin >> s >> t;

  int count0 = count(s.begin(), s.end(), '0');
  int count1 = count(s.begin(), s.end(), '1');

  poly_hash hash(t);
  int n = t.size();

  int ans = 0;

  for (int i = 1; count0 * i < n; ++i) {
    if ((n - count0 * i) % count1 == 0) {
      int j = (n - count0 * i) / count1;

      int index = 0;
      int prv0 = -1;
      int prv1 = -1;
      bool ok = true;

      for (auto k : s) {
        if (k == '0') {
          if (prv0 != -1) {
            ok &= (hash.query(prv0, prv0 + i - 1) == hash.query(index, index + i - 1));
          }
          prv0 = index;
          index += i;
        } else {
          if (prv1 != -1) {
            ok &= (hash.query(prv1, prv1 + j - 1) == hash.query(index, index + j - 1));
          }
          prv1 = index;
          index += j;
        }
      }
      ok &= (i != j || hash.query(prv0, prv0 + i - 1) != hash.query(prv1, prv1 + j - 1));

      ans += ok;
    }
  }

  cout << ans << "\n";
}