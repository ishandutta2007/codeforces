#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += md;
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
    b >>= 1;
    a = mul(a, a);
  }
  return res;
}

inline int inv(int x) {
  return power(x, md - 2);
}

const int N = 1000010;

int phi[N];
int choose[N];
int cnt[N];

int main() {
  for (int i = 1; i < N; i++) {
    phi[i] = i;
  }
  for (int i = 1; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      phi[j] -= phi[i];
    }
  }
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);
  for (int i = 0; i < k; i++) {
    choose[i] = 0;
  }
  choose[k] = 1;
  for (int i = k + 1; i <= n + q; i++) {
    choose[i] = mul(choose[i - 1], mul(i, inv(i - k)));
  }
  for (int i = 1; i < N; i++) {
    cnt[i] = 0;
  }
  int ans = 0;
  for (int id = 0; id < n + q; id++) {
    int x;
    scanf("%d", &x);
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        for (int rot = 0; rot < 2; rot++) {
          int tmp = md - choose[cnt[i]];
          cnt[i]++;
          add(ans, mul(phi[i], tmp + choose[cnt[i]]));
          if (i * i == x) {
            break;
          }
          i = x / i;
        }
      }
    }
    if (id >= n) {
      printf("%d\n", ans);
    }
  }
  return 0;
}