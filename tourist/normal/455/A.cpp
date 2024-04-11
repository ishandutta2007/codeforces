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

const int N = 1000010;

int cnt[N];
long long f[N];

int main() {
  int n;
  scanf("%d", &n);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    cnt[foo]++;
  }
  f[0] = 0;
  for (int i = 1; i < N; i++) {
    f[i] = (long long)i * cnt[i];
    if (i - 2 >= 0) {
      f[i] += f[i - 2];
    }
    if (f[i - 1] > f[i]) {
      f[i] = f[i - 1];
    }
  }
  cout << f[N - 1] << endl;
  return 0;
}