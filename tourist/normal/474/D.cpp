#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

const int md = 1000000007;
const int N = 1234567;

int f[N], s[N];

int main() {
  int tt, k;
  scanf("%d %d", &tt, &k);
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = f[i - 1];
    if (i >= k) {
      f[i] += f[i - k];
      if (f[i] >= md) {
        f[i] -= md;
      }
    }
  }
  s[0] = 0;
  for (int i = 1; i < N; i++) {
    s[i] = s[i - 1] + f[i];
    if (s[i] >= md) {
      s[i] -= md;
    }
  }
  while (tt--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (s[b] - s[a - 1] + md) % md);
  }
  return 0;
}