/**
 *    author:  wxhtzdy
 *    created: 03.06.2022 20:06:59
**/
#include <bits/stdc++.h>

using namespace std;

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
/*
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cc = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      cc += 1;
    }
  }      
  vector<vector<Mint>> dp(1 << 18, vector<Mint>(18));
  function<void(int, int)> Add = [&](int mask, int pp) {
    for (int i = 1; i <= 17; i++) {
      Mint qq = i;
      dp[mask][i] += power(qq, pp);
    }
  };
  for (int i = 0; i < n; i++) {
    int mask = 0;
    int cq = 0;
    int ft = 0;
    for (int j = 0; j < n; j++) {
      int l = i - j;
      int r = i + j;
      if (l < 0 || r >= n) {
        break;
      }
      if (s[l] == '?') {
        cq += 1;                        
      }
      if (l != r && s[r] == '?') {
        cq += 1;
      }
      if (s[l] == '?' || s[r] == '?') {
        if (s[l] == s[r]) {
          ft += 1;
        } else {  
          if (s[l] != '?') {
            mask |= (1 << (s[l] - 'a'));  
          } else {
            mask |= (1 << (s[r] - 'a'));  
          }
        }
      } else {
        if (s[l] != s[r]) {
          break;
        }          
      }
      Add(mask, cc - cq + ft);
    }
  }                                                                     
  for (int i = 0; i < n; i++) {
    int mask = 0;
    int cq = 0;
    int ft = 0;
    for (int j = 0; j < n; j++) {
      int l = i - j;
      int r = i + j + 1;
      if (l < 0 || r >= n) {
        break;
      }
      if (s[l] == '?') {
        cq += 1;
      }
      if (l != r && s[r] == '?') {
        cq += 1;
      }
      if (s[l] == '?' || s[r] == '?') {
        if (s[l] == s[r]) {
          ft += 1;
        } else {  
          if (s[l] != '?') {
            mask |= (1 << (s[l] - 'a'));  
          } else {
            mask |= (1 << (s[r] - 'a'));  
          }
        }
      } else {
        if (s[l] != s[r]) {
          break;
        }
      }
      Add(mask, cc - cq + ft);
    }
  }
  for (int i = 0; i < 18; i++) {
    for (int s = 0; s < (1 << 18); s++) {
      if (!(s >> i & 1)) {
        for (int j = 0; j < 18; j++) {
          dp[s ^ (1 << i)][j] += dp[s][j];
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int sz = s.size();
    int mask = 0;
    for (int i = 0; i < sz; i++) {
      mask |= (1 << (s[i] - 'a'));
    }
    cout << dp[mask][sz] << '\n';
  }                                                                 
  return 0;
}