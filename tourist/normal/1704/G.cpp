/**
 *    author:  tourist
 *    created: 31.07.2022 18:53:25       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
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
    value = normalize((__int128) value * rhs.value % mod());
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

constexpr long long md = (1LL << 61) - 1;
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

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
uint64_t step = (md >> 2) + rng() % (md >> 1);

// make it understandable one day...
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

void fft(vector<num>& a, int n = -1) {
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
  if (a == b) {
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
typename enable_if<is_same<typename Modular<T>::Type, int>::value, vector<Modular<T>>>::type operator*(
    const vector<Modular<T>>& a,
    const vector<Modular<T>>& b) {
  if (a.empty() || b.empty()) {
    return {};
  }
  if (min(a.size(), b.size()) < 150) {
    vector<Modular<T>> c(a.size() + b.size() - 1, 0);
    for (int i = 0; i < (int) a.size(); i++) {
      for (int j = 0; j < (int) b.size(); j++) {
        c[i + j] += a[i] * b[j];
      }
    }
    return c;
  } 
  vector<int> a_mul(a.size());
  for (int i = 0; i < (int) a.size(); i++) {
    a_mul[i] = static_cast<int>(a[i]);
  }
  vector<int> b_mul(b.size());
  for (int i = 0; i < (int) b.size(); i++) {
    b_mul[i] = static_cast<int>(b[i]);
  }
  vector<int> c_mul = fft::multiply_mod(a_mul, b_mul, T::value);
  vector<Modular<T>> c(c_mul.size());
  for (int i = 0; i < (int) c.size(); i++) {
    c[i] = c_mul[i];
  }
  return c;
}

template <typename T>
typename enable_if<is_same<typename Modular<T>::Type, int>::value, vector<Modular<T>>>::type& operator*=(
    vector<Modular<T>>& a,
    const vector<Modular<T>>& b) {
  return a = a * b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int m;
    cin >> m;
    vector<long long> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    vector<Mint> pw(n + 1);
    pw[0] = 1;
    for (int i = 0; i < n; i++) {
      pw[i + 1] = pw[i] * step;
    }
    vector<Mint> add(n + 1);
    add[0] = 0;
    for (int i = 0; i < n; i++) {
      add[i + 1] = add[i] * step + (i % 2 == 0 ? i + 1 : (-i - 1));
    }
    vector<Mint> pref_a(n + 1);
    for (int i = 0; i < n; i++) {
      pref_a[i + 1] = pref_a[i] * step + a[i];
    }
    vector<Mint> pref_b(m + 1);
    for (int i = 0; i < m; i++) {
      pref_b[i + 1] = pref_b[i] * step + b[i];
    }
    vector<Mint> aux1(n + 1);
    for (int i = 0; i < n; i++) {
      aux1[i + 1] = aux1[i] * step + (i % 2 == 0 ? 1 : -1);
    }
    vector<Mint> aux2(n + 1);
    for (int i = 0; i < n; i++) {
      aux2[i + 1] = aux2[i] * step + (i % 2 == 0 ? -i : i);
    }
    auto FindMax = [&](long long odds, long long evens, long long limit) {
      if (limit % 2 == 0) {
        limit -= 1;
      }
      // limit + (limit - 2) + ... + (limit - 2 * odds + 2)
      long long s1 = (limit + (limit - 2 * odds + 2)) * odds / 2;
      // - 2 - 4 - ... - 2 * evens
      long long s2 = evens * (evens + 1);
      long long res = s1 - s2;
      long long nxt = (limit - 2 * odds) + (limit - 2 * odds - 2) - (2 * evens + 2) - (2 * evens + 4);
      if (nxt > 0) {
        long long cnt = nxt / 16 + 1;
        // nxt + (nxt - 16) + ... + (nxt - 16 * (cnt - 1))
        res += (nxt + (nxt - 16 * (cnt - 1))) * cnt / 2;
      }
      return res;
    };
    auto FindMin = [&](long long odds, long long evens, long long limit) {
      if (limit % 2 == 1) {
        limit -= 1;
      }
      // limit + (limit - 2) + ... + (limit - 2 * evens + 2)
      long long s1 = (limit + (limit - 2 * evens + 2)) * evens / 2;
      // 1 + 3 + ... + (2 * odds - 1)
      long long s2 = odds * odds;
      long long res = s2 - s1;
      long long nxt = (limit - 2 * evens) + (limit - 2 * evens - 2) - (2 * odds + 1) - (2 * odds + 3);
      if (nxt > 0) {
        long long cnt = nxt / 16 + 1;
        // nxt + (nxt - 16) + ... + (nxt - 16 * (cnt - 1))
        res -= (nxt + (nxt - 16 * (cnt - 1))) * cnt / 2;
      }
      return res;
    };
    auto Can = [&](long long sum, long long diff, long long limit) {
      long long odds = (diff > 0 ? diff : 0);
      long long evens = (diff < 0 ? -diff : 0);
      if ((odds & 1) != (sum & 1)) {
        odds += 1;
        evens += 1;
      }
      if (odds > (limit + 1) / 2 || evens > limit / 2) {
        return false;
      }
      long long mx = FindMax(odds, evens, limit);
      long long mn = FindMin(odds, evens, limit);
      return (mn <= sum && sum <= mx);
    };
    auto MUL = [&](vector<Mint> pa, vector<Mint> pb) {
      int sz = (int) pa.size() + (int) pb.size() - 1;
      vector<vector<int>> help(sz, vector<int>(3));
      vector<int> mods = {998244353, (int) 1e9 + 7, (int) 1e9 + 9};
      for (int id = 0; id < 3; id++) {
        int mod = mods[id];
        vector<int> qa(pa.size());
        for (int i = 0; i < (int) pa.size(); i++) {
          qa[i] = pa[i]() % mod;
        }
        vector<int> qb(pb.size());
        for (int i = 0; i < (int) pb.size(); i++) {
          qb[i] = pb[i]() % mod;
        }
        auto got = fft::multiply_mod(qa, qb, mod);
        for (int i = 0; i < sz; i++) {
          help[i][id] = got[i];
        }
      }
      vector<Mint> pc(sz);
      for (int pos = 0; pos < sz; pos++) {
        Mint res = 0;
        Mint mult = 1;
        vector<int> x(3);
        for (int i = 0; i < 3; i++) {
          x[i] = help[pos][i];
          for (int j = 0; j < i; j++) {
            long long cur = (x[i] - x[j]) * 1LL * inverse(mods[j], mods[i]);
            x[i] = (int)( (cur % mods[i] + mods[i]) % mods[i] );					
          }
          res += mult * x[i];
          mult *= mods[i];
        }
        pc[pos] = res;
      }
      return pc;
    };
    vector<Mint> extra(n - m + 1);
    if (m > 2) {
      for (int v = 0; v < 2; v++) {
        vector<Mint> pa(n - 2);
        for (int i = 1; i < n - 1; i++) {
          if (((a[i - 1] - 2 * a[i] + a[i + 1]) & 1) == v) {
            pa[i - 1] = 1;
          }
        }
        vector<Mint> pb(m - 2);
        for (int i = 1; i < m - 1; i++) {
          if (((b[i - 1] - 2 * b[i] + b[i + 1]) & 1) != v) {
            pb[i - 1] = add[m - 1 - i];
          }
        }
        reverse(pb.begin(), pb.end());
        auto pc = MUL(pa, pb);
        for (int pos = 0; pos <= n - m; pos++) {
          extra[pos] += pc[pos + m - 3];
        }
      }
    }
    bool found = false;
    for (int pos = 0; pos <= n - m; pos++) {
      Mint h = pref_a[pos + m] - pref_a[pos] * pw[m];
      h += extra[pos];
/*      for (int i = 1; i < m - 1; i++) {
        int in_a = (a[pos + i - 1] - 2 * a[pos + i] + a[pos + i + 1]) & 1;
        int in_b = (b[0 + i - 1] - 2 * b[0 + i] + b[0 + i + 1]) & 1;
        if (in_a != in_b) {
          h += add[m - 1 - i];
        }
      }*/
      long long da = b[0] - a[pos + 0];
      long long db = b[1] - a[pos + 1];
      long long sum = db;
      long long diff = da + db;
      long long limit = pos + 2;
      h += aux1[m] * da + aux2[m] * diff;
      if (h == pref_b[m]) {
        if (Can(sum, diff, limit)) {
          vector<int> res;
          for (int i = 1; i < m - 1; i++) {
            int in_a = (a[pos + i - 1] - 2 * a[pos + i] + a[pos + i + 1]) & 1;
            int in_b = (b[0 + i - 1] - 2 * b[0 + i] + b[0 + i + 1]) & 1;
            if (in_a != in_b) {
              res.push_back(pos + i + 1);
            }
          }
          for (long long val = limit; val >= 1; val--) {
            if (!Can(sum, diff, val - 1)) {
              res.push_back(pos + 2 - val);
              if (val % 2 == 1) {
                sum -= val;
                diff -= 1;
              } else {
                sum += val;
                diff += 1;
              }
            }
          }
          assert(sum == 0 && diff == 0);
          sort(res.begin(), res.end());
          cout << res.size() << '\n';
          for (int i = 0; i < (int) res.size(); i++) {
            cout << res[i] + 1 << " \n"[i == (int) res.size() - 1];
          }
          found = true;
          break;
        }
      }
    }
    if (!found) {
      cout << -1 << '\n';
    }
  }
  return 0;
}