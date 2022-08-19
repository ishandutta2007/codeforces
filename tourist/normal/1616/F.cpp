/**
 *    author:  tourist
 *    created: 29.12.2021 19:03:09       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  friend const Type& abs(const Modular& x) { return x.value; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = 3;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

/*vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}*/

const double eps = 1e-9;

bool IsZero(double v) {
  return abs(v) < 1e-9;
}

enum GAUSS_MODE {
  DEGREE, ABS
};

template <typename T>
void GaussianElimination(vector<vector<T>>& a, int limit, GAUSS_MODE mode = DEGREE) {
  if (a.empty() || a[0].empty()) {
    return;
  }
  int h = static_cast<int>(a.size());
  int w = static_cast<int>(a[0].size());
  for (int i = 0; i < h; i++) {
    assert(w == static_cast<int>(a[i].size()));
  }
  assert(limit <= w);
  vector<int> deg(h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      deg[i] += !IsZero(a[i][j]);
    }
  }
  int r = 0;
  for (int c = 0; c < limit; c++) {
    int id = -1;
    for (int i = r; i < h; i++) {
      if (!IsZero(a[i][c]) && (id == -1 || (mode == DEGREE && deg[i] < deg[id]) || (mode == ABS && abs(a[id][c]) < abs(a[i][c])))) {
        id = i;
      }
    }
    if (id == -1) {
      continue;
    }
    if (id > r) {
      swap(a[r], a[id]);
      swap(deg[r], deg[id]);
      for (int j = c; j < w; j++) {
        a[id][j] = -a[id][j];
      }
    }
    vector<int> nonzero;
    for (int j = c; j < w; j++) {
      if (!IsZero(a[r][j])) {
        nonzero.push_back(j);
      }
    }
    T inv_a = 1 / a[r][c];
    for (int i = r + 1; i < h; i++) {
      if (IsZero(a[i][c])) {
        continue;
      }
      T coeff = -a[i][c] * inv_a;
      for (int j : nonzero) {
        if (!IsZero(a[i][j])) deg[i]--;
        a[i][j] += coeff * a[r][j];
        if (!IsZero(a[i][j])) deg[i]++;
      }
    }
    ++r;
  }
  for (r = h - 1; r >= 0; r--) {
    for (int c = 0; c < limit; c++) {
      if (!IsZero(a[r][c])) {
        T inv_a = 1 / a[r][c];
        for (int i = r - 1; i >= 0; i--) {
          if (IsZero(a[i][c])) {
            continue;
          }
          T coeff = -a[i][c] * inv_a;
          for (int j = c; j < w; j++) {
            a[i][j] += coeff * a[r][j];
          }
        }
        break;
      }
    }
  }
}

template <typename T>
vector<T> SolveLinearSystem(vector<vector<T>> a, const vector<T>& b, int w) {
  int h = static_cast<int>(a.size());
  assert(h == static_cast<int>(b.size()));
  if (h > 0) {
    assert(w == static_cast<int>(a[0].size()));
  }
  for (int i = 0; i < h; i++) {
    a[i].push_back(b[i]);
  }
  GaussianElimination(a, w);
  vector<T> x(w, 0);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!IsZero(a[i][j])) {
        x[j] = a[i][w] / a[i][j];
        break;
      }
    }
  }
  return x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m), z(m);
    vector<int> vars;
    vector<int> ids(m, -1);
    vector<vector<int>> g(n, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
      cin >> x[i] >> y[i] >> z[i];
      --x[i]; --y[i];
      if (z[i] > 0) {
        --z[i];
      }
      if (z[i] == -1) {
        ids[i] = (int) vars.size();
        vars.push_back(i);
      }
      g[x[i]][y[i]] = i;
      g[y[i]][x[i]] = i;
    }
    int sz = (int) vars.size();
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    mt19937 rng(589813054);
    shuffle(order.begin(), order.end(), rng);
    vector<vector<Mint>> mat;
    vector<Mint> R;
    for (int it = 0; it < n; it++) {
      for (int jt = it + 1; jt < n; jt++) {
        if (g[it][jt] != -1) {
          for (int kt = jt + 1; kt < n; kt++) {
            if (g[it][kt] != -1 && g[jt][kt] != -1) {
              int e0 = g[it][jt];
              int e1 = g[it][kt];
              int e2 = g[jt][kt];
              mat.emplace_back(sz, 0);
              R.push_back(0);
              for (int e : {e0, e1, e2}) {
                if (z[e] == -1) {
                  mat.back()[ids[e]] += 1;
                } else {
                  R.back() -= z[e];
                }
              }
            }
          }
        }
      }
    }
    auto res = SolveLinearSystem(mat, R, sz);
    bool ok = true;
    for (int i = 0; i < (int) mat.size(); i++) {
      Mint sum = 0;
      for (int j = 0; j < sz; j++) {
        sum += mat[i][j] * res[j];
      }
      if (sum != R[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    for (int i = 0; i < m; i++) {
      if (z[i] == -1) {
        z[i] = res[ids[i]]();
      }
      if (i > 0) {
        cout << " ";
      }
      cout << z[i] + 1;
    }
    cout << '\n';
  }
  return 0;
}