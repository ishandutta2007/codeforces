#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int MaxN = 300, MaxM = 300;

int Te, N, M;
int A[MaxN + 5][MaxM + 5];
int B[MaxN + 5][MaxM + 5];

void init() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      scanf("%d", &A[i][j]);
}

void solve() {
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      B[i][j] = 4;
  for (int i = 1; i <= N; ++i) B[i][1] = B[i][M] = 3;
  for (int i = 1; i <= M; ++i) B[1][i] = B[N][i] = 3;
  B[1][1] = B[1][M] = B[N][1] = B[N][M] = 2;
  bool ok = true;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      if (A[i][j] > B[i][j]) ok = false;
  if (ok == true) {
    puts("YES");
    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= M; ++j)
        printf("%d%c", B[i][j], " \n"[j == M]);
  } else puts("NO");
}

int main() {
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    init();
    solve();
  }
  return 0;
}