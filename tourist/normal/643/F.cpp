#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;

const uint phi = ((uint) 1) << ((uint) 31);

inline uint power(uint a, uint b) {
  uint res = 1;
  while (b > 0) {
    if (b & 1) {
      res *= a;
    }
    a *= a;
    b >>= 1;
  }
  return res;
}

inline uint calc_C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  if (k > n - k) {
    k = n - k;
  }
  uint x = 1;
  int p2 = 0;
  for (int i = n; i > n - k; i--) {
    int tmp = i;
    while (!(tmp & 1)) {
      p2++;
      tmp >>= 1;
    }
    x *= tmp;
  }
  uint y = 1;
  for (int i = k; i > 0; i--) {
    int tmp = i;
    while (!(tmp & 1)) {
      p2--;
      tmp >>= 1;
    }
    y *= tmp;
  }
  x *= power(y, phi - 1);
  while (p2 > 0) {
    x *= 2;
    p2--;
  }
  return x;
}

const int P = 144;

uint C[P][P];
uint f[P][P];
uint smallC[P];

int main() {
  int n, p, q;
  scanf("%d %d %d", &n, &p, &q);
  p = min(p, n - 1);
  for (int d = 0; d <= p; d++) {
    for (int t = 0; t <= p - d; t++) {
      C[d][t] = calc_C(n - d, t);
    }
  }
  for (int d = 0; d <= p; d++) {
    f[0][d] = 1;
  }
  for (int i = 1; i <= p; i++) {
    for (int d = 0; d <= p; d++) {
      f[i][d] = 0;
      for (int t = 1; t <= p - d; t++) {
        f[i][d] += C[d][t] * f[i - 1][d + t];
      }
    }
  }
  for (int j = 0; j <= p; j++) {
    smallC[j] = (j == 0 ? 1 : 0);
  }
  uint res = 0;
  for (int i = 1; i <= q; i++) {
    uint ans = 1;
    for (int j = p; j >= 1; j--) {
      smallC[j] += smallC[j - 1];
      ans += f[j][0] * smallC[j];
    }
    res ^= ((uint) i) * ((uint) ans);
  }
  cout << res << endl;
  return 0;
}