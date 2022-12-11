#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 5000;
const long long INF = 0x7F7F7F7F7F7F7F7F;

int N, _S, _E;
long long X[MaxN + 5], A[MaxN + 5], B[MaxN + 5], C[MaxN + 5], D[MaxN + 5];
long long F[MaxN + 5], G[MaxN + 5];

void init() {
  scanf("%d %d %d", &N, &_S, &_E);
  for (int i = 1; i <= N; ++i) scanf("%lld", &X[i]);
  for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
  for (int i = 1; i <= N; ++i) scanf("%lld", &B[i]);
  for (int i = 1; i <= N; ++i) scanf("%lld", &C[i]);
  for (int i = 1; i <= N; ++i) scanf("%lld", &D[i]);
  for (int i = 1; i <= N; ++i) {
    A[i] += X[i];
    B[i] -= X[i];
    C[i] += X[i];
    D[i] -= X[i];
  }
}

void solve() {
  memset(F, 0x7F, sizeof F);
  F[0] = 0;
  for (int i = 1; i < N; ++i) {
    memcpy(G, F, sizeof F);
    memset(F, 0x7F, sizeof F);
    for (int j = 0; j <= N; ++j) {
      if (i == _S) {
        F[j] = std::min(F[j], G[j + 1] + C[i]);
        F[j] = std::min(F[j], G[j] + D[i]);
      } else if (i == _E) {
        F[j] = std::min(F[j], G[j + 1] + A[i]);
        F[j] = std::min(F[j], G[j] + B[i]);
      } else {
        if (j > 0 || i >= _S) F[j] = std::min(F[j], G[j] + A[i] + D[i]);
        if (j > 0 || i >= _E) F[j] = std::min(F[j], G[j] + B[i] + C[i]);
        if (j > 0 || i >= _S || i >= _E) F[j] = std::min(F[j], G[j + 1] + A[i] + C[i]);
        if (j != 0) F[j] = std::min(F[j], G[j - 1] + B[i] + D[i]);
      }
      // printf("F[%d] = %lld\n", j, F[j]);
    }
  }
  if (N == _S) printf("%lld\n", F[0] + C[N]);
  else if (N == _E) printf("%lld\n", F[0] + A[N]);
  else printf("%lld\n", F[0] + A[N] + C[N]);
}

int main() {
  init();
  solve();
  return 0;
}