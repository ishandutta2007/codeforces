#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 200000, MaxV = 400000;
const int MaxNodes = (1 << 20);

int N, V;
struct seg_t { int l, r, t; } A[MaxN + 5];

struct SegTree {
  int L[MaxNodes + 5], R[MaxNodes + 5];
  int Max[MaxNodes + 5], Tag[MaxNodes + 5];

  inline void upt(int x, int v) {
    Max[x] += v;
    Tag[x] += v;
  }

  inline void pushdown(int i) {
    if (Tag[i] != 0) {
      upt(i << 1, Tag[i]);
      upt(i << 1 | 1, Tag[i]);
      Tag[i] = 0;
    }
  }

  void buildTree(int left, int right, int i = 1) {
    L[i] = left, R[i] = right;
    Max[i] = Tag[i] = 0;
    if (L[i] == R[i]) return;
    int mid = (L[i] + R[i]) >> 1;
    buildTree(left, mid, i << 1);
    buildTree(mid + 1, right, i << 1 | 1);
  }

  void updateTree(int left, int right, int val, int i = 1) {
    if (left > right) return;
    if (left == L[i] && right == R[i]) {
      upt(i, val);
      return;
    }
    pushdown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (right <= mid) updateTree(left, right, val, i << 1);
    else if (left > mid) updateTree(left, right, val, i << 1 | 1);
    else updateTree(left, mid, val, i << 1), updateTree(mid + 1, right, val, i << 1 | 1);
    Max[i] = std::max(Max[i << 1], Max[i << 1 | 1]);
  }

  void updatePos(int pos, int val, int i = 1) {
    if (L[i] == R[i]) {
      Max[i] = val;
      return;
    }
    pushdown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (pos <= mid) updatePos(pos, val, i << 1);
    else updatePos(pos, val, i << 1 | 1);
    Max[i] = std::max(Max[i << 1], Max[i << 1 | 1]);
  }

  int queryTree(int left, int right, int i = 1) {
    if (left > right) return 0;
    if (L[i] == left && R[i] == right) return Max[i];
    pushdown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (right <= mid) return queryTree(left, right, i << 1);
    else if (left > mid) return queryTree(left, right, i << 1 | 1);
    else return std::max(queryTree(left, mid, i << 1), queryTree(mid + 1, right, i << 1 | 1));
  }
};
SegTree Wh, Bl;

template <typename Int>
inline void tense(Int &x, Int y) { if (y > x) x = y; }
template <typename Int>
inline void relax(Int &x, Int y) { if (y < x) x = y; }

void init() {
  static int d[MaxV + 5];
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d %d %d", &A[i].l, &A[i].r, &A[i].t);
    d[++V] = A[i].l, d[++V] = A[i].r;
  }
  std::sort(d + 1, d + 1 + V);
  for (int i = 1; i <= N; ++i) {
    A[i].l = std::lower_bound(d + 1, d + 1 + V, A[i].l) - d;
    A[i].r = std::lower_bound(d + 1, d + 1 + V, A[i].r) - d;
  }
}

inline bool seg_cmp(const seg_t &x, const seg_t &y) { return x.r < y.r; }

void solve() {
  std::sort(A + 1, A + 1 + N, seg_cmp);
  Wh.buildTree(0, V), Bl.buildTree(0, V);
  for (int l = 1, r = 0; l <= N; l = r + 1) {
    while (r < N && A[r + 1].r == A[l].r) r++;
    int wh_max = 0, bl_max = 0;
    for (int i = l; i <= r; ++i) {
      if (A[i].t == 2) Wh.updateTree(0, A[i].l - 1, 1);
      else Bl.updateTree(0, A[i].l - 1, 1);
    }
    for (int i = l; i <= r; ++i) {
      // printf("(%d, %d, %d)\n", A[i].l, A[i].r, A[i].t);
      if (A[i].t == 1) tense(wh_max, Bl.queryTree(0, A[i].l - 1));
      else tense(bl_max, Wh.queryTree(0, A[i].l - 1));
    }
    // printf("wh_max = %d, bl_max = %d\n", wh_max, bl_max);
    Wh.updatePos(A[l].r, wh_max);
    Bl.updatePos(A[l].r, bl_max);
  }
  printf("%d\n", std::max(Wh.queryTree(0, V), Bl.queryTree(0, V)));
}

int main() {
  init();
  solve();
  return 0;
}