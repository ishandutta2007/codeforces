#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <utility>

#ifdef Tweetuzki
#define debug(arg...) fprintf(stderr, arg)
#else
#define debug(arg...) void(0)
#endif

const int MaxN = 100000, MaxM = 100000;
const int MaxV = MaxN + MaxM;

int N, M, V;
int A[MaxN + 5], B[MaxM + 5];
int D[MaxV + 5];
int F[MaxN + 5], G[MaxN + 5], L[MaxN + 5], P[MaxN + 5];
int PreGap[MaxN + 5], Cnt[MaxV + 5];
std::set< std::pair<int, int> > S[MaxN + 5];
int Ans[MaxN + 5];

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
    if (A[i] != -1) D[++V] = A[i];
  }
  scanf("%d", &M);
  for (int i = 1; i <= M; ++i) {
    scanf("%d", &B[i]);
    D[++V] = B[i];
  }
  std::sort(D + 1, D + 1 + V);
  V = std::unique(D + 1, D + 1 + V) - D - 1;
  for (int i = 1; i <= N; ++i)
    if (A[i] != -1) A[i] = std::lower_bound(D + 1, D + 1 + V, A[i]) - D;
  for (int i = 1; i <= M; ++i)
    B[i] = std::lower_bound(D + 1, D + 1 + V, B[i]) - D;
  std::sort(B + 1, B + 1 + M);
  for (int i = 1; i <= M; ++i) Cnt[B[i]]++;
  for (int i = 1, pregap = 0; i <= N; ++i) {
    if (A[i] == -1) {
      PreGap[i] = pregap;
      pregap = i;
    }
  }
  for (int i = 1; i <= N; ++i)
    debug("preGap[%d] = %d\n", i, PreGap[i]);
  debug("V = %d\n", V);
  debug("a: ");
  for (int i = 1; i <= N; ++i) debug("%d%c", A[i], " \n"[i == N]);
  debug("b: ");
  for (int i = 1; i <= M; ++i) debug("%d%c", B[i], " \n"[i == M]);
}

void solve() {
  int mxl = 0;
  for (int i = 1; i <= N; ++i) {
    if (A[i] != -1) {
      int lbound = 0, rbound = mxl, ans = 0;
      while (lbound <= rbound) {
        int mid = (lbound + rbound) >> 1;
        if (F[mid] < A[i]) {
          ans = mid;
          lbound = mid + 1;
        } else rbound = mid - 1;
      }
      L[i] = ans + 1;
      mxl = std::max(mxl, L[i]);
      P[i] = G[ans];
      F[L[i]] = A[i];
      G[L[i]] = i;
    } else {
      int lk = mxl;
      for (int j = M; j >= 1; --j) {
        while (F[lk] >= B[j]) lk--;
        mxl = std::max(mxl, lk + 1);
        F[lk + 1] = B[j];
        G[lk + 1] = i;
      }
    }
  }
  for (int i = 1; i <= N; ++i)
    debug("i = %d, l = %d, p = %d, f = %d, g = %d\n", i, L[i], P[i], F[i], G[i]);
  debug("ans = %d\n", mxl);
  static int stk[MaxN + 5], tp = 0;
  memcpy(Ans, A, sizeof A);
  for (int i = 1; i <= N; ++i)
    if (A[i] != -1) S[L[i]].insert(std::make_pair(A[i], i));
  for (int pos = G[mxl], lk = N; pos != 0;) {
    if (tp == mxl) break;
    debug("pos = %d, tp = %d\n", pos, tp);
    if (A[pos] != -1) {
      stk[++tp] = A[pos];
      pos = P[pos];
    } else {
      int value = tp == 0 ? B[M] : *(std::lower_bound(B + 1, B + 1 + M, stk[tp]) - 1);
      stk[++tp] = value;
      Ans[pos] = value;
      Cnt[value]--;
      while (lk >= pos) {
        S[L[lk]].erase(std::make_pair(A[lk], lk));
        lk--;
      }
      if (S[mxl - tp].empty() || S[mxl - tp].begin()->first >= stk[tp]) pos = PreGap[pos];
      else pos = S[mxl - tp].begin()->second;
    }
  }
  for (int i = 1, j = 1; i <= N; ++i) {
    if (Ans[i] == -1) {
      while (Cnt[j] == 0) j++;
      Ans[i] = j;
      Cnt[j]--;
    }
  }
  for (int i = 1; i <= N; ++i) printf("%d%c", D[Ans[i]], " \n"[i == N]);
}

int main() {
#ifdef Tweetuzki
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("errorfile.txt", "w", stderr);
#endif
  init();
  solve();
  return 0;
}