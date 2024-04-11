#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>

const int MaxN = 200000, MaxLog = 18;

int N, M, Q;
int A[MaxN + 5];
int PreDif[MaxN + 5], NxtDif[MaxN + 5];
int Stk1[MaxN + 5], Tp1, Stk2[MaxN + 5], Tp2;
int MinJ[MaxN + 5], Nx1[MaxN + 5], Nx2[MaxN + 5];
int Buc[MaxN + 5], Pop1[MaxN + 5], Pop2[MaxN + 5];
int X[MaxN + 5], R[MaxN + 5];
int St[MaxLog + 2][MaxN + 5], St2[MaxLog + 2][MaxN + 5];
std::set<int> S;

void init() {
  scanf("%d %d", &N, &Q);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  for (int i = 1; i <= N; ++i) {
    if (A[i - 1] != A[i]) PreDif[i] = i - 1;
    else PreDif[i] = PreDif[i - 1];
  }
  for (int i = N; i >= 1; --i) {
    if (A[i + 1] != A[i]) NxtDif[i] = i + 1;
    else NxtDif[i] = NxtDif[i + 1];
  }
  R[0] = N + 1;
  for (int i = 1; i <= N; ++i) {
    if (PreDif[i] == 0 || NxtDif[i] == N + 1) continue;
    if (1LL * (A[i] - A[PreDif[i]]) * (A[i] - A[NxtDif[i]]) > 0) {
      M++;
      X[M] = i, R[M] = NxtDif[i];
      if (R[M] < R[St2[0][PreDif[i]]]) St2[0][PreDif[i]] = M;
    }
  }
}

inline int gt(int x) {
  int lbound = 1, rbound = Tp1, ans = N + 1;
  while (lbound <= rbound) {
    int mid = (lbound + rbound) >> 1;
    if (A[Stk1[mid]] > x) {
      ans = Stk1[mid];
      lbound = mid + 1;
    } else rbound = mid - 1;
  }
  return ans;
}

inline int lt(int x) {
  int lbound = 1, rbound = Tp2, ans = N + 1;
  while (lbound <= rbound) {
    int mid = (lbound + rbound) >> 1;
    if (A[Stk2[mid]] < x) {
      ans = Stk2[mid];
      lbound = mid + 1;
    } else rbound = mid - 1;
  }
  return ans;
}

inline int query(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  int ls = St[k][l], rs = St[k][r - (1 << k) + 1];
  if (MinJ[ls] <= MinJ[rs]) return ls;
  else return rs;
}

inline int query2(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  int ls = St2[k][l], rs = St2[k][r - (1 << k) + 1];
  if (R[ls] <= R[rs]) return ls;
  else return rs;
}

void solve() {
  S.insert(N + 1);
  for (int i = N; i >= 1; --i) {
    while (Tp1 > 0 && A[Stk1[Tp1]] < A[i]) {
      Buc[Stk1[Tp1]]--;
      Pop1[Stk1[Tp1]] = i;
      if (Buc[Stk1[Tp1]] == 0) S.insert(Stk1[Tp1]);
      Tp1--;
    }
    Stk1[++Tp1] = i, Buc[i]++;
    while (Tp2 > 0 && A[Stk2[Tp2]] > A[i]) {
      Buc[Stk2[Tp2]]--;
      Pop2[Stk2[Tp2]] = i;
      if (Buc[Stk2[Tp2]] == 0) S.insert(Stk2[Tp2]);
      Tp2--;
    }
    Stk2[++Tp2] = i, Buc[i]++;
    Nx1[i] = gt(A[i]), Nx2[i] = lt(A[i]);
    MinJ[i] = *(S.lower_bound(std::max(Nx1[i], Nx2[i])));
  }
  for (int i = 1; i <= N; ++i) St[0][i] = i;
  for (int i = 1; (1 << i) <= N; ++i)
    for (int j = 1; j + (1 << i) - 1 <= N; ++j) {
      int ls = St[i - 1][j], rs = St[i - 1][j + (1 << (i - 1))];
      if (MinJ[ls] <= MinJ[rs]) St[i][j] = ls;
      else St[i][j] = rs;
      ls = St2[i - 1][j], rs = St2[i - 1][j + (1 << (i - 1))];
      if (R[ls] <= R[rs]) St2[i][j] = ls;
      else St2[i][j] = rs;
    }
  for (int q = 1; q <= Q; ++q) {
    int l, r;
    scanf("%d %d", &l, &r);
    int minpos = query(l, r);
    if (MinJ[minpos] <= r) {
      int x = Pop1[MinJ[minpos]], y = Pop2[MinJ[minpos]];
      if (A[minpos] < A[MinJ[minpos]]) y = Nx2[minpos];
      else x = Nx1[minpos];
      printf("%d\n", 4);
      printf("%d %d %d %d\n", minpos, std::min(x, y), std::max(x, y), MinJ[minpos]);
    } else {
      int k = query2(l, r);
      if (R[k] <= r) {
        printf("%d\n", 3);
        printf("%d %d %d\n", PreDif[X[k]], X[k], R[k]);
      } else printf("%d\n\n", 0);
    }
  }
}

int main() {
  init();
  solve();
  return 0;
}