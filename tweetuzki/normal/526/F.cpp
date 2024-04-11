#include <cstdio>

template <size_t StackSize>
class Stack {
private:
  int st[StackSize];
  int tp;
public:
  inline int size() { return tp; }
  inline bool empty() { return tp == 0; }
  inline void push(int x) { st[++tp] = x; }
  inline void pop() { tp--; }
  inline int top() { return st[tp]; }
};

const int MaxN = 300000;
const int MaxV = (1 << 20);

int N;
int A[MaxN + 5];
Stack<MaxN + 5> Mx, Mn;

struct data_t {
  int val, num;
  data_t(int _val = 0, int _num = 0) { val = _val, num = _num; }

  inline friend data_t operator+(const data_t &a, const data_t &b) {
    if (a.val == b.val) return data_t(a.val, a.num + b.num);
    else if (a.val < b.val) return a;
    else return b;
  }
};

struct SegTree {
  int L[MaxV + 5], R[MaxV + 5];
  int Add[MaxV + 5];
  data_t Val[MaxV + 5];

  inline void pushDown(int i) {
    if (Add[i] != 0) {
      int ls = i << 1, rs = i << 1 | 1;
      Add[ls] += Add[i];
      Val[ls].val += Add[i];
      Add[rs] += Add[i];
      Val[rs].val += Add[i];
      Add[i] = 0;
    }
  }

  void buildTree(int left, int right, int i = 1) {
    L[i] = left, R[i] = right;
    Add[i] = 0;
    if (L[i] == R[i]) {
      Val[i] = data_t(L[i], 1);
      return;
    }
    int mid = (L[i] + R[i]) >> 1;
    buildTree(left, mid, i << 1);
    buildTree(mid + 1, right, i << 1 | 1);
    Val[i] = Val[i << 1] + Val[i << 1 | 1];
  }

  void updateTree(int left, int right, int val, int i = 1) {
    if (L[i] == left && R[i] == right) {
      Add[i] += val;
      Val[i].val += val;
      return;
    }
    pushDown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (right <= mid) updateTree(left, right, val, i << 1);
    else if (left > mid) updateTree(left, right, val, i << 1 | 1);
    else updateTree(left, mid, val, i << 1), updateTree(mid + 1, right, val, i << 1 | 1);
    Val[i] = Val[i << 1] + Val[i << 1 | 1];
  }

  data_t queryTree(int left, int right, int i = 1) {
    if (L[i] == left && R[i] == right) return Val[i];
    pushDown(i);
    int mid = (L[i] + R[i]) >> 1;
    if (right <= mid) return queryTree(left, right, i << 1);
    else if (left > mid) return queryTree(left, right, i << 1 | 1);
    else return queryTree(left, mid, i << 1) + queryTree(mid + 1, right, i << 1 | 1);
  }
};
SegTree T;

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    int r, c;
    scanf("%d %d", &r, &c);
    A[r] = c;
  }
}

void solve() {
  T.buildTree(1, N);
  long long ans = 0;
  for (int i = 1; i <= N; ++i) {
    while (!Mx.empty() && A[Mx.top()] < A[i]) {
      int x = Mx.top(), y = 1;
      Mx.pop();
      if (!Mx.empty()) y = Mx.top() + 1;
      T.updateTree(y, x, A[i] - A[x]);
    }
    Mx.push(i);
    while (!Mn.empty() && A[Mn.top()] > A[i]) {
      int x = Mn.top(), y = 1;
      Mn.pop();
      if (!Mn.empty()) y = Mn.top() + 1;
      T.updateTree(y, x, A[x] - A[i]);
    }
    Mn.push(i);
    data_t d = T.queryTree(1, i);
    if (d.val == i) ans += d.num;
  }
  printf("%lld\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}