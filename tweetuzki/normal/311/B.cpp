#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>

#ifdef Tweetuzki
#define debug(arg...) fprintf(stderr, arg)
#else
#define debug(arg...) void(0)
#endif

const int MaxN = 100000, MaxM = 100000;

int N, M, P;
int D[MaxN + 5];
int H[MaxM + 5], T[MaxM + 5];
int A[MaxM + 5];
long long Pre[MaxM + 5];
std::pair<long long, int> F[MaxM + 5];
long long G[MaxM + 5];

void init() {
  scanf("%d %d %d", &N, &M, &P);
  for (int i = 2; i <= N; ++i) scanf("%d", &D[i]);
  for (int i = 2; i <= N; ++i) D[i] += D[i - 1];
  for (int i = 1; i <= M; ++i) scanf("%d %d", &H[i], &T[i]);
  for (int i = 1; i <= M; ++i) A[i] = T[i] - D[H[i]];
  std::sort(A + 1, A + 1 + M);
  for (int i = 1; i <= M; ++i) Pre[i] = Pre[i - 1] + A[i];
}

inline double getSlope(int j, int k) {
  return 1.0 * (G[j] - G[k]) / (1.0 * (j - k));
}

inline bool check(long long mid) {
  static int que[MaxM + 5];
  int head = 1, tail = 0;
  F[0] = std::make_pair(0, 0);
  G[0] = F[0].first + Pre[0];
  que[++tail] = 0;
  for (int i = 1; i <= M; ++i) {
    while (head < tail && getSlope(que[head + 1], que[head]) < A[i]) head++;
    int j = que[head];
    debug("i = %d, j = %d\n", i, j);
    F[i].first = 1LL * A[i] * (i - j) - Pre[i] + G[j] + mid;
    F[i].second = F[j].second + 1;
    G[i] = F[i].first + Pre[i];
    debug("G[%d] = %lld\n", i, G[i]);
    while (head < tail && getSlope(i, que[tail]) < getSlope(que[tail], que[tail - 1])) tail--;
    que[++tail] = i;
  }
  return F[M].second <= P;
}

void solve() {
  long long lbound = 0, rbound = 1LL * (A[M] - A[1]) * (A[M] - A[1]), ans = 0;
  for (int i = 1; i <= M; ++i) debug("%d%c", A[i], " \n"[i == M]);
  while (lbound <= rbound) {
    long long mid = (lbound + rbound) >> 1;
    if (check(mid) == false) {
      ans = mid + 1;
      lbound = mid + 1;
    } else rbound = mid - 1;
  }
  debug("ans = %lld\n", ans);
  check(ans);
  for (int i = 1; i <= M; ++i) debug("F[%d] = (%lld, %d)\n", i, F[i].first, F[i].second);
  printf("%lld\n", F[M].first - P * ans);
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