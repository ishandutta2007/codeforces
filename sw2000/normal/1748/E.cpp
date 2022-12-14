#include <bits/stdc++.h>
#ifdef SW2000
#include "debug_info.h"
#else
#define endl '\n'
using namespace std;
#define freopen(a, b, c)
#define D(...)
#endif
#define fi first
#define se second
template <class T>
void Min(T& a, const T b) {
  if (a > b) a = b;
}
template <class T>
void Max(T& a, const T b) {
  if (a < b) a = b;
}
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e5 + 10, M = 100;
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a, swap(a, m);
    u -= t * v, swap(u, v);
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
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) {
    if ((value += other.value) >= mod()) value -= mod();
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((value -= other.value) < 0) value += mod();
    return *this;
  }
  template <typename U>
  Modular& operator+=(const U& other) {
    return *this += Modular(other);
  }
  template <typename U>
  Modular& operator-=(const U& other) {
    return *this -= Modular(other);
  }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),
             d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) *
                                         rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) {
    return *this *= Modular(inverse(other.value, mod()));
  }

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

template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value < rhs.value;
}

template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
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

constexpr int mod = (int)1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;

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

struct segtree {
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    int ma = 0;

    void apply(int l, int r, int v) { ma = v; }
  };

  node unite(const node& a, const node& b) const {
    node ret;
    ret.ma = max(a.ma, b.ma);
    return ret;
  }

  inline void push(int o, int l, int r) {
    int mid = (l + r) >> 1, lo = o + 1, ro = o + ((mid - l + 1) << 1);
    // push from o into lo and ro
    // if (tree[o].lazy != 0) {
    //   tree[lo].apply(l, mid, tree[o].lazy);
    //   tree[ro].apply(mid + 1, r, tree[o].lazy);
    //   tree[o].lazy = 0;
    // }
  }

  inline void pull(int o, int ro) { tree[o] = unite(tree[o + 1], tree[ro]); }

  int n;
  vector<node> tree;

  void build(int o, int l, int r) {
    if (l == r) {
      return;
    }
    int mid = (l + r) >> 1, lo = o + 1, ro = o + ((mid - l + 1) << 1);
    build(lo, l, mid);
    build(ro, mid + 1, r);
    pull(o, ro);
  }

  template <typename M>
  void build(int o, int l, int r, const vector<M>& v) {
    if (l == r) {
      tree[o].apply(l, r, v[l]);
      return;
    }
    int mid = (l + r) >> 1, lo = o + 1, ro = o + ((mid - l + 1) << 1);
    build(lo, l, mid, v);
    build(ro, mid + 1, r, v);
    pull(o, ro);
  }

  node get(int o, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return tree[o];
    }
    int mid = (l + r) >> 1, lo = o + 1, ro = o + ((mid - l + 1) << 1);
    push(o, l, r);
    node ret{};
    if (qr <= mid) {
      ret = get(lo, l, mid, ql, qr);
    } else if (ql > mid) {
      ret = get(ro, mid + 1, r, ql, qr);
    } else {
      ret = unite(get(lo, l, mid, ql, qr), get(ro, mid + 1, r, ql, qr));
    }
    pull(o, ro);
    return ret;
  }

  template <typename... M>
  void modify(int o, int l, int r, int ql, int qr, const M&... v) {
    if (ql <= l && r <= qr) {
      tree[o].apply(l, r, v...);
      return;
    }
    int mid = (l + r) >> 1, lo = o + 1, ro = o + ((mid - l + 1) << 1);
    push(o, l, r);
    if (ql <= mid) {
      modify(lo, l, mid, ql, qr, v...);
    }
    if (qr > mid) {
      modify(ro, mid + 1, r, ql, qr, v...);
    }
    pull(o, ro);
  }

  int find_first_knowingly(int o, int l, int r,
                           const function<bool(const node&)>& f) {
    if (l == r) {
      return l;
    }
    push(o, l, r);
    int mid = (l + r) >> 1, lo = o + 1, ro = o + ((mid - l + 1) << 1);
    int ret;
    if (f(tree[lo])) {
      ret = find_first_knowingly(lo, l, mid, f);
    } else {
      ret = find_first_knowingly(ro, mid + 1, r, f);
    }
    pull(o, ro);
    return ret;
  }

  int find_first(int o, int l, int r, int ql, int qr,
                 const function<bool(const node&)>& f) {
    if (ql <= l && r <= qr) {
      if (!f(tree[o])) {
        return -1;
      }
      return find_first_knowingly(o, l, r, f);
    }
    push(o, l, r);
    int mid = (l + r) >> 1, lo = o + 1, ro = o + ((mid - l + 1) << 1);
    int ret = -1;
    if (ql <= mid) {
      ret = find_first(lo, l, mid, ql, qr, f);
    }
    if (qr > mid && ret == -1) {
      ret = find_first(ro, mid + 1, r, ql, qr, f);
    }
    pull(o, ro);
    return ret;
  }

  int find_last_knowingly(int o, int l, int r,
                          const function<bool(const node&)>& f) {
    if (l == r) {
      return l;
    }
    push(o, l, r);
    int mid = (l + r) >> 1, lo = o + 1, ro = o + ((mid - l + 1) << 1);
    int ret;
    if (f(tree[ro])) {
      ret = find_last_knowingly(ro, mid + 1, r, f);
    } else {
      ret = find_last_knowingly(lo, l, mid, f);
    }
    pull(o, ro);
    return ret;
  }

  int find_last(int o, int l, int r, int ql, int qr,
                const function<bool(const node&)>& f) {
    if (ql <= l && r <= qr) {
      if (!f(tree[o])) {
        return -1;
      }
      return find_last_knowingly(o, l, r, f);
    }
    push(o, l, r);
    int mid = (l + r) >> 1, lo = o + 1, ro = o + ((mid - l + 1) << 1);
    int ret = -1;
    if (qr > mid) {
      ret = find_last(ro, mid + 1, r, ql, qr, f);
    }
    if (ql <= mid && ret == -1) {
      ret = find_last(lo, l, mid, ql, qr, f);
    }
    pull(o, ro);
    return ret;
  }

  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }

  template <typename M>
  segtree(const vector<M>& v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }

  node get(int ql, int qr) {
    assert(0 <= ql && ql <= qr && qr <= n - 1);
    return get(0, 0, n - 1, ql, qr);
  }

  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }

  template <typename... M>
  void modify(int ql, int qr, const M&... v) {
    assert(0 <= ql && ql <= qr && qr <= n - 1);
    modify(0, 0, n - 1, ql, qr, v...);
  }

  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once

  int find_first(int ql, int qr, const function<bool(const node&)>& f) {
    assert(0 <= ql && ql <= qr && qr <= n - 1);
    return find_first(0, 0, n - 1, ql, qr, f);
  }

  int find_last(int ql, int qr, const function<bool(const node&)>& f) {
    assert(0 <= ql && ql <= qr && qr <= n - 1);
    return find_last(0, 0, n - 1, ql, qr, f);
  }
};

Mint solve() {
  int n, m;
  cin >> n >> m;
  vi ar(n);
  for (auto& i : ar) {
    cin >> i;
  }
  segtree seg(ar);
  function<vector<Mint>(int, int, int)> dfs = [&](int l, int r, int limit) {
    if (l > r) return vector<Mint>(limit + 1, 1);
    auto anc = seg.get(l, r);
    int mid = seg.find_first(
        l, r, [&](const segtree::node& a) { return a.ma == anc.ma; });
    auto left = dfs(l, mid - 1, limit - 1);
    auto right = dfs(mid + 1, r, limit);
    vector<Mint> ret(limit + 1, 0);
    for (int i = 1; i <= limit; i++) {
      ret[i] = ret[i - 1] + left[i - 1] * right[i];
    }
    return ret;
  };
  return dfs(0, n - 1, m).back();
};
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  freopen("a.in", "r", stdin);
  int _ = 1;
  cin >> _;
  while (_--) {
    cout << (solve());
    cout << endl;
  }
}