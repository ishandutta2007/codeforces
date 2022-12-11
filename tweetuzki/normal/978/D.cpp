#include <algorithm>
#include <cstdio>
#include <cstdlib>

const int MaxN = 100000 + 5;

int N;
int A[MaxN];

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
    scanf("%d", &A[i]);
}

inline int check(int a1, int a2) {
  int r = a2 - a1, f = a1 - r;
  int res = 0;
  for (int i = 1; i <= N; ++i) {
    int a = f + r * i;
    if (abs(a - A[i]) > 1) return N + 1;
    res += abs(a - A[i]);
  }
  return res;
}

void solve() {
  if (N == 1) {
    printf("%d\n", 0);
    return;
  }

  int Ans = N + 1;
  for (int a1 = A[1] - 1; a1 <= A[1] + 1; ++a1)
    for (int a2 = A[2] - 1; a2 <= A[2] + 1; ++a2)
      Ans = std::min(check(a1, a2), Ans);
  if (Ans == N + 1) printf("%d\n", -1);
  else printf("%d\n", Ans);
}

int main() {
  init();
  solve();
  return 0;
}