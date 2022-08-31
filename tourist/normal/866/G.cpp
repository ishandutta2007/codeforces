/**
 *    author:  tourist
 *    created: 06.01.2019 23:15:40       
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular inverse() const {
    Type a = value, b = mod(), u = 0, v = 1;
    while (a != 0) {
      Type t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    assert(b == 1);
    return Modular(u);
  }
  Modular& operator/=(const Modular& other) { return *this *= other.inverse(); }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

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
string to_string(const Modular<T>& number) {
  return to_string(number());
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  stream >> number.value;
  number.value = Modular<T>::normalize(number.value);
  return stream;
}

struct VarMod { static int value; };
int VarMod::value;

//using Mint = Modular<VarMod>;
using Mint = Modular<std::integral_constant<int, (int) 1e9 + 7>>;

template <typename T>
vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < (int) b.size(); i++) {
    a[i] += b[i];
  }
  return a;
}

template <typename T>
vector<T> operator+(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c += b;
}

template <typename T>
vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  if (a.size() < b.size()) {
    a.resize(b.size());
  }
  for (int i = 0; i < (int) b.size(); i++) {
    a[i] -= b[i];
  }
  return a;
}

template <typename T>
vector<T> operator-(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c -= b;
}

template <typename T>
vector<T>& operator*=(vector<T>& a, const vector<T>& b) {
  if (a.empty() || b.empty()) {
    a.clear();
  } else {
    vector<T> c = a;
    a.assign(a.size() + b.size() - 1, 0);
    for (int i = 0; i < (int) c.size(); i++) {
      for (int j = 0; j < (int) b.size(); j++) {
        a[i + j] += c[i] * b[j];
      }
    }
  }
  return a;
}

template <typename T>
vector<T> operator*(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c *= b;
}

template <typename T>
vector<T> inverse(const vector<T>& a) {
  assert(!a.empty());
  int n = (int) a.size();
  vector<T> b = {1 / a[0]};
  while ((int) b.size() < n) {
    vector<T> x = b * b * vector<T>(a.begin(), a.begin() + min(a.size(), b.size() << 1));
    b.resize(b.size() << 1);
    for (int i = (int) b.size() >> 1; i < (int) min(x.size(), b.size()); i++) {
      b[i] = -x[i];
    }
  }
  b.resize(n);
  return b;
}

template <typename T>
vector<T>& operator/=(vector<T>& a, const vector<T>& b) {
  int n = (int) a.size();
  int m = (int) b.size();
  if (n < m) {
    a.clear();
  } else {
    vector<T> d = b;
    reverse(a.begin(), a.end());
    reverse(d.begin(), d.end());
    d.resize(n - m + 1);
    a *= inverse(d);
    a.erase(a.begin() + n - m + 1, a.end());
    reverse(a.begin(), a.end());
  }
  return a;
}

template <typename T>
vector<T> operator/(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c /= b;
}

template <typename T>
vector<T>& operator%=(vector<T>& a, const vector<T>& b) {
  int n = (int) a.size();
  int m = (int) b.size();
  if (n >= m) {
    vector<T> c = (a / b) * b;
    a.resize(m - 1);
    for (int i = 0; i < m - 1; i++) {
      a[i] -= c[i];
    }
  }
  return a;
}

template <typename T>
vector<T> operator%(const vector<T>& a, const vector<T>& b) {
  vector<T> c = a;
  return c %= b;
}

template <typename T, typename U>
vector<T> power(const vector<T>& a, const U& b, const vector<T>& c) {
  assert(b >= 0);
  vector<U> binary;
  U bb = b;
  while (bb > 0) {
    binary.push_back(bb & 1);
    bb >>= 1;
  }
  vector<T> res = vector<T> {1} % c;
  for (int j = (int) binary.size() - 1; j >= 0; j--) {
    res = res * res % c;
    if (binary[j] == 1) {
      res = res * a % c;
    }
  }
  return res;
}

namespace fft {

typedef double dbl;

struct num {
  dbl x, y;
  num() { x = y = 0; }
  num(dbl x_, dbl y_) : x(x_), y(y_) {}
};

inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline num conj(num a) { return num(a.x, -a.y); }

int base = 1;
vector<num> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

const dbl PI = static_cast<dbl>(acosl(-1.0));

void ensure_base(int nbase) {
  if (nbase <= base) {
    return;
  }
  rev.resize(1 << nbase);
  for (int i = 0; i < (1 << nbase); i++) {
    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    dbl angle = 2 * PI / (1 << (base + 1));
//      num z(cos(angle), sin(angle));
    for (int i = 1 << (base - 1); i < (1 << base); i++) {
      roots[i << 1] = roots[i];
//        roots[(i << 1) + 1] = roots[i] * z;
      dbl angle_i = angle * (2 * i + 1 - (1 << base));
      roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
    }
    base++;
  }
}

void fft(vector<num> &a, int n = -1) {
  if (n == -1) {
    n = (int) a.size();
  }
  assert((n & (n - 1)) == 0);
  int zeros = __builtin_ctz(n);
  ensure_base(zeros);
  int shift = base - zeros;
  for (int i = 0; i < n; i++) {
    if (i < (rev[i] >> shift)) {
      swap(a[i], a[rev[i] >> shift]);
    }
  }
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        num z = a[i + j + k] * roots[j + k];
        a[i + j + k] = a[i + j] - z;
        a[i + j] = a[i + j] + z;
      }
    }
  }
}

vector<num> fa, fb;

vector<int64_t> square(const vector<int>& a) {
  if (a.empty()) {
    return {};
  }
  int need = (int) a.size() + (int) a.size() - 1;
  int nbase = 1;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int sz = 1 << nbase;
  if ((sz >> 1) > (int) fa.size()) {
    fa.resize(sz >> 1);
  }
  for (int i = 0; i < (sz >> 1); i++) {
    int x = (2 * i < (int) a.size() ? a[2 * i] : 0);
    int y = (2 * i + 1 < (int) a.size() ? a[2 * i + 1] : 0);
    fa[i] = num(x, y);
  }
  fft(fa, sz >> 1);
  num r(1.0 / (sz >> 1), 0.0);
  for (int i = 0; i <= (sz >> 2); i++) {
    int j = ((sz >> 1) - i) & ((sz >> 1) - 1);
    num fe = (fa[i] + conj(fa[j])) * num(0.5, 0);
    num fo = (fa[i] - conj(fa[j])) * num(0, -0.5);
    num aux = fe * fe + fo * fo * roots[(sz >> 1) + i] * roots[(sz >> 1) + i];
    num tmp = fe * fo;
    fa[i] = r * (conj(aux) + num(0, 2) * conj(tmp));
    fa[j] = r * (aux + num(0, 2) * tmp);
  }
  fft(fa, sz >> 1);
  vector<int64_t> res(need);
  for (int i = 0; i < need; i++) {
    res[i] = llround(i % 2 == 0 ? fa[i >> 1].x : fa[i >> 1].y);
  }
  return res;
}

vector<int64_t> multiply(const vector<int>& a, const vector<int>& b) {
  if (a.empty() || b.empty()) {
    return {};
  }
  if (a.size() == b.size() && a == b) {
    return square(a);
  }
  int need = (int) a.size() + (int) b.size() - 1;
  int nbase = 1;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int sz = 1 << nbase;
  if (sz > (int) fa.size()) {
    fa.resize(sz);
  }
  for (int i = 0; i < sz; i++) {
    int x = (i < (int) a.size() ? a[i] : 0);
    int y = (i < (int) b.size() ? b[i] : 0);
    fa[i] = num(x, y);
  }
  fft(fa, sz);
  num r(0, -0.25 / (sz >> 1));
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    num z = (fa[j] * fa[j] - conj(fa[i] * fa[i])) * r;
    fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
    fa[i] = z;
  }
  for (int i = 0; i < (sz >> 1); i++) {
    num A0 = (fa[i] + fa[i + (sz >> 1)]) * num(0.5, 0);
    num A1 = (fa[i] - fa[i + (sz >> 1)]) * num(0.5, 0) * roots[(sz >> 1) + i];
    fa[i] = A0 + A1 * num(0, 1);
  }
  fft(fa, sz >> 1);
  vector<int64_t> res(need);
  for (int i = 0; i < need; i++) {
    res[i] = llround(i % 2 == 0 ? fa[i >> 1].x : fa[i >> 1].y);
  }
  return res;
}

vector<int> multiply_mod(const vector<int>& a, const vector<int>& b, int m) {
  if (a.empty() || b.empty()) {
    return {};
  }
  int eq = (a.size() == b.size() && a == b);
  int need = (int) a.size() + (int) b.size() - 1;
  int nbase = 0;
  while ((1 << nbase) < need) nbase++;
  ensure_base(nbase);
  int sz = 1 << nbase;
  if (sz > (int) fa.size()) {
    fa.resize(sz);
  }
  for (int i = 0; i < (int) a.size(); i++) {
    int x = (a[i] % m + m) % m;
    fa[i] = num(x & ((1 << 15) - 1), x >> 15);
  }
  fill(fa.begin() + a.size(), fa.begin() + sz, num {0, 0});
  fft(fa, sz);
  if (sz > (int) fb.size()) {
    fb.resize(sz);
  }
  if (eq) {
    copy(fa.begin(), fa.begin() + sz, fb.begin());
  } else {
    for (int i = 0; i < (int) b.size(); i++) {
      int x = (b[i] % m + m) % m;
      fb[i] = num(x & ((1 << 15) - 1), x >> 15);
    }
    fill(fb.begin() + b.size(), fb.begin() + sz, num {0, 0});
    fft(fb, sz);
  }
  dbl ratio = 0.25 / sz;
  num r2(0, -1);
  num r3(ratio, 0);
  num r4(0, -ratio);
  num r5(0, 1);
  for (int i = 0; i <= (sz >> 1); i++) {
    int j = (sz - i) & (sz - 1);
    num a1 = (fa[i] + conj(fa[j]));
    num a2 = (fa[i] - conj(fa[j])) * r2;
    num b1 = (fb[i] + conj(fb[j])) * r3;
    num b2 = (fb[i] - conj(fb[j])) * r4;
    if (i != j) {
      num c1 = (fa[j] + conj(fa[i]));
      num c2 = (fa[j] - conj(fa[i])) * r2;
      num d1 = (fb[j] + conj(fb[i])) * r3;
      num d2 = (fb[j] - conj(fb[i])) * r4;
      fa[i] = c1 * d1 + c2 * d2 * r5;
      fb[i] = c1 * d2 + c2 * d1;
    }
    fa[j] = a1 * b1 + a2 * b2 * r5;
    fb[j] = a1 * b2 + a2 * b1;
  }
  fft(fa, sz);
  fft(fb, sz);
  vector<int> res(need);
  for (int i = 0; i < need; i++) {
    int64_t aa = llround(fa[i].x);
    int64_t bb = llround(fb[i].x);
    int64_t cc = llround(fa[i].y);
    res[i] = static_cast<int>((aa + ((bb % m) << 15) + ((cc % m) << 30)) % m);
  }
  return res;
}

}  // namespace fft

template <typename T>
typename enable_if<is_same<typename Modular<T>::Type, int>::value, vector<Modular<T>>>::type& operator*=(
    vector<Modular<T>>& a,
    const vector<Modular<T>>& b) {
  vector<int> A(a.size());
  for (int i = 0; i < (int) A.size(); i++) {
    A[i] = static_cast<int>(a[i]);
  }
  vector<int> B(b.size());
  for (int i = 0; i < (int) B.size(); i++) {
    B[i] = static_cast<int>(b[i]);
  }
  vector<int> C = fft::multiply_mod(A, B, T::value);
  a.resize(C.size());
  for (int i = 0; i < (int) C.size(); i++) {
    a[i] = C[i];
  }
  return a;
}

template <typename T>
typename enable_if<is_same<typename Modular<T>::Type, int>::value, vector<Modular<T>>>::type operator*(
    const vector<Modular<T>>& a,
    const vector<Modular<T>>& b) {
  vector<Modular<T>> c = a;
  return c *= b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int f, b;
  long long n;
  cin >> f >> b >> n;
  vector<int> p(f);
  for (int i = 0; i < f; i++) {
    cin >> p[i];
  }
  vector<int> c(b);
  for (int i = 0; i < b; i++) {
    cin >> c[i];
  }
  int mx = *max_element(c.begin(), c.end());
  vector<Mint> md(mx + 1);
  md[mx]++;
  for (int i = 0; i < b; i++) {
    md[mx - c[i]]--;
  }
  vector<Mint> sum;
  for (int i = 0; i < f; i++) {
    sum += power({0, 1}, p[i], md);
  }
  vector<Mint> res = power(sum, n, md);
  vector<Mint> final(mx);
  final[mx - 1] = 1;
  res = res * final % md;
  debug(res);
  cout << ((int) res.size() <= mx - 1 ? Mint(0) : res[mx - 1]) << '\n';
  return 0;
}