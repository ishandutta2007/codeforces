#include <iostream>
#include <numeric>
constexpr int kBase = 100003, kMod = 1e9 + 9;
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
template <typename T, typename... Args>
T sub(T a, T b, Args... args) {
  return sub(sub(a, b), args...);
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
template <typename T, typename... Args>
void Sub(T &a, T b, Args... args) {
  Sub(a, add(b, args...));
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
int pw[1000001];
void Init(int n) {
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = mul(pw[i - 1], kBase);
}
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Node {
  int cnt, ls, rs;
  long long sum;
} t[20000001];
int n, m, ha[500001], hb[500001], hs[1000001], a[500001], b[500001], rt[500001],
    tot;
char A[500001], B[500001], S[1000001];
int Calc(int *h, int l, int r) {
  return sub(h[r], mul(h[l - 1], pw[r - l + 1]));
}
void Pushup(int x) {
  t[x].cnt = t[t[x].ls].cnt + t[t[x].rs].cnt;
  t[x].sum = t[t[x].ls].sum + t[t[x].rs].sum;
}
int Modify(int l, int r, int p, int x) {
  int xx = ++tot;
  t[xx] = t[x];
  if (l == r) {
    t[xx].cnt++, t[xx].sum += p;
    return xx;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    t[xx].ls = Modify(l, mid, p, t[x].ls);
  else
    t[xx].rs = Modify(mid + 1, r, p, t[x].rs);
  Pushup(xx);
  return xx;
}
template <typename T, typename U>
std::pair<T, U> &operator+=(std::pair<T, U> &lhs, const std::pair<T, U> &rhs) {
  lhs.first += rhs.first, lhs.second += rhs.second;
  return lhs;
}
std::pair<int, long long> Query(int L, int R, int l, int r, int x, int y) {
  if (L <= l && r <= R) return {t[y].cnt - t[x].cnt, t[y].sum - t[x].sum};
  int mid = (l + r) >> 1;
  std::pair<int, long long> ans;
  if (L <= mid) ans += Query(L, R, l, mid, t[x].ls, t[y].ls);
  if (R > mid) ans += Query(L, R, mid + 1, r, t[x].rs, t[y].rs);
  return ans;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m >> (A + 1) >> (B + 1) >> (S + 1), Init(std::max(n, m));
  for (int i = 1; i <= n; i++)
    ha[i] = add(mul(ha[i - 1], kBase), static_cast<int>(A[i]));
  for (int i = 1; i <= n; i++)
    hb[i] = add(mul(hb[i - 1], kBase), static_cast<int>(B[i]));
  for (int i = 1; i <= m; i++)
    hs[i] = add(mul(hs[i - 1], kBase), static_cast<int>(S[i]));
  for (int i = 1; i <= n; i++) {
    int l = 0, r = std::min(n - i + 1, m);
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (Calc(ha, i, i + mid - 1) == hs[mid])
        a[i] = mid, l = mid + 1;
      else
        r = mid - 1;
    }
  }
  for (int i = n; i >= 1; i--) {
    int l = 0, r = std::min(i, m);
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (Calc(hb, i - mid + 1, i) == Calc(hs, m - mid + 1, m))
        b[i] = mid, l = mid + 1;
      else
        r = mid - 1;
    }
  }
  for (int i = 1; i <= n; i++) rt[i] = Modify(0, n, b[i], rt[i - 1]);
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    if (m - a[i] > n) continue;
    int lim = std::max(0, m - a[i]), r = std::min(i + m - 2, n);
    auto [c, s] = Query(lim, n, 0, n, rt[i - 1], rt[r]);
    ans += c * (a[i] - m + 1LL) + s;
    if (a[i] >= m) ans -= c;
    if (m <= n) ans -= Query(m, n, 0, n, rt[i - 1], rt[r]).first;
  }
  std::cout << ans;
  return 0;
}