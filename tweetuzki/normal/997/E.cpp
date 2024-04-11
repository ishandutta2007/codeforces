#include <cstdio>

const int MaxN = 120000 + 5, MaxQ = 120000 + 5;
const int MaxV = (1 << 18) + 5;

struct LinkedList {
  int cnte;
  int Head[MaxN], To[MaxQ], Next[MaxQ];

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int N, Q;
int A[MaxN];
int Ql[MaxQ], Qr[MaxQ];
long long Ans[MaxQ];
int MxStk[MaxN], MxTp, MnStk[MaxN], MnTp;
LinkedList G;

struct data {
  int val, num;
  long long sum;

  data(int _val = 0, int _num = 0, long long _sum = 0) {
    val = _val;
    num = _num;
    sum = _sum;
  }

  inline friend data operator + (const data &x, const data &y) {
    data z = x;
    if (y.val < x.val) z = y;
    else if (x.val == y.val) z.num += y.num;
    z.sum = x.sum + y.sum;
    return z;
  }
};

struct SegTree {
  int L[MaxV], R[MaxV];
  data V[MaxV];
  int Add[MaxV], Tag[MaxV];

  inline void pushDown(int i) {
    int ls = i << 1, rs = i << 1 | 1;
    if (Add[i] != 0) {
      Add[ls] += Add[i];
      V[ls].val += Add[i];
      Add[rs] += Add[i];
      V[rs].val += Add[i];
      Add[i] = 0;
    }
    if (Tag[i] != 0) {
      if (V[ls].val == V[i].val) {
        Tag[ls] += Tag[i];
        V[ls].sum += 1LL * Tag[i] * V[ls].num;
      }
      if (V[rs].val == V[i].val) {
        Tag[rs] += Tag[i];
        V[rs].sum += 1LL * Tag[i] * V[rs].num;
      }
      Tag[i] = 0;
    }
  }

  void buildTree(int left, int right, int i = 1) {
    L[i] = left, R[i] = right;
    if (L[i] == R[i]) {
      V[i] = data(0, 1, 0);
      return;
    }
    int mid = (L[i] + R[i]) >> 1;
    buildTree(left, mid, i << 1);
    buildTree(mid + 1, right, i << 1 | 1);
    V[i] = V[i << 1] + V[i << 1 | 1];
  }

  void updateTree(int left, int right, int val, int i = 1) {
    if (L[i] == left && R[i] == right) {
      Add[i] += val;
      V[i].val += val;
      return;
    }
    pushDown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (right <= mid) updateTree(left, right, val, i << 1);
    else if (left > mid) updateTree(left, right, val, i << 1 | 1);
    else updateTree(left, mid, val, i << 1), updateTree(mid + 1, right, val, i << 1 | 1);
    V[i] = V[i << 1] + V[i << 1 | 1];
  }

  void updateAns(int left, int right, int i = 1) {
    if (L[i] == left && R[i] == right) {
      if (V[i].val == -1) {
        Tag[i]++;
        V[i].sum += V[i].num;
      }
      return;
    }
    pushDown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (right <= mid) updateAns(left, right, i << 1);
    else if (left > mid) updateAns(left, right, i << 1 | 1);
    else updateAns(left, mid, i << 1), updateAns(mid + 1, right, i << 1 | 1);
    V[i] = V[i << 1] + V[i << 1 | 1];
  }

  data queryTree(int left, int right, int i = 1) {
    if (L[i] == left && R[i] == right) return V[i];
    pushDown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (right <= mid) return queryTree(left, right, i << 1);
    else if (left > mid) return queryTree(left, right, i << 1 | 1);
    return queryTree(left, mid, i << 1) + queryTree(mid + 1, right, i << 1 | 1);
  }
};
SegTree T;

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  scanf("%d", &Q);
  for (int i = 1; i <= Q; ++i) {
    scanf("%d %d", &Ql[i], &Qr[i]);
    G.addEdge(Qr[i], i);
  }
}

void solve() {
  T.buildTree(1, N);
  for (int i = 1; i <= N; ++i) {
    while (MxTp > 0 && A[MxStk[MxTp]] < A[i]) {
      T.updateTree(MxStk[MxTp - 1] + 1, MxStk[MxTp], A[i] - A[MxStk[MxTp]]);
      MxTp--;
    }
    MxStk[++MxTp] = i;
    while (MnTp > 0 && A[MnStk[MnTp]] > A[i]) {
      T.updateTree(MnStk[MnTp - 1] + 1, MnStk[MnTp], A[MnStk[MnTp]] - A[i]);
      MnTp--;
    }
    MnStk[++MnTp] = i;
    T.updateTree(1, i, -1);
    T.updateAns(1, i);
    for (int e = G.Head[i]; e; e = G.Next[e]) {
      int id = G.To[e];
      Ans[id] = T.queryTree(Ql[id], Qr[id]).sum;
    }
  }
  for (int i = 1; i <= Q; ++i) printf("%lld\n", Ans[i]);
}

int main() {
  init();
  solve();
  return 0;
}