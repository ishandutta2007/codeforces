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

const int MaxN = 100000;

int Te, N;
long long A[MaxN + 5];

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
}

inline bool check(int mid) {
  long long maxadd = (1LL << mid) - 1;
  int mx = -1000000001;
  for (int i = 1; i <= N; ++i) {
    if (A[i] < mx) {
      if (A[i] + maxadd < mx) return false;
    } else mx = A[i];
  }
  return true;
}

void solve() {
  int lbound = 0, rbound = 40, ans = -1;
  while (lbound <= rbound) {
    int mid = (lbound + rbound) >> 1;
    if (check(mid) == true) {
      ans = mid;
      rbound = mid - 1;
    } else lbound = mid + 1;
  }
  printf("%d\n", ans);
}

int main() {
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    init();
    solve();
  }
  return 0;
}