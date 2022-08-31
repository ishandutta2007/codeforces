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

int md;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long)a * b % md;
}

int pw(int a, int b) {
  int x = 1;
  while (b > 0) {
    if (b & 1) {
      x = mul(x, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}

int gcd(int a, int b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

int phi;

void init(int n) {
  md = n;
  phi = 0;
  for (int i = 1; i <= n; i++) {
    if (gcd(n, i) == 1) {
      phi++;
    }
  }
}

int ans[1234567];

int main() {
  int n, m, dx, dy;
  scanf("%d %d %d %d", &n, &m, &dx, &dy);
  init(n);
  for (int i = 0; i < n; i++) {
    ans[i] = 0;
  }
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    int k = mul(x, pw(dx, phi - 1));
    add(y, n - mul(k, dy));
    ans[y]++;
  }
  int best = 0;
  for (int i = 1; i < n; i++) {
    if (ans[i] > ans[best]) {
      best = i;
    }
  }
  printf("%d %d\n", 0, best);
  return 0;
}