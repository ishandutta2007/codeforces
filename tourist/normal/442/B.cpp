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

double p[12345];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p, p + n);
  double ans = 0.0;
  for (int from = 0; from < n; from++) {
    double f = 0.0, prod = 1.0;
    for (int i = from; i < n; i++) {
      f = f * (1 - p[i]) + prod * p[i];
      prod *= (1 - p[i]);
    }
    if (f > ans) {
      ans = f;
    }
  }
  printf("%.17lf\n", ans);
  return 0;
}