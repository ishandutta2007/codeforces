#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>

const int MaxN = 500000;
const int MaxLog = 19;
const int MaxV = 10000000 + 5;

int N, D;
int A[MaxN + 5];
int Sa[MaxN + 5], Rnk[MaxN + 5], Tmp[MaxN + 5], Height[MaxN + 5];
int St[MaxLog + 1][MaxN + 5], Log[MaxN + 5];
int F[MaxN + 5];

struct PersistentTree {
  int cntv, Rt[MaxN + 5];
  int Lson[MaxV + 5], Rson[MaxV + 5], Val[MaxV + 5];

  void updateTree(int pos, int val, int &u, int v, int l, int r) {
    u = ++cntv;
    Val[u] = Val[v];
    if (l == r) {
      Val[u] = std::max(Val[u], val);
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
      Rson[u] = Rson[v];
      updateTree(pos, val, Lson[u], Lson[v], l, mid);
    } else {
      Lson[u] = Lson[v];
      updateTree(pos, val, Rson[u], Rson[v], mid + 1, r);
    }
    Val[u] = std::max(Val[Lson[u]], Val[Rson[u]]);
  }

  int queryTree(int left, int right, int l, int r, int i) {
    if (i == 0) return 0;
    if (left == l && right == r) return Val[i];
    int mid = (l + r) >> 1;
    if (right <= mid) return queryTree(left, right, l, mid, Lson[i]);
    else if (left > mid) return queryTree(left, right, mid + 1, r, Rson[i]);
    else return std::max(queryTree(left, mid, l, mid, Lson[i]), queryTree(mid + 1, right, mid + 1, r, Rson[i]));
  }
};
PersistentTree T;

void init() {
  static char s[MaxN + 5];
  scanf("%d", &N);
  scanf("%s", s + 1);
  for (int i = 1; i <= N; ++i) A[i] = s[i] - 'a' + 1;
}

inline void quickSort() {
  static int buc[MaxN + 5];
  for (int i = 0; i <= D; ++i) buc[i] = 0;
  for (int i = 1; i <= N; ++i) buc[Rnk[i]]++;
  for (int i = 1; i <= D; ++i) buc[i] += buc[i - 1];
  for (int i = N; i >= 1; --i) Sa[buc[Rnk[Tmp[i]]]--] = Tmp[i];
}

void buildSa() {
  D = 26;
  for (int i = 1; i <= N; ++i) {
    Rnk[i] = A[i];
    Tmp[i] = i;
  }
  quickSort();
  for (int w = 1, cnt = 0; cnt != N; w <<= 1) {
    D = cnt; cnt = 0;
    for (int i = 1; i <= w; ++i) Tmp[++cnt] = N - w + i;
    for (int i = 1; i <= N; ++i)
      if (Sa[i] > w) Tmp[++cnt] = Sa[i] - w;
    quickSort();
    memcpy(Tmp, Rnk, sizeof Rnk);
    cnt = 0;
    for (int i = 1; i <= N; ++i) {
      if (i == 1 || Tmp[Sa[i - 1]] != Tmp[Sa[i]] || Tmp[Sa[i - 1] + w] != Tmp[Sa[i] + w]) cnt++;
      Rnk[Sa[i]] = cnt;
    }
  }
  for (int i = 1, h = 0; i <= N; ++i) {
    if (h != 0) h--;
    int j = Sa[Rnk[i] - 1];
    while (A[i + h] == A[j + h]) h++;
    Height[Rnk[i]] = h;
  }
}

void buildSt() {
  for (int i = 2; i <= N; ++i) Log[i] = Log[i >> 1] + 1;
  for (int i = 1; i <= N; ++i) St[0][i] = Height[i];
  for (int i = 1; (1 << i) <= N; ++i)
    for (int j = 1; j + (1 << i) - 1 <= N; ++j)
      St[i][j] = std::min(St[i - 1][j], St[i - 1][j + (1 << (i - 1))]);
}

inline int qmin(int l, int r) {
  int k = Log[r - l + 1];
  return std::min(St[k][l], St[k][r - (1 << k) + 1]);
}

inline std::pair<int, int> qrange(int x, int h) {
  int lbound = 1, rbound = x - 1, ansl = x;
  while (lbound <= rbound) {
    int mid = (lbound + rbound) >> 1;
    if (qmin(mid + 1, x) >= h) {
      ansl = mid;
      rbound = mid - 1;
    } else lbound = mid + 1;
  }
  lbound = x + 1, rbound = N;
  int ansr = x;
  while (lbound <= rbound) {
    int mid = (lbound + rbound) >> 1;
    if (qmin(x + 1, mid) >= h) {
      ansr = mid;
      lbound = mid + 1;
    } else rbound = mid - 1;
  }
  // printf("qrange(%d, %d) = [%d, %d]\n", x, h, ansl, ansr);
  return std::make_pair(ansl, ansr);
}

void solve() {
  buildSa();
  buildSt();
  F[N] = 1;
  T.updateTree(Rnk[N], F[N], T.Rt[N], 0, 1, N);
  for (int i = N - 1; i >= 1; --i) {
    F[i] = F[i + 1];
    if (F[i] != 0) F[i]--;
    for (;;) {
      int f = F[i] + 1;
      if (i + f > N + 1) break;
      std::pair<int, int> range1 = qrange(Rnk[i], f - 1), range2 = qrange(Rnk[i + 1], f - 1);
      int mx1 = T.queryTree(range1.first, range1.second, 1, N, T.Rt[i + f]),
          mx2 = T.queryTree(range2.first, range2.second, 1, N, T.Rt[i + f]);
      if (mx1 + 1 < f && mx2 + 1 < f) break;
      F[i]++;
    }
    // printf("F[%d] = %d\n", i, F[i]);
    T.updateTree(Rnk[i], F[i], T.Rt[i], T.Rt[i + 1], 1, N);
  }
  printf("%d\n", T.queryTree(1, N, 1, N, T.Rt[1]));
  // for (int i = 1; i <= N; ++i) printf("%d%c", A[i], " \n"[i == N]);
  // for (int i = 1; i <= N; ++i) printf("Sa[%d] = %d\n", i, Sa[i]);
  // for (int i = 1; i <= N; ++i) printf("Height[%d] = %d\n", i, Height[i]);
}

int main() {
  init();
  solve();
  return 0;
}