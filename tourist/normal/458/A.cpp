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

void wr(char c) {
  printf("%c\n", c);
  exit(0);
}

const int N = 1000010;

int a[N];
char foo[N];

int main() {
  for (int i = 0; i < N; i++) {
    a[i] = 0;
  }
  for (int r = 1; r >= -1; r -= 2) {
    scanf("%s", foo);
    int n = strlen(foo);
    for (int i = 0; i < n; i++) {
      if (foo[i] == '1') {
        a[n - i - 1] += r;
      }
    }
  }
  for (int i = N - 1; i >= 2; i--) {
    if (a[i] != 0) {
      if (a[i] >= 2) {
        wr('>');
      }
      if (a[i] <= -2) {
        wr('<');
      }
      a[i - 1] += a[i];
      a[i - 2] += a[i];
      a[i] = 0;
    }
  }
  long double q = 1.6180339887498948482045868343656;
  long double x = a[1] * q + a[0];
  if (x > 1e-9) {
    wr('>');
  }
  if (x < -1e-9) {
    wr('<');
  }
  wr('=');
  return 0;
}