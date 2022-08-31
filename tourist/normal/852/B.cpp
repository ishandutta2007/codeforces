/**
 *    author:  tourist
 *    created: 03.09.2017 13:02:50       
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

const int N = 105;

struct matrix {
  int a[N][N];
};

int m;

matrix multiply(matrix a, matrix b) {
  matrix c;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      c.a[i][j] = 0;
      for (int k = 0; k < m; k++) {
        add(c.a[i][j], mul(a.a[i][k], b.a[k][j]));
      }
    }
  }
  return c;
}

matrix power(matrix a, int b) {
  matrix c;
  for (int i = 0; i < m; i++) {
    c.a[i][i] = 1;
  }
  while (b > 0) {
    if (b & 1) {
      c = multiply(c, a);
    }
    a = multiply(a, a);
    b >>= 1;
  }
  return c;
}

int last[1234567];
int not_last[1234567];

int main() {
  int n, l;
  scanf("%d %d %d", &n, &l, &m);
  matrix a, b;
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    a.a[0][foo % m]++;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", not_last + i);
    b.a[0][not_last[i] % m]++;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", last + i);
  }
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < m; j++) {
      a.a[i][(i + j) % m] = a.a[0][j];
      b.a[i][(i + j) % m] = b.a[0][j];
    }
  }
  matrix d = multiply(power(b, l - 2), a);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int z = (last[i] + not_last[i]) % m;
    add(ans, d.a[0][(m - z) % m]);
  }
  printf("%d\n", ans);
  return 0;
}