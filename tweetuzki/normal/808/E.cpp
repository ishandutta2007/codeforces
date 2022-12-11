#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <vector>

const int MaxN = 1000000 + 5;

int N; long long M;
long long A[4][MaxN]; int Cnt[4];
long long F[MaxN * 2];

void init() {
  scanf("%d %lld", &N, &M);
  for (int i = 1; i <= N; ++i) {
    int w; long long c;
    scanf("%d %lld", &w, &c);
    Cnt[w]++;
    A[w][Cnt[w]] = c;
  }
}

void solve() {
  std::sort(A[1] + 1, A[1] + 1 + Cnt[1], std::greater<long long>());

  memset(F, 0x80, sizeof F);
  F[0] = 0, F[1] = A[1][1];
  static long long b[MaxN]; int cntb = 0;
  for (int i = 1; i <= Cnt[1]; i += 2)
    b[++cntb] = A[1][i] + A[1][i + 1];
  for (int i = 1; i <= Cnt[2]; ++i)
    b[++cntb] = A[2][i];
  std::sort(b + 1, b + 1 + cntb, std::greater<long long>());
  for (int i = 2; i <= M && (i >> 1) <= cntb; i += 2)
    F[i] = F[i - 2] + b[i >> 1];
  cntb = 0;
  for (int i = 2; i <= Cnt[1]; i += 2)
    b[++cntb] = A[1][i] + A[1][i + 1];
  for (int i = 1; i <= Cnt[2]; ++i)
    b[++cntb] = A[2][i];
  std::sort(b + 1, b + 1 + cntb, std::greater<long long>());
  for (int i = 3; i <= M && (i >> 1) <= cntb; i += 2)
    F[i] = F[i - 2] + b[i >> 1];
  for (int i = 1; i <= 2 * N && i <= M; ++i) F[i] = std::max(F[i], F[i - 1]);

  long long ans = 0;
  std::sort(A[3] + 1, A[3] + 1 + Cnt[3], std::greater<long long>());
  long long sum = 0;
  for (int i = 0; i <= Cnt[3]; ++i) {
    if (i * 3 > M) break;
    sum += A[3][i];
    ans = std::max(ans, sum + F[std::min(M - i * 3, 1LL * N * 2)]);
  }
  printf("%lld\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}