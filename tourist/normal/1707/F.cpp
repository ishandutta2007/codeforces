/**
 *    author:  tourist
 *    created: 16.07.2022 20:17:25       
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

using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, t, w;
  cin >> n >> m >> t >> w;
  vector<int> a(n, -1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    a[x] = y;
  }
  int p2 = 1;
  while (n / p2 % 2 == 0) {
    p2 *= 2;
  }
  vector<int> val(p2);
  vector<int> cnt(p2);
  for (int i = 0; i < n; i++) {
    if (a[i] == -1) {
      cnt[i & (p2 - 1)] += 1;
    } else {
      val[i & (p2 - 1)] ^= a[i];
    }
  }
  int q;
  cin >> q;
  int bad = 0;
  int total = 0;
  if (t >= p2) {
    for (int i = 0; i < p2; i++) {
      if (cnt[i] == 0 && val[i] != 0) {
        bad += 1;
      } else {
        total += max(0, cnt[i] - 1);
      }
    }
  }
  vector<int> st(2 * p2);
  vector<int> sf(2 * p2);
  vector<bool> type(p2);
  for (int i = p2 - 1; i >= 1; i--) {
    int bit = 1 << (31 - __builtin_clz(i));
    type[i] = !!(t & bit);
  }
  vector<int> bitrev(p2);
  for (int i = 1; i < p2; i++) {
    bitrev[i] = bitrev[i >> 1] >> 1;
    if (i & 1) bitrev[i] |= (p2 >> 1);
  }
  auto Fill = [&](int i) {
    int at = bitrev[i - p2];
    st[i] = (cnt[at] == 0 ? val[at] : -1);
    sf[i] = cnt[at];
  };
  auto Merge = [&](int i) {
    int x = 2 * i;
    int y = 2 * i + 1;
    if (sf[x] == -1 || sf[y] == -1) {
      st[i] = -1;
      sf[i] = -1;
      return;
    }
    if (st[x] > st[y]) {
      swap(x, y);
    }
    if (type[i]) {
      if (st[y] == -1) {
        st[i] = -1;
        sf[i] = sf[x] + sf[y] - 1;
      } else {
        if (st[x] == -1) {
          st[i] = st[y];
          sf[i] = sf[y] + sf[x] - 1;
        } else {
          if (st[x] != st[y]) {
            st[i] = -1;
            sf[i] = -1;
          } else {
            st[i] = st[x];
            sf[i] = sf[x] + sf[y];
          }
        }
      }
    } else {
      if (st[y] == -1) {
        st[i] = -1;
        sf[i] = sf[x] + sf[y];
      } else {
        if (st[x] == -1) {
          st[i] = -1;
          sf[i] = sf[y] + sf[x];
        } else {
          st[i] = st[x] ^ st[y];
          sf[i] = sf[x] + sf[y];
        }
      }
    }
  };
  for (int i = 2 * p2 - 1; i >= p2; i--) {
    Fill(i);
  }
  for (int i = p2 - 1; i >= 1; i--) {
    Merge(i);
  }
  while (q--) {
    int x, y;
    cin >> x >> y >> md;
    --x;
    int cell = x % p2;
    if (t >= p2) {
      if (cnt[cell] == 0 && val[cell] != 0) {
        bad -= 1;
      } else {
        total -= max(0, cnt[cell] - 1);
      }
    }
    if (a[x] == -1) {
      cnt[cell] -= 1;
    } else {
      val[cell] ^= a[x];
    }
    a[x] = y;
    if (a[x] == -1) {
      cnt[cell] += 1;
    } else {
      val[cell] ^= a[x];
    }
    if (t >= p2) {
      if (cnt[cell] == 0 && val[cell] != 0) {
        bad += 1;
      } else {
        total += max(0, cnt[cell] - 1);
      }
      if (bad > 0) {
        cout << 0 << '\n';
      } else {
        cout << power(Mint(1 << w), total) << '\n';
      }
    } else {
      cell = bitrev[cell];
      cell += p2;
      Fill(cell);
      while (cell > 1) {
        cell >>= 1;
        Merge(cell);
      }
      if (sf[1] == -1) {
        cout << 0 << '\n';
      } else {
        cout << power(Mint(1 << w), sf[1]) << '\n';
      }
    }
  }
  return 0;
}