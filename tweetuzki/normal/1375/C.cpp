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

const int MaxN = 300000;

int Te, N;
int A[MaxN + 5];
int Stk[MaxN + 5], Tp;

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
}

void solve() {
  Tp = 0;
  for (int i = 1; i <= N; ++i) {
    while (Tp > 1) {
      int x = Stk[Tp];
      if (x > A[i]) break;
      Tp--;
    }
    if (Tp != 1 || Stk[Tp] > A[i]) Stk[++Tp] = A[i];
  }
  if (Tp == 1) puts("YES");
  else puts("NO");
}

int main() {
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    init();
    solve();
  }
  return 0;
}