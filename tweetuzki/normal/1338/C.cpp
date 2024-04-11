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

int Te;
long long N;

void solve() {
  long long p = (N - 1) / 3 + 1, q = N % 3;
  if (q == 0) q = 3;
  if (p == 1) {
    printf("%lld\n", q);
    return;
  }
  long long num = 0;
  for (int i = 1;; i += 2) {
    long long delta = (1LL << (i - 1));
    if (num + delta >= p) {
      long long x = p - num - 1;
      long long a = (1LL << (i - 1)) + x;
      // printf("x = %lld, a = %lld\n", x, a);
      long long b = (1LL << i);
      for (int j = 1; j < i; j += 2) {
        long long round = (1LL << (j + 1));
        if (x % round >= round / 2) b |= (1LL << (j - 1));
        if (x % round >= round / 4 && x % round < round / 4 * 3) b |= (1LL << j);
      }
      long long c = a ^ b;
      if (q == 1) printf("%lld\n", a);
      else if (q == 2) printf("%lld\n", b);
      else printf("%lld\n", c);
      break;
    }
    num += (1LL << (i - 1));
  }
}

int main() {
#ifdef Tweetuzki
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    scanf("%lld", &N);
    solve();
  }
  return 0;
}