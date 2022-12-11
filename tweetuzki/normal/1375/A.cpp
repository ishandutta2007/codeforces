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

const int MaxN = 99;

int Te, N;
int A[MaxN + 5];

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
}

void solve() {
  for (int i = 1; i <= N; ++i) {
    if (i & 1) A[i] = abs(A[i]);
    else A[i] = -abs(A[i]);
  }
  for (int i = 1; i <= N; ++i)
    printf("%d%c", A[i], " \n"[i == N]);
}

int main() {
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    init();
    solve();
  }
  return 0;
}