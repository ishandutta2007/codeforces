#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <algorithm>
#include <cctype>
#include <cstdio>
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while (!std::isdigit(c = std::getchar()))
    if (c == '-') f = -1;
  x = c - '0';
  while (std::isdigit(c = std::getchar())) x = x * 10 + c - '0';
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x), Read(args...);
}
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}
int n, m, k;
struct Rect {
  int x1, y1, x2, y2;
} a[50001];
int y[100001];
struct Node {
  int x, y1, y2, op;
} c[100001];
class SegmentTree {
 public:
  SegmentTree() {}
  void Modify(int L, int R, int l, int r, int v, int x) {
    if (L <= l && r <= R) {
      t_[x].cnt += v;
      return Pushup(l, r, x);
    }
    int mid = (l + r) >> 1;
    if (L <= mid) Modify(L, R, l, mid, v, x + x);
    if (R > mid) Modify(L, R, mid + 1, r, v, x + x + 1);
    Pushup(l, r, x);
  }
  int sum() const { return t_[1].sum; }
  ~SegmentTree() {}

 private:
  struct Node {
    int cnt, sum;
  } t_[400001];
  void Pushup(int l, int r, int x) {
    if (t_[x].cnt)
      t_[x].sum = y[r] ^ y[l - 1];
    else if (l == r)
      t_[x].sum = 0;
    else
      t_[x].sum = t_[x + x].sum ^ t_[x + x + 1].sum;
  }
} sgt;
int main(int argc, char const *argv[]) {
  Read(n, m, k);
  for (int i = 1; i <= m; i++) Read(a[i].x1, a[i].y1, a[i].x2, a[i].y2);
  int cy = 0;
  for (int i = 1; i <= m; i++) y[++cy] = a[i].y1 - 1, y[++cy] = a[i].y2;
  std::sort(y + 1, y + cy + 1);
  cy = std::unique(y + 1, y + cy + 1) - y - 1;
  int cx = 0;
  for (int i = 1; i <= m; i++) {
    c[++cx] = {a[i].x1 - 1, a[i].y1 - 1, a[i].y2, 1};
    c[++cx] = {a[i].x2, a[i].y1 - 1, a[i].y2, -1};
  }
  std::sort(c + 1, c + cx + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.x < rhs.x; });
  int ans = 0;
  for (int l = 1, r; l <= cx; l = r + 1) {
    ans ^= sgt.sum() & (c[l].x ^ c[l - 1].x);
    r = l;
    while (r < cx && c[r + 1].x == c[l].x) r++;
    for (int i = l; i <= r; i++) {
      int pl = std::lower_bound(y + 1, y + cy + 1, c[i].y1) - y + 1,
          pr = std::lower_bound(y + 1, y + cy + 1, c[i].y2) - y;
      sgt.Modify(pl, pr, 1, cy, c[i].op, 1);
    }
  }
  int S = 1;
  while (S <= k) S <<= 1;
  S--;
  std::printf(ans & S ? "Hamed" : "Malek");
  return 0;
}