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

const int MaxN = 1000;

int Te, N;
int A[MaxN + 5];

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
}

inline int getmex() {
  static int buc[MaxN + 5];
  memset(buc, 0, sizeof buc);
  for (int i = 1; i <= N; ++i) buc[A[i]]++;
  for (int i = 0; i <= N; ++i)
    if (buc[i] == 0) return i;
  return N + 1;
}

void solve() {
  int fixedNode = 0;
  std::vector<int> vec;
  vec.clear();
  for (int i = 1; i <= N; ++i)
    if (A[i] == i - 1) fixedNode++;
  while (fixedNode < N) {
    int mex = getmex();
    if (mex == N) {
      int doid = 0;
      for (int i = 1; i <= N; ++i)
        if (A[i] != i - 1) doid = i;
      vec.push_back(doid);
      A[doid] = N;
    } else {
      vec.push_back(mex + 1);
      A[mex + 1] = mex;
      fixedNode++;
    }
  }
  printf("%d\n", (int) vec.size());
  for (int i : vec) printf("%d ", i);
  putchar('\n');
}

int main() {
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    init();
    solve();
  }
  return 0;
}