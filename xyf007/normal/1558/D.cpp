#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
constexpr int kMod = 998244353;
template <typename T>
T add(T a, T b) {
  return (a + b) % kMod;
}
template <typename T, typename... Args>
T add(T a, T b, Args... args) {
  return add(add(a, b), args...);
}
template <typename T>
T sub(T a, T b) {
  return (a + kMod - b) % kMod;
}
template <typename T>
T mul(T a, T b) {
  return a * static_cast<long long>(b) % kMod;
}
template <typename T, typename... Args>
T mul(T a, T b, Args... args) {
  return mul(mul(a, b), args...);
}
template <typename T>
void Add(T &a, T b) {
  a = add(a, b);
}
template <typename T, typename... Args>
void Add(T &a, T b, Args... args) {
  Add(a, add(b, args...));
}
template <typename T>
void Sub(T &a, T b) {
  a = sub(a, b);
}
template <typename T>
void Mul(T &a, T b) {
  a = mul(a, b);
}
template <typename T, typename... Args>
void Mul(T &a, T b, Args... args) {
  Mul(a, mul(b, args...));
}
template <typename T1, typename T2>
T1 Ksm(T1 a, T2 b) {
  T1 s = 1;
  while (b) {
    if (b & 1) Mul(s, a);
    Mul(a, a);
    b >>= 1;
  }
  return s;
}
int fac[400001], inv[400001];
void Init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  inv[n] = Ksm(fac[n], kMod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
}
int C(int x, int y) {
  if (x < y || y < 0) return 0;
  return mul(fac[x], inv[x - y], inv[y]);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, n, m;
struct node {
  int ls, rs, rd, val, sz, tag;
} t[500001];
int cnt, root;
void checkmax(int &x, int y) {
  if (x < y) {
    x = y;
  }
}
int newnode(int val) {
  int id = ++cnt;
  t[id].ls = t[id].rs = t[id].tag = 0;
  t[id].val = val;
  t[id].sz = 1;
  t[id].rd = rand();
  return id;
}
void pushup(int x) {
  if (!x) return;
  t[x].sz = t[t[x].ls].sz + t[t[x].rs].sz + 1;
}
void pushdown(int x) {
  if (!x) return;
  if (t[x].tag) {
    if (t[x].ls) t[t[x].ls].val += t[x].tag, t[t[x].ls].tag += t[x].tag;
    if (t[x].rs) t[t[x].rs].val += t[x].tag, t[t[x].rs].tag += t[x].tag;
    t[x].tag = 0;
  }
}
void split(int p, int k, int &x, int &y) {
  if (!p) {
    x = y = 0;
    return;
  }
  pushdown(p);
  if (k >= t[p].val) {
    x = p;
    split(t[p].rs, k, t[p].rs, y);
  } else {
    y = p;
    split(t[p].ls, k, x, t[p].ls);
  }
  pushup(p);
}
int merge(int x, int y) {
  if (!x || !y) return x + y;
  if (t[x].rd < t[y].rd) {
    pushdown(x);
    t[x].rs = merge(t[x].rs, y);
    pushup(x);
    return x;
  } else {
    pushdown(y);
    t[y].ls = merge(x, t[y].ls);
    pushup(y);
    return y;
  }
}
bool Find(int x, int p) {
  if (!p) return false;
  if (t[p].val == x) return true;
  pushdown(p);
  if (x < t[p].val)
    return Find(x, t[p].ls);
  else
    return Find(x, t[p].rs);
}
void Solve() {
  std::cin >> n >> m;
  root = cnt = 0;
  for (int i = 1; i <= m; i++) {
    int a, b, x, y;
    std::cin >> a >> b;
    bool f = Find(b, root);
    split(root, b - 1, x, y);
    if (y) t[y].val++, t[y].tag++;
    if (f) {
      root = merge(x, y);
    } else {
      root = merge(x, merge(newnode(b + 1), y));
    }
  }
  std::cout << C(n + n - cnt - 1, n) << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Init(400000);
  std::srand(std::time(nullptr));
  std::cin >> T;
  while (T--) Solve();
  return 0;
}