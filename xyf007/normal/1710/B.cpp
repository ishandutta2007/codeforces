#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <iostream>
#include <utility>
constexpr long long kN = 1000000000;
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int T, n, ans[200001];
long long m, h[200001];
struct Node {
  long long x, p, id;
} a[200001];
std::pair<int, long long> operator+(const std::pair<int, long long> &lhs,
                                    const std::pair<int, long long> &rhs) {
  return {lhs.first + rhs.first, lhs.second + rhs.second};
}
class Sgt {
 public:
  void Clear() {
    for (int i = 1; i <= tot_; i++)
      t_[i].ls = t_[i].rs = t_[i].cnt = t_[i].sum = 0;
    tot_ = 1;
  }
  void Pushup(int x) {
    t_[x].cnt = t_[t_[x].ls].cnt + t_[t_[x].rs].cnt;
    t_[x].sum = t_[t_[x].ls].sum + t_[t_[x].rs].sum;
  }
  void Modify(int l, int r, int p, long long v, int x) {
    if (l == r) {
      t_[x].cnt++, t_[x].sum += v;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) {
      if (!t_[x].ls) t_[x].ls = ++tot_;
      Modify(l, mid, p, v, t_[x].ls);
    } else {
      if (!t_[x].rs) t_[x].rs = ++tot_;
      Modify(mid + 1, r, p, v, t_[x].rs);
    }
    Pushup(x);
  }
  std::pair<int, long long> Query(int L, int R, int l, int r, int x) {
    if (!x) return {0, 0LL};
    if (L <= l && r <= R) return {t_[x].cnt, t_[x].sum};
    int mid = (l + r) >> 1;
    std::pair<int, long long> ans;
    if (L <= mid) ans = ans + Query(L, R, l, mid, t_[x].ls);
    if (R > mid) ans = ans + Query(L, R, mid + 1, r, t_[x].rs);
    return ans;
  }

 private:
  int tot_;
  struct Node {
    int ls, rs, cnt;
    long long sum;
  } t_[7000001];
} sgt;
int xx[200001], lg[200001];
long long pre[200001], suf[200005], st1[21][200001], st2[21][200001];
long long Query1(int l, int r) {
  if (l > r) return -kN;
  int len = lg[r - l + 1];
  return std::max(st1[len][l], st1[len][r - (1 << len) + 1]);
}
long long Query2(int l, int r) {
  if (l > r) return -kN;
  int len = lg[r - l + 1];
  return std::max(st2[len][l], st2[len][r - (1 << len) + 1]);
}
void Solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i].x >> a[i].p, a[i].id = i;
  std::sort(a + 1, a + n + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.x < rhs.x; });
  for (int i = 1; i <= n; i++) h[i] = a[i].p;
  sgt.Clear();
  for (int i = 1; i <= n; i++) {
    auto [c, s] = sgt.Query(a[i].x, kN, 1, kN, 1);
    h[i] += s - (long long)c * a[i].x;
    sgt.Modify(1, kN, std::min(a[i].x + a[i].p, kN), a[i].x + a[i].p, 1);
  }
  sgt.Clear();
  for (int i = n; i >= 1; i--) {
    auto [c, s] = sgt.Query(1, a[i].x, 1, kN, 1);
    h[i] += s + (long long)c * a[i].x;
    sgt.Modify(1, kN, std::max(1LL, a[i].x - a[i].p), a[i].p - a[i].x, 1);
  }
  // for (int i = 1; i <= n; i++) std::cerr << h[i] << " \n"[i == n];
  for (int i = 1; i <= n; i++) xx[i] = a[i].x;
  for (int i = 1; i <= n; i++) pre[i] = std::max(pre[i - 1], h[i]);
  suf[n + 1] = 0;
  for (int i = n; i >= 0; i--) suf[i] = std::max(suf[i + 1], h[i]);
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; i++) st1[0][i] = h[i] - a[i].x;
  for (int i = 1; i <= lg[n]; i++)
    for (int j = 1; j + (1 << i) - 1 <= n; j++)
      st1[i][j] = std::max(st1[i - 1][j], st1[i - 1][j + (1 << (i - 1))]);
  for (int i = 1; i <= n; i++) st2[0][i] = h[i] + a[i].x;
  for (int i = 1; i <= lg[n]; i++)
    for (int j = 1; j + (1 << i) - 1 <= n; j++)
      st2[i][j] = std::max(st2[i - 1][j], st2[i - 1][j + (1 << (i - 1))]);
  std::fill(ans + 1, ans + n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int p1 = std::lower_bound(xx + 1, xx + n + 1, a[i].x - a[i].p) - xx,
        p2 = std::upper_bound(xx + 1, xx + n + 1, a[i].x + a[i].p) - xx;
    if (pre[p1 - 1] <= m && Query1(p1, i - 1) - a[i].p + a[i].x <= m &&
        Query2(i, p2 - 1) - a[i].p - a[i].x <= m && suf[p2] <= m)
      ans[a[i].id] = 1;
  }
  for (int i = 1; i <= n; i++) std::cout << ans[i];
  std::cout << '\n';
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}