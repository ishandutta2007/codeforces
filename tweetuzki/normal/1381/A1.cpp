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

int N;
int A[MaxN + 5], B[MaxN + 5];

inline int getDigit() {
  char c;
  do c = getchar();
  while (c < '0' || c > '9');
  return c - '0';
}

int main() {
  int Tests = 1;
  scanf("%d", &Tests);
  while (Tests--) {
    std::vector<int> vec;
    vec.clear();
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) A[i] = getDigit();
    for (int i = 1; i <= N; ++i) B[i] = getDigit();
    for (int i = N; i >= 1; --i) {
      if (A[1] == B[i]) {
        vec.push_back(1);
        A[1] ^= 1;
      }
      vec.push_back(i);
      for (int j = 1; j <= i; ++j) A[j] ^= 1;
      std::reverse(A + 1, A + 1 + i);
    }
    printf("%d", (int) vec.size());
    for (int v : vec) printf(" %d", v);
    puts("");
  }
  return 0;
}