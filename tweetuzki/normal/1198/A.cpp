#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 400000 + 5;

int N, K, I;
int A[MaxN], D[MaxN];
int Buc[MaxN], Num;

void init() {
  scanf("%d %d", &N, &I);
  I *= 8;
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
    D[i] = A[i];
  }
  std::sort(A + 1, A + 1 + N);
  std::sort(D + 1, D + 1 + N);
  for (int i = 1; i <= N; ++i)
    A[i] = std::lower_bound(D + 1, D + 1 + N, A[i]) - D;
}

void solve() {
  int k = I / N;
  K = 1;
  for (int i = 1; i <= k && K < N; ++i) K <<= 1;
  if (K >= N) {
    printf("%d\n", 0);
    return;
  }
  Buc[A[1]]++; Num = 1;
  int ans = N;
  for (int l = 1, r = 1; l <= N; ++l) {
    while (r < N && (Num < K || (Num == K && Buc[A[r + 1]] > 0))) {
      r++;
      Buc[A[r]]++;
      if (Buc[A[r]] == 1) Num++;
    }
    ans = std::min(ans, N - (r - l + 1));
    Buc[A[l]]--;
    if (Buc[A[l]] == 0) Num--;
  }
  printf("%d\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}