#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 4000010;

int a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int foo;
    scanf("%d %d", &foo, a + i);
  }
  sort(a, a + m);
  reverse(a, a + m);
  int res = 0, cur = 0;
  for (int cnt = 1; cnt <= 10000 && cnt <= m; cnt++) {
    cur += a[cnt - 1];
    int need = cnt * (cnt - 1) / 2;
    if (cnt % 2 == 1) need += 1;
    else need += cnt / 2;
    if (need <= n) {
      if (cur > res) res = cur;
    }
  }
  printf("%d\n", res);
  return 0;
}