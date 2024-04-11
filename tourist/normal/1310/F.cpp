/**
 *    author:  tourist
 *    created: 23.02.2020 21:13:57       
**/
#undef _GLIBCXX_DEBUG

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

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend const Modular<U>& abs(const Modular<U>& v) { return v; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

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

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;

typedef unsigned long long ull;

const ull one = 1;

ull multiply(ull a, ull b);

ull multiply_powers_of_2(ull a, ull b) {
    if (a == 1 || b == 1) return a * b;
    ull n = 5;
    while ((one << (one << n)) > max(a, b)) {
      --n;
    }
    ull power = (one << (one << n));
    if (a >= power && b >= power) {
        return multiply(power * 3 / 2, multiply_powers_of_2(a / power, b / power));
    } else if (a >= power) {
        return multiply_powers_of_2(a / power, b) * power;
    } else {
        return multiply_powers_of_2(a, b / power) * power;
    }
}

ull multiply(ull a, ull b) {
   ull ans = 0;
   for (int i = 0; i < 64; i++) {
     if (a & (one << i)) {
       for (int j = 0; j < 64; j++) {
         if (b & (one << j)) {
           ans ^= multiply_powers_of_2(one << i, one << j);
         }
       }
     }
   }
   return ans;
}

ull memo[64][64];

ull multiply_powers_of_2_fast(ull a, ull b) {
  return memo[__builtin_ctzll(a)][__builtin_ctzll(b)];
}

ull multiply_fast(ull a, ull b) {
   ull ans = 0;
   for (int i = 0; i < 64; i++) {
     if (a & (one << i)) {
       for (int j = 0; j < 64; j++) {
         if (b & (one << j)) {
           ans ^= multiply_powers_of_2_fast(one << i, one << j);
         }
       }
     }
   }
   return ans;
}

template <typename T>
void crt(const vector<int>& p, const vector<int>& a, T& res) {
  assert(p.size() == a.size());
  auto inverse = [&](int q, int m) {
    q %= m;
    if (q < 0) q += m;
    int b = m, u = 0, v = 1;
    while (q) {
      int t = b / q;
      b -= t * q; swap(q, b);
      u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += m;
    return u;
  };
  vector<int> x(p.size());
  for (int i = 0; i < (int) p.size(); i++) {
    assert(0 <= a[i] && a[i] < p[i]);
    x[i] = a[i];
    for (int j = 0; j < i; j++) {
      x[i] = (int) ((long long) (x[i] - x[j]) * inverse(p[j], p[i]) % p[i]);
      if (x[i] < 0) x[i] += p[i];
    }
  }
  res = 0;
  for (int i = (int) p.size() - 1; i >= 0; i--) {
    res = res * p[i] + x[i];
  }
}

const ull M = ((one << 63) - 1) * 2 + 1;
vector<int> factors = {641, 6700417, 65537, 257, 17, 5, 3};

ull my_power(ull x, ull y) {
  ull res = 1;
  while (y > 0) {
    if (y & 1) {
      res = multiply_fast(res, x);
    }
    x = multiply_fast(x, x);
    y >>= 1;
  }
  return res;
}

map<ull, int> mp[7];
const int JUMP = 50000;

vector<ull> steps;
vector<ull> big_steps;

vector<int> Log(ull x) {
  vector<int> ret(factors.size());
  for (int iter = 0; iter < (int) factors.size(); iter++) {
    int f = factors[iter];
    assert(M % f == 0);
    ull y = my_power(x, M / f);
    ull big_step = big_steps[iter];
    ret[iter] = 0;
    while (true) {
      if (mp[iter].find(y) != mp[iter].end()) {
        ret[iter] = (ret[iter] + mp[iter][y]) % f;
        break;
      }
      y = multiply_fast(y, big_step);
      ret[iter] = ((ret[iter] + f - JUMP) % f + f) % f;
    }
  }
  return ret;
}

int main() {
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < 64; j++) {
      memo[i][j] = multiply_powers_of_2(one << i, one << j);
    }
  }
  debug(clock());
  for (int iter = 0; iter < (int) factors.size(); iter++) {
    int f = factors[iter];
    ull step = my_power(M, M / f);
    steps.push_back(step);
    big_steps.push_back(my_power(step, JUMP));
    ull me = 1;
    for (int i = 0; i < JUMP; i++) {
      if (mp[iter].find(me) != mp[iter].end()) break;
      mp[iter][me] = i;
      me = multiply_fast(me, step);
    }
  }
  debug(clock());
  int tt;
  cin >> tt;
  while (tt--) {
    ull x, y;
    cin >> x >> y;
    auto xl = Log(x);
    auto yl = Log(y);
    bool ok = true;
    for (int i = 0; i < (int) factors.size(); i++) {
      if (xl[i] == 0) {
        if (yl[i] != 0) {
          ok = false;
          break;
        }
      } else {
        md = factors[i];
        yl[i] = (Mint(yl[i]) / Mint(xl[i]))();
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      ull res;
      crt(factors, yl, res);
      cout << res << '\n';
    }
    if (tt % 10 == 0)
      debug(tt, clock());
  }
  return 0;
}