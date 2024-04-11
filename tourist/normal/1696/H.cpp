/**
 *    author:  tourist
 *    created: 25.06.2022 18:24:34       
**/
#undef _GLIBCXX_DEBUG

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

/*
using ModType = int;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int md = (int) 1e9 + 7;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> pos;
  vector<int> neg;
  int zeros = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a > 0) {
      pos.push_back(a);
    }
    if (a < 0) {
      neg.push_back(-a);
    }
    if (a == 0) {
      zeros += 1;
    }
  }
  sort(pos.rbegin(), pos.rend());
  sort(neg.rbegin(), neg.rend());
  int cp = (int) pos.size();
  int cn = (int) neg.size();
  vector<int> pos_idx(cp);
  vector<int> neg_idx(cn);
  {
    int ip = 0;
    int in = 0;
    int idx = 0;
    while (ip < cp || in < cn) {
      if (in == cn || (ip < cp && pos[ip] >= neg[in])) {
        pos_idx[ip++] = idx++;
      } else {
        neg_idx[in++] = idx++;
      }
    }
  }
  vector<vector<Mint>> dp(cp + 1, vector<Mint>(cp + 1));
  dp[0][0] = 1;
  for (int i = 0; i < cp; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j + 1] += dp[i][j] * pos[i];
    }
  }
  vector<vector<Mint>> dn(cn + 1, vector<Mint>(cn + 1));
  dn[0][0] = 1;
  for (int i = 0; i < cn; i++) {
    for (int j = 0; j <= i; j++) {
      dn[i + 1][j] += dn[i][j];
      dn[i + 1][j + 1] += dn[i][j] * neg[i];
    }
  }
  vector<Mint> p2(n + 1);
  p2[0] = 1;
  for (int i = 1; i <= n; i++) {
    p2[i] = p2[i - 1] * 2;
  }
  Mint ans = 0;
  for (int ip = 0; ip < cp; ip++) {
    for (int in = 0; in < cn; in++) {
      if (ip + in + 2 >= k) {
        vector<Mint> sum(2);
        for (int tp = 0; tp <= ip; tp++) {
          int tn = k - 2 - tp;
          if (tn >= 0 && tn <= in) {
            sum[(tn + 1) & 1] += dp[ip][tp] * dn[in][tn];
          }
        }
        int bound = max(pos_idx[ip], neg_idx[in]);
        int cnt = zeros;
        for (int i = 0; i < cp; i++) {
          cnt += (pos_idx[i] > bound);
        }
        for (int i = 0; i < cn; i++) {
          cnt += (neg_idx[i] > bound);
        }
        ans += sum[0] * pos[ip] * neg[in] * p2[cnt];
        ans -= sum[1] * pos[ip] * neg[in];
        {
          int jp = ip + 1;
          int jn = in + 1;
          while (jp < cp && pos_idx[jp] <= bound) {
            jp += 1;
          }
          while (jn < cn && neg_idx[jn] <= bound) {
            jn += 1;
          }
          while (jp < cp && jn < cn) {
            if ((long long) pos[ip] * pos[jp] > (long long) neg[in] * neg[jn]) {
              ans += sum[1] * pos[ip] * pos[jp] * (p2[zeros + (cp - jp - 1) + (cn - jn)] - p2[zeros + (cp - jp - 1)]);
              jp += 1;
            } else {
              ans += sum[1] * neg[in] * neg[jn] * (p2[zeros + (cn - jn - 1) + (cp - jp)] - p2[zeros + (cn - jn - 1)]);
              jn += 1;
            }
          }
        }
        for (int jp = ip + 1; jp < cp; jp++) {
          if (pos_idx[jp] > bound) {
            ans += sum[1] * pos[ip] * pos[jp] * p2[zeros + max(0, cp - jp - 1)];
          }
        }
        for (int jn = in + 1; jn < cn; jn++) {
          if (neg_idx[jn] > bound) {
            ans += sum[1] * neg[in] * neg[jn] * p2[zeros + max(0, cn - jn - 1)];
          }
        }
      }
    }
  }
  for (int ip = k - 1; ip < cp; ip++) {
    int bound = pos_idx[ip];
    int cnt = zeros;
    for (int i = 0; i < cp; i++) {
      cnt += (pos_idx[i] > bound);
    }
    for (int i = 0; i < cn; i++) {
      cnt += (neg_idx[i] > bound);
    }
    ans += dp[ip][k - 1] * pos[ip] * p2[cnt];
  }
  if (k % 2 == 0) {
    for (int in = k - 1; in < cn; in++) {
      int bound = neg_idx[in];
      int cnt = zeros;
      for (int i = 0; i < cp; i++) {
        cnt += (pos_idx[i] > bound);
      }
      for (int i = 0; i < cn; i++) {
        cnt += (neg_idx[i] > bound);
      }
      ans += dn[in][k - 1] * neg[in] * p2[cnt];
    }
  } else {
    for (int in = k - 1; in < cn; in++) {
      int bound = neg_idx[in];
      for (int ip = 0; ip < cp; ip++) {
        if (pos_idx[ip] > bound) {
          int new_bound = pos_idx[ip];
          int cnt = zeros;
          for (int i = 0; i < cp; i++) {
            cnt += (pos_idx[i] > new_bound);
          }
          for (int i = 0; i < cn; i++) {
            cnt += (neg_idx[i] > bound);
          }
          ans += dn[in][k - 1] * pos[ip] * p2[cnt];
        }
      }
    }
    reverse(neg.begin(), neg.end());
    dn.assign(cn + 1, vector<Mint>(cn + 1));
    dn[0][0] = 1;
    for (int i = 0; i < cn; i++) {
      for (int j = 0; j <= i; j++) {
        dn[i + 1][j] += dn[i][j];
        dn[i + 1][j + 1] += dn[i][j] * neg[i];
      }
    }
    for (int in = k - 1; in < cn; in++) {
      ans -= dn[in][k - 1] * neg[in] * p2[cn - in - 1];
    }
  }
  cout << ans << '\n';
  debug(clock());
  return 0;
}