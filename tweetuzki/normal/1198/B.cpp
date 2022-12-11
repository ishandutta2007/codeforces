#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 200000 + 5;
const int MaxV = 800000 + 5;

int N, Q;
int A[MaxN], Ans[MaxN];

struct SegTree {
  int L[MaxV], R[MaxV];
  int Min[MaxV], Tag[MaxV];

  inline void pushUp(int i) {
    Min[i] = std::min(Min[i << 1], Min[i << 1 | 1]);
  }

  inline void pushDown(int i) {
    if (Tag[i] != -1) {
      int ls = i << 1, rs = i << 1 | 1;
      if (Min[ls] < Tag[i]) {
        Tag[ls] = Tag[i];
        Min[ls] = Tag[i];
      }
      if (Min[rs] < Tag[i]) {
        Tag[rs] = Tag[i];
        Min[rs] = Tag[i];
      }
      Tag[i] = -1;
    }
  }

  void buildTree(int left, int right, int i) {
    L[i] = left, R[i] = right;
    Tag[i] = -1;
    if (L[i] == R[i]) {
      Min[i] = A[left];
      return;
    }
    int mid = (L[i] + R[i]) >> 1;
    buildTree(left, mid, i << 1);
    buildTree(mid + 1, right, i << 1 | 1);
    pushUp(i);
  }

  void updateTree(int pos, int val, int i) {
    if (L[i] == R[i]) {
      Min[i] = val;
      return;
    }
    pushDown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (pos <= mid) updateTree(pos, val, i << 1);
    else updateTree(pos, val, i << 1 | 1);
    pushUp(i);
  }

  void setTree(int left, int right, int val, int i) {
    if (L[i] == left && R[i] == right) {
      if (Min[i] < val) {
        Tag[i] = val;
        Min[i] = val;
      }
      return;
    }
    pushDown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (right <= mid) setTree(left, right, val, i << 1);
    else if (left > mid) setTree(left, right, val, i << 1 | 1);
    else setTree(left, mid, val, i << 1), setTree(mid + 1, right, val, i << 1 | 1);
    pushUp(i);
  }

  void getAnsTree(int i) {
    if (L[i] == R[i]) {
      Ans[L[i]] = Min[i];
      return;
    }
    pushDown(i);
    getAnsTree(i << 1);
    getAnsTree(i << 1 | 1);
  }
};
SegTree T;

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  scanf("%d", &Q);
}

void solve() {
  T.buildTree(1, N, 1);
  for (int i = 1; i <= Q; ++i) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int x, w;
      scanf("%d %d", &x, &w);
      T.updateTree(x, w, 1);
    } else {
      int x;
      scanf("%d", &x);
      T.setTree(1, N, x, 1);
    }
  }
  T.getAnsTree(1);
  for (int i = 1; i <= N; ++i)
    printf("%d%c", Ans[i], i == N ? '\n' : ' ');
}

int main() {
  init();
  solve();
  return 0;
}