/**
 *    author:  tourist
 *    created: 03.09.2017 13:26:32       
**/
#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

inline int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int x) {
  return power(x, md - 2);
}

int deg[1234567];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    foo--; bar--;
    deg[foo]++;
    deg[bar]++;
  }
  if (n == 1) {
    printf("%d\n", 1);
    return 0;
  }
  int leaves = 0;
  for (int i = 0; i < n; i++) {
    leaves += (deg[i] == 1);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    add(ans, power(2, n - (leaves - (deg[i] == 1))));
  }
  printf("%d\n", ans);
  return 0;
}