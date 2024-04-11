#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline int mul(int a, int b) {
  return (long long)a * b % md;
}

inline int pw(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  return pw(a, md - 2);
}

const int N = 1000010;

int fact[N], invfact[N];

int main() {
  int n;
  scanf("%d", &n);
  fact[0] = invfact[0] = 1;
  for (int i = 1; i <= n + 1; i++) {
    fact[i] = mul(fact[i - 1], i);
    invfact[i] = mul(invfact[i - 1], inv(i));
  }
  int ans = 0;
  for (int x = 1; x <= n + 1; x++) {
    int c = mul(fact[n + 1], mul(invfact[x], invfact[n + 1 - x]));
    add(ans, mul(c, c));
  }
  printf("%d\n", ans);
  return 0;
}