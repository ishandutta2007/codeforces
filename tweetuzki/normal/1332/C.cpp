#include <algorithm>
#include <cstdio>
#include <cstring>
 
const int MaxN = 200000;
 
int Te;
int N, K;
char S[MaxN + 5];
int Cnt[MaxN + 5][26], Sum[MaxN + 5];
int F[MaxN + 5];
 
void init() {
  scanf("%d %d", &N, &K);
  scanf("%s", S);
  for (int i = 0; i < N; ++i)
    for (int c = 0; c < 26; ++c)
      Cnt[i][c] = 0;
  for (int i = 0; i <= N; ++i) F[i] = 0;
}
 
void solve() {
  for (int i = 0; i < N; ++i) Cnt[i % K][S[i] - 'a']++;
  int f = 0;
  for (int i = 0; i * 2 < K; ++i) {
    int j = K - i - 1;
    int res = 2 * N;
    for (int c = 0; c < 26; ++c) {
      int cost = N / K - Cnt[i][c];
      if (i != j) cost += N / K - Cnt[j][c];
      res = std::min(res, cost);
    }
    f += res;
  }
  printf("%d\n", f);
}
 
int main() {
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    init();
    solve();
  }
  return 0;
}