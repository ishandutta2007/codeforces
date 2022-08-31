/**
 *    author:  tourist
 *    created: 29.05.2018 18:52:44       
**/
//#undef _GLIBCXX_DEBUG

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

namespace fft {
  typedef double dbl;

  struct num {
    dbl x, y;
    num() { x = y = 0; }
    num(dbl x, dbl y) : x(x), y(y) { }
  };

  inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }
  inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }
  inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
  inline num conj(num a) { return num(a.x, -a.y); }

  int base = 1;
  vector<num> roots = {{0, 0}, {1, 0}};
  vector<int> rev = {0, 1};

  const dbl PI = acosl(-1.0);

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
      n = a.size();
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
/*    for (int len = 1; len < n; len <<= 1) {
      for (int i = 0; i < n; i += 2 * len) {
        for (int j = i, k = i + len; j < i + len; j++, k++) {
          num z = a[k] * roots[k - i];
          a[k] = a[j] - z;
          a[j] = a[j] + z;
        }
      }
    }*/
  }

  vector<num> fa, fb;

  vector<int> multiply(vector<int> &a, vector<int> &b) {
    int need = a.size() + b.size() - 1;
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
      if (i != j) {
        fa[j] = (fa[i] * fa[i] - conj(fa[j] * fa[j])) * r;
      }
      fa[i] = z;
    }
    for (int i = 0; i < (sz >> 1); i++) {
      num A0 = (fa[i] + fa[i + (sz >> 1)]) * num(0.5, 0);
      num A1 = (fa[i] - fa[i + (sz >> 1)]) * num(0.5, 0) * roots[(sz >> 1) + i];
      fa[i] = A0 + A1 * num(0, 1);
    }
    fft(fa, sz >> 1);
    vector<int> res(need);
    for (int i = 0; i < need; i++) {
      if (i % 2 == 0) {
        res[i] = fa[i >> 1].x + 0.5;
      } else {
        res[i] = fa[i >> 1].y + 0.5;
      }
    }
    return res;
  }

  vector<long long> square(const vector<int> &a) {
    int need = a.size() + a.size() - 1;
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
    vector<long long> res(need);
    for (int i = 0; i < need; i++) {
      if (i % 2 == 0) {
        res[i] = fa[i >> 1].x + 0.5;
      } else {
        res[i] = fa[i >> 1].y + 0.5;
      }
    }
    return res;
  }

  vector<int> multiply_mod(vector<int> &a, vector<int> &b, int m, int eq = 0) {
    int need = a.size() + b.size() - 1;
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
      long long aa = fa[i].x + 0.5;
      long long bb = fb[i].x + 0.5;
      long long cc = fa[i].y + 0.5;
      res[i] = (aa + ((bb % m) << 15) + ((cc % m) << 30)) % m;
    }
    return res;
  }

  vector<int> square_mod(vector<int> &a, int m) {
    return multiply_mod(a, a, m, 1);
  }
};

void multiply(vector<int> &a, int b) {
  int carry = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    carry += a[i] * b;
    a[i] = carry % 100000;
    carry /= 100000;
  }
  while (carry > 0) {
    a.push_back(carry % 100000);
    carry /= 100000;
  }
}

void divide(vector<int> &a, int b) {
  int md = 0;
  for (int i = (int) a.size() - 1; i >= 0; i--) {
    md = 100000 * md + a[i];
    a[i] = md / b;
    md %= b;
  }
  assert(md == 0);
  while (!a.empty() && a.back() == 0) {
    a.pop_back();
  }
}

bool is_less(const vector<int> &a, const vector<int> &b) {
  if (a.size() != b.size()) {
    return (a.size() < b.size());
  }
  for (int i = (int) a.size() - 1; i >= 0; i--) {
    if (a[i] != b[i]) {
      return (a[i] < b[i]);
    }
  }
  return false;
}

vector<int> sp3;
vector<long long> sp3_aux;

void get_p3(int p3) {
  if (p3 <= 0) {
    return;
  }
  if (p3 & 1) {
    get_p3(p3 - 1);
    multiply(sp3, 3);
  } else {
    get_p3(p3 >> 1);
    sp3_aux = fft::square(sp3);
    sp3.resize(sp3_aux.size());
    long long carry = 0;
    for (int i = 0; i < (int) sp3_aux.size(); i++) {
      carry += sp3_aux[i];
      sp3[i] = carry % 100000;
      carry /= 100000;
    }
    while (carry > 0) {
      sp3.push_back(carry % 100000);
      carry /= 100000;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
//  debug(fft::square({100, 200, 300, 400, 500}));
//  return 0;
  string foo;
  cin >> foo;
  if (foo == "1") {
    cout << 1 << '\n';
    return 0;
  }
  int len = (int) foo.size();
  vector<int> s_10(len);
  for (int i = 0; i < len; i++) {
    s_10[i] = (int) (foo[len - 1 - i] - '0');
  }
  vector<int> s((len + 4) / 5);
  for (int i = 0; i < (int) s.size(); i++) {
    s[i] = s_10[5 * i];
    if (5 * i + 1 < (int) s_10.size()) s[i] += 10 * s_10[5 * i + 1];
    if (5 * i + 2 < (int) s_10.size()) s[i] += 100 * s_10[5 * i + 2];
    if (5 * i + 3 < (int) s_10.size()) s[i] += 1000 * s_10[5 * i + 3];
    if (5 * i + 4 < (int) s_10.size()) s[i] += 10000 * s_10[5 * i + 4];
  }
  int p3 = (int) (logl(10) * (len - 1) / logl(3));
  sp3.assign(1, 1);
  get_p3(p3);
  int ans = 3 * p3;
  while (is_less(sp3, s)) {
    if (ans <= 3) {
      sp3[0] = ans + 1;
    } else {
      if (ans % 3 == 0) {
        divide(sp3, 3);
        multiply(sp3, 4);
      } else {
        divide(sp3, 2);
        multiply(sp3, 3);
      }
    }
    ans++;
  }
  cout << ans << '\n';
  return 0;
}