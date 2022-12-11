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

const int MaxN = 4000;

int N;
int A[MaxN + 5];
std::vector<int> Vec;

void init() {
  scanf("%d", &N);
  N <<= 1;
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
}

void solve() {
  Vec.clear();
  for (int l = 1, r = 0; l <= N; l = r + 1) {
    while (r < N && A[r + 1] <= A[l]) r++;
    Vec.push_back(r - l + 1);
  }
  std::bitset<MaxN + 5> bt;
  bt.reset();
  bt[0] = 1;
  for (int i : Vec) bt |= (bt << i);
  if (bt[N / 2] == true) puts("YES");
  else puts("NO");
}

int main() {
  int Tests = 1;
  scanf("%d", &Tests);
  for (int t = 1; t <= Tests; ++t) {
    init();
    solve();
  }
  return 0;
}