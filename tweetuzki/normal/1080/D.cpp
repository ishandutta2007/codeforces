#include <cstdio>

#define Yes(xx) { printf("Yes %d\n", xx); return; }
#define No { puts("No"); return; }

int T, N;
long long K;

inline bool check() {
  long long f = 1;
  for (int i = 2; i <= N; ++i) {
    f = f * 4 + 1;
    if (f >= K) return true;
  }
  return f >= K;
}

void solve() {
  scanf("%d %lld", &N, &K);
  if (check() == false) No
  if (N == 2 && K == 3) No
  for (int i = 1; i <= N; ++i) {
    K -= (1LL << i) - 1;
    if (K < 0) Yes(N - i + 1)
  }
  Yes(0)
}

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) solve();
  return 0;
}