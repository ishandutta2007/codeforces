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
    int l = 1, r = N;
    int rev = 0;
    for (int i = 1; i <= N; ++i) {
      if (i & 1) {
        if ((A[l] ^ rev) == B[N - i + 1]) {
          vec.push_back(1);
          A[l] ^= 1;
        }
        vec.push_back(N - i + 1);
        rev ^= 1;
        l++;
      } else {
        if ((A[r] ^ rev) == B[N - i + 1]) {
          vec.push_back(1);
          A[r] ^= 1;
        }
        vec.push_back(N - i + 1);
        rev ^= 1;
        r--;
      }
    }
    printf("%d", (int) vec.size());
    for (int v : vec) printf(" %d", v);
    puts("");
  }
  return 0;
}