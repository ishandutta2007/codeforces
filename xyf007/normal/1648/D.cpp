#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <iostream>
#include <numeric>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, m;
long long a[4][500001], s[4][500001], sl[500002], sr[500001];
struct Node {
  int l, r;
  long long c;
} b[500001];
class SegmentTree1 {
 public:
  SegmentTree1() {}
  void Build(int l, int r, int x) {
    if (l == r) {
      max_[x] = sl[l];
      return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
    Pushup(x);
  }
  void Modify(int l, int r, int p, int x) {
    if (l == r) {
      max_[x] = sl[l];
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      Modify(l, mid, p, x + x);
    else
      Modify(mid + 1, r, p, x + x + 1);
    Pushup(x);
  }
  long long Query(int L, int R, int l, int r, int x) {
    if (L <= l && r <= R) return max_[x];
    int mid = (l + r) >> 1;
    if (R <= mid) return Query(L, R, l, mid, x + x);
    if (L > mid) return Query(L, R, mid + 1, r, x + x + 1);
    return std::max(Query(L, R, l, mid, x + x),
                    Query(L, R, mid + 1, r, x + x + 1));
  }
  ~SegmentTree1() {}

 private:
  long long max_[2000001];
  void Pushup(int x) { max_[x] = std::max(max_[x + x], max_[x + x + 1]); }
} sgt1;
class SegmentTree2 {
 public:
  SegmentTree2() {}
  void Build(int l, int r, int x) {
    if (l == r) {
      t_[x] = {sl[l], sr[l], sl[l] + sr[l]};
      return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
    Pushup(x);
  }
  long long Query(int l, int r) { return Query(l, r, 1, n, 1).ms; }
  ~SegmentTree2() {}

 private:
  struct Node {
    long long ml, mr, ms;
    Node operator+(const Node &rhs) const {
      return {std::max(ml, rhs.ml), std::max(mr, rhs.mr),
              std::max({ms, rhs.ms, ml + rhs.mr})};
    }
  } t_[2000001];
  void Pushup(int x) { t_[x] = t_[x + x] + t_[x + x + 1]; }
  Node Query(int L, int R, int l, int r, int x) {
    if (L <= l && r <= R) return t_[x];
    int mid = (l + r) >> 1;
    if (R <= mid) return Query(L, R, l, mid, x + x);
    if (L > mid) return Query(L, R, mid + 1, r, x + x + 1);
    return Query(L, R, l, mid, x + x) + Query(L, R, mid + 1, r, x + x + 1);
  }
} sgt2;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= n; j++) std::cin >> a[i][j];
    std::partial_sum(a[i] + 1, a[i] + n + 1, s[i] + 1);
  }
  for (int i = 1; i <= n; i++) sl[i] = s[1][i] - s[2][i - 1];
  for (int i = 1; i <= n; i++) sr[i] = s[3][n] - s[3][i - 1] + s[2][i];
  for (int i = 1; i <= m; i++) std::cin >> b[i].l >> b[i].r >> b[i].c;
  std::sort(b + 1, b + m + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.r < rhs.r; });
  sgt1.Build(1, n, 1);
  for (int i = 1; i <= m; i++) {
    long long w = sgt1.Query(b[i].l, b[i].r, 1, n, 1) - b[i].c;
    checkmax(sl[b[i].r + 1], w);
    if (b[i].r + 1 <= n) sgt1.Modify(1, n, b[i].r + 1, 1);
  }
  sgt2.Build(1, n, 1);
  long long ans = -0x3f3f3f3f3f3f3f3fLL;
  for (int i = 1; i <= m; i++)
    checkmax(ans, sgt2.Query(b[i].l, b[i].r) - b[i].c);
  std::cout << ans;
  return 0;
}