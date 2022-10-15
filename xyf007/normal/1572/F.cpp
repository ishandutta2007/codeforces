#include <cstring>
#include <iostream>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, q;
class SegmentTree {
 private:
  long long sum_[800001], tag_[800001];
  void Pushup(int x) { sum_[x] = sum_[x + x] + sum_[x + x + 1]; }
  void Add(int l, int r, int v, int x) {
    sum_[x] += static_cast<long long>(r - l + 1) * v, tag_[x] += v;
  }
  void Pushdown(int l, int r, int x) {
    if (tag_[x]) {
      int mid = (l + r) >> 1;
      Add(l, mid, tag_[x], x + x), Add(mid + 1, r, tag_[x], x + x + 1);
      tag_[x] = 0LL;
    }
  }

 public:
  void Build(int l, int r, int x) {
    if (l == r) {
      sum_[x] = 1LL;
      return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
    Pushup(x);
  }
  void Modify(int L, int R, int l, int r, int v, int x) {
    if (L <= l && r <= R) return Add(l, r, v, x);
    int mid = (l + r) >> 1;
    Pushdown(l, r, x);
    if (L <= mid) Modify(L, R, l, mid, v, x + x);
    if (R > mid) Modify(L, R, mid + 1, r, v, x + x + 1);
    Pushup(x);
  }
  long long Query(int L, int R, int l, int r, int x) {
    if (L <= l && r <= R) return sum_[x];
    Pushdown(l, r, x);
    int mid = (l + r) >> 1;
    long long ans = 0LL;
    if (L <= mid) ans += Query(L, R, l, mid, x + x);
    if (R > mid) ans += Query(L, R, mid + 1, r, x + x + 1);
    return ans;
  }
} sgt;
class SegmentTreeBeats {
 private:
  struct Node {
    int max, smax, cnt, tag;
  } t_[800001];
  void Pushup(int x) {
    if (t_[x + x].max == t_[x + x + 1].max) {
      t_[x].max = t_[x + x].max;
      t_[x].smax = std::max(t_[x + x].smax, t_[x + x + 1].smax);
      t_[x].cnt = t_[x + x].cnt + t_[x + x + 1].cnt;
    } else if (t_[x + x].max > t_[x + x + 1].max) {
      t_[x].max = t_[x + x].max;
      t_[x].smax = std::max(t_[x + x].smax, t_[x + x + 1].max);
      t_[x].cnt = t_[x + x].cnt;
    } else {
      t_[x].max = t_[x + x + 1].max;
      t_[x].smax = std::max(t_[x + x].max, t_[x + x + 1].smax);
      t_[x].cnt = t_[x + x + 1].cnt;
    }
  }
  void Min(int v, int x) { t_[x].max = t_[x].tag = v; }
  void Pushdown(int x) {
    if (t_[x].tag != -1) {
      if (t_[x].tag < t_[x + x].max) Min(t_[x].tag, x + x);
      if (t_[x].tag < t_[x + x + 1].max) Min(t_[x].tag, x + x + 1);
      t_[x].tag = -1;
    }
  }

 public:
  void Build(int l, int r, int x) {
    t_[x].tag = -1;
    if (l == r) {
      t_[x] = {l, -0x3f3f3f3f, 1, -1};
      return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x), Build(mid + 1, r, x + x + 1);
    Pushup(x);
  }
  void Modify(int l, int r, int p, int v, int x) {
    if (l == r) {
      t_[x] = {v, -0x3f3f3f3f, 1, -1};
      return;
    }
    Pushdown(x);
    int mid = (l + r) >> 1;
    if (p <= mid)
      Modify(l, mid, p, v, x + x);
    else
      Modify(mid + 1, r, p, v, x + x + 1);
    Pushup(x);
  }
  void Min(int L, int R, int l, int r, int v, int x) {
    if (L <= l && r <= R) {
      if (v >= t_[x].max) return;
      if (v > t_[x].smax) {
        sgt.Modify(v + 1, t_[x].max, 1, n, -t_[x].cnt, 1);
        return Min(v, x);
      }
    }
    Pushdown(x);
    int mid = (l + r) >> 1;
    if (L <= mid) Min(L, R, l, mid, v, x + x);
    if (R > mid) Min(L, R, mid + 1, r, v, x + x + 1);
    Pushup(x);
  }
  int Query(int l, int r, int p, int x) {
    if (l == r) return t_[x].max;
    Pushdown(x);
    int mid = (l + r) >> 1;
    if (p <= mid)
      return Query(l, mid, p, x + x);
    else
      return Query(mid + 1, r, p, x + x + 1);
  }
} sgtb;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> q;
  sgtb.Build(1, n, 1), sgt.Build(1, n, 1);
  while (q--) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if (op == 1) {
      if (x > 1) sgtb.Min(1, x - 1, 1, n, x - 1, 1);
      int r = sgtb.Query(1, n, x, 1);
      sgt.Modify(x, r, 1, n, -1, 1);
      sgtb.Modify(1, n, x, y, 1), sgt.Modify(x, y, 1, n, 1, 1);
    } else {
      std::cout << sgt.Query(x, y, 1, n, 1) << '\n';
    }
  }
  return 0;
}