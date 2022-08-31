#include <bits/stdc++.h>
using namespace std;

template <int MOD>
class ModInt {
 public:
  int v;

  ModInt() : v(0) {}
  ModInt(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
    if (v < 0) v += MOD;
  }

  friend bool operator==(const ModInt &a, const ModInt &b) { return a.v == b.v; }
  friend bool operator!=(const ModInt &a, const ModInt &b) { return a.v != b.v; }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
  friend bool operator<=(const ModInt &a, const ModInt &b) { return a.v <= b.v; }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
  friend bool operator>=(const ModInt &a, const ModInt &b) { return a.v >= b.v; }

  ModInt &operator+=(const ModInt &a) {
    if ((v += a.v) >= MOD) v -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &a) {
    if ((v -= a.v) < 0) v += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &a) {
    v = 1ll * v * a.v % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &a) {
    return (*this) *= inverse(a);
  }

  friend ModInt pow(ModInt a, long long x) {
    ModInt res = 1;
    assert(x >= 0);
    for (; x; x /= 2, a *= a)
      if (x & 1) res *= a;
    return res;
  }
  friend ModInt inverse(ModInt a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }

  ModInt operator+() const { return ModInt(v); }
  ModInt operator-() const { return ModInt(-v); }
  ModInt operator++() const { return *this += 1; }
  ModInt operator--() const { return *this -= 1; }

  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }

  friend istream &operator>>(istream &is, ModInt &v) {
    is >> v.v;
    return is;
  }
  friend ostream &operator<<(ostream &os, const ModInt &v) {
    os << v.v;
    return os;
  }
};

const int MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  // N = 1e5, K = 1;
  K--;
  map<pair<int, int>, int> done;
  vector<int> A, B;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    // x = 0, y = i;
    // if (i + 1 == N) {
    //   x = 1, y = 0;
    // }
    if (done.count({x, y})) {
      if (K == i) {
        K = done[{x, y}];
      }
    } else {
      done[{x, y}] = i;
      A.emplace_back(x);
      B.emplace_back(y);
    }
  }
  N = A.size();

  const auto Canon = [&](int x, int y) {
    if (x == 0) {
      return pair(0, 1);
    } else if (y == 0) {
      return pair(1, 0);
    } else {
      int g = __gcd(abs(x), abs(y));
      x /= g;
      y /= g;
      if (y < 0) {
        x *= -1;
        y *= -1;
      }
      return pair(x, y); 
    }
  };
  int OTHER = -1;
  for (int s = 0; s < 2; s++) {
    map<pair<int, int>, vector<int>> group;
    for (int i = 0; i < N; i++) if (i != s) {
      group[Canon(A[i] - A[s], B[i] - B[s])].emplace_back(i);
      if (group.size() > 2) break;
    }
    if (group.size() > 2) {
      OTHER = s;
    } else {
      assert(group.size() == 2);
      for (auto [x, y] : group) {
        if (y.size() == 1) {
          OTHER = y[0];
        }
      }
    }
  }
  assert(OTHER != -1);

  vector<int> line;
  for (int i = 0; i < N; i++) {
    if (i != OTHER) {
      line.emplace_back(i);
    }
  }
  auto cmp = [&](int a, int b) {
    return pair(A[a], B[a]) < pair(A[b], B[b]);
  };
  sort(begin(line), end(line), cmp);

  // const auto Solve = [&](vector<pair<int, int>> nodes, vector<pair<int, int>> edges, int start) -> double {

  // };

  const auto Dist = [&](int i, int j) {
    return hypot(A[i] - A[j], B[i] - B[j]);
  };

  int meetk = 0;
  double ans = 1e18;
  if (K == OTHER) {
    ans = min(ans, Dist(K, line.front()) + Dist(line.front(), line.back()));
    ans = min(ans, Dist(K, line.back()) + Dist(line.front(), line.back()));
  } else if (K == line.front()) {
    for (int i = 0; i < int(line.size()); i++) {
      if (i + 1 == line.size()) {
        ans = min(ans, Dist(K, line.back()) + Dist(line.back(), OTHER));
      } else {
        ans = min(ans, Dist(K, line[i]) + Dist(line[i], OTHER) + Dist(OTHER, line[i + 1]) + Dist(line[i + 1], line.back()));
        ans = min(ans, Dist(K, line[i]) + Dist(line[i], OTHER) + Dist(OTHER, line.back()) + Dist(line[i + 1], line.back()));
      }
    }
  } else if (K == line.back()) {
    for (int i = 0; i < int(line.size()); i++) {
      if (i == 0) {
        ans = min(ans, Dist(K, line.front()) + Dist(line.front(), OTHER));
      } else {
        ans = min(ans, Dist(K, line[i]) + Dist(line[i], OTHER) + Dist(OTHER, line[i - 1]) + Dist(line[i - 1], line.front()));
        ans = min(ans, Dist(K, line[i]) + Dist(line[i], OTHER) + Dist(OTHER, line.front()) + Dist(line[i - 1], line.front()));        
      }
    }
  } else {
    ans = min(ans, Dist(K, line.front()) + Dist(line.front(), line.back()) + Dist(line.back(), OTHER));
    ans = min(ans, Dist(K, line.back()) + Dist(line.back(), line.front()) + Dist(line.front(), OTHER));
    int meetk = 0;
    for (int i = 0; i < int(line.size()); i++) {
      if (line[i] == K) meetk = 1;
      if (meetk == 1 || line[i] == K) {
        if (i + 1 < int(line.size())) {
          ans = min(ans, Dist(K, line.front()) + Dist(line.front(), line[i]) + Dist(line[i], OTHER) + Dist(OTHER, line[i + 1]) + Dist(line[i + 1], line.back()));
          ans = min(ans, Dist(K, line.front()) + Dist(line.front(), line[i]) + Dist(line[i], OTHER) + Dist(OTHER, line.back()) + Dist(line[i + 1], line.back()));
          ans = min(ans, Dist(K, line[i]) + Dist(line.front(), line[i]) + Dist(line.front(), OTHER) + Dist(OTHER, line[i + 1]) + Dist(line[i + 1], line.back()));
          ans = min(ans, Dist(K, line[i]) + Dist(line.front(), line[i]) + Dist(line.front(), OTHER) + Dist(OTHER, line.back()) + Dist(line[i + 1], line.back()));
        }
      }
      if (meetk == 0 || line[i] == K) {
        if (i > 0) {
          ans = min(ans, Dist(K, line.back()) + Dist(line.back(), line[i]) + Dist(line[i], OTHER) + Dist(OTHER, line[i - 1]) + Dist(line[i - 1], line.front()));
          ans = min(ans, Dist(K, line.back()) + Dist(line.back(), line[i]) + Dist(line[i], OTHER) + Dist(OTHER, line.front()) + Dist(line[i - 1], line.front()));
          ans = min(ans, Dist(K, line[i]) + Dist(line.back(), line[i]) + Dist(line.back(), OTHER) + Dist(OTHER, line[i - 1]) + Dist(line[i - 1], line.front()));
          ans = min(ans, Dist(K, line[i]) + Dist(line.back(), line[i]) + Dist(line.back(), OTHER) + Dist(OTHER, line.front()) + Dist(line[i - 1], line.front()));
        }
      }
    }
  }
  // for (int i = 0; i + 1 < int(line.size()); i++) {
  //   for (int x = 0; x < 2; x++) {
  //     for (int y = 0; y < 2; y++) {
  //       double sum = 0;
  //       sum += Dist()
  //       ans = min(ans, sum);
  //     }
  //   }
  //   ans = min(ans, )
  // }
  // for (auto add : line) {
  //   if (K == add) meetk = 1;
  //   if (K == OTHER) {
  //     ans = min(ans, Dist(K, add) + Dist(add, line.front()) + Dist(line.front(), line.back()));
  //     ans = min(ans, Dist(K, add) + Dist(add, line.back()) + Dist(line.front(), line.back()));
  //     ans = min(ans, Dist(K, line.front()) + Dist(line.front(), line.back()));
  //     ans = min(ans, Dist(K, line.back()) + Dist(line.front(), line.back()));      
  //   } else if (K == add) {
  //     ans = min(ans, 2 * (Dist(K, OTHER) + Dist(K, line.front()) + Dist(K, line.back())) - min({Dist(K, OTHER), Dist(K, line.front()), Dist(K, line.back())}));
  //     ans = min(ans, Dist(K, OTHER) + Dist(OTHER, line.front()) + Dist(line.front(), line.back()));
  //     ans = min(ans, Dist(K, OTHER) + Dist(OTHER, line.back()) + Dist(line.front(), line.back()));
  //   } else if (meetk == 1) { // K on left of line

  //   } else if (meetk == 0) { // K on right of line

  //   }
  // }
  cout << fixed << setprecision(12) << ans << '\n';
  return 0;
}