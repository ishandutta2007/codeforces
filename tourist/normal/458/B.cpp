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

int a[N], b[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  long long sum_a = 0, sum_b = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    sum_a += a[i];
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", b + i);
    sum_b += b[i];
  }
  sort(a, a + n);
  sort(b, b + m);
  long long ans_a = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= sum_b || i == n - 1) {
      ans_a += sum_b;
    } else {
      ans_a += a[i];
    }
  }
  long long ans_b = 0;
  for (int i = 0; i < m; i++) {
    if (b[i] >= sum_a || i == m - 1) {
      ans_b += sum_a;
    } else {
      ans_b += b[i];
    }
  }
  cout << (ans_a < ans_b ? ans_a : ans_b) << endl;
  return 0;
}