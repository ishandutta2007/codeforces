/**
 *    author:  tourist
 *    created: 27.05.2018 19:00:11       
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

const int md = 998244353;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
#if !defined(_WIN32) || defined(_WIN64)
  return (int) ((long long) a * b % md);
#endif
  unsigned long long x = (long long) a * b;
  unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
  asm(
    "divl %4; \n\t"
    : "=a" (d), "=d" (m)
    : "d" (xh), "a" (xl), "r" (md)
  );
  return m;
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

namespace ntt {
  int base = 1;
  vector<int> roots = {0, 1};
  vector<int> rev = {0, 1};
  int max_base = -1;
  int root = -1;

  void init() {
    int tmp = md - 1;
    max_base = 0;
    while (tmp % 2 == 0) {
      tmp /= 2;
      max_base++;
    }
    root = 2;
    while (true) {
      if (power(root, 1 << max_base) == 1) {
        if (power(root, 1 << (max_base - 1)) != 1) {
          break;
        }
      }
      root++;
    }
  }

  void ensure_base(int nbase) {
    if (max_base == -1) {
      init();
    }
    if (nbase <= base) {
      return;
    }
    assert(nbase <= max_base);
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
      rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
      int z = power(root, 1 << (max_base - 1 - base));
      for (int i = 1 << (base - 1); i < (1 << base); i++) {
        roots[i << 1] = roots[i];
        roots[(i << 1) + 1] = mul(roots[i], z);
      }
      base++;
    }
  }

  void fft(vector<int> &a) {
    int n = (int) a.size();
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
          int x = a[i + j];
          int y = mul(a[i + j + k], roots[j + k]);
          a[i + j] = x + y - md;
          if (a[i + j] < 0) a[i + j] += md;
          a[i + j + k] = x - y + md;
          if (a[i + j + k] >= md) a[i + j + k] -= md;
        }
      }
    }
  }

  vector<int> multiply(vector<int> a, vector<int> b, int eq = 0) {
    int need = (int) (a.size() + b.size() - 1);
    int nbase = 0;
    while ((1 << nbase) < need) nbase++;
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    fft(a);
    if (eq) b = a; else fft(b);
    int inv_sz = inv(sz);
    for (int i = 0; i < sz; i++) {
      a[i] = mul(mul(a[i], b[i]), inv_sz);
    }
    reverse(a.begin() + 1, a.end());
    fft(a);
    a.resize(need);
    return a;
  }

  vector<int> square(vector<int> a) {
    return multiply(a, a, 1);
  }
}

vector<vector<int>> vect;

vector<int> multiply_all(int from, int to) {
  if (from == to) {
    return {1};
  }
  if (from + 1 == to) {
    return vect[from];
  }
  int mid = (from + to) >> 1;
  return ntt::multiply(multiply_all(from, mid), multiply_all(mid, to));
}

const int N = 400010;

vector<int> g[N];
int sz[N];
int pv[N];
int val[N];
int sum_val[N];
int memo[N];
int touched[N], ITER;
vector<int> all;
int n, k;
int ans;

void dfs(int v, int pr) {
  pv[v] = pr;
  all.push_back(v);
  sz[v] = 1;
  sum_val[v] = 0;
  vector<int> children;
  for (int u : g[v]) {
    if (u == pr) {
      continue;
    }
    children.push_back(u);
    dfs(u, v);
    sz[v] += sz[u];
    add(ans, mul(sum_val[u], sum_val[v]));
    add(sum_val[v], sum_val[u]);
  }
  vect.clear();
  for (int u : children) {
    vect.push_back({1, sz[u]});
  }
  vector<int> res = multiply_all(0, (int) vect.size());
  assert(res.size() == vect.size() + 1);
  int ways = 1;
  val[v] = 0;
  for (int i = 0; i <= min(k, (int) vect.size()); i++) {
    add(val[v], mul(ways, res[i]));
    ways = mul(ways, k - i);
  }
  add(sum_val[v], val[v]);
  if (pr != -1) {
    res = ntt::multiply(res, {1, n - sz[v]});
  }
  ITER++;
  for (int it = 0; it < (int) children.size(); it++) {
    int S = sz[children[it]];
    int &vall = memo[S];
    if (touched[S] != ITER) {
      touched[S] = ITER;
      vall = 0;
      int cur = 0;
      ways = 1;
      for (int i = 0; i <= min(k, (int) res.size() - 1); i++) {
        cur = mul(cur, S);
        cur = (res[i] - cur + md) % md;
        add(vall, mul(ways, cur));
        ways = mul(ways, k - i);
      }
      assert(cur == 0);
    }
    add(ans, mul(vall, sum_val[children[it]]));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i <= n; i++) {
    memo[i] = -1;
    touched[i] = -1;
  }
  ITER = 0;
  ans = 0;
  if (k == 1) {
    ans = mul(mul(n, n - 1), inv(2));
  } else {
    dfs(0, -1);
  }
  cout << ans << '\n';
  return 0;
}