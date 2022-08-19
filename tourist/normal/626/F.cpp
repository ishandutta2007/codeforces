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

const int N = 2010;

int a[N];
int f[N][N], nf[N][N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  for (int z = 0; z <= k; z++) {
    f[0][z] = (z == 0);
  }
  a[n] = a[n - 1];
  for (int id = 0; id < n; id++) {
    for (int j = 0; j <= id + 1; j++) {
      for (int z = 0; z <= k; z++) {
        nf[j][z] = 0;
      }
    }
    for (int j = 0; j <= id; j++) {
      for (int z = 0; z <= k; z++) {
        int ft = f[j][z];
        if (ft == 0) {
          continue;
        }
        {
          int nz = z + (a[id + 1] - a[id]) * (j + 1);
          if (nz <= k) {
            add(nf[j + 1][nz], ft);
          }
        }
        {
          int nz = z + (a[id + 1] - a[id]) * j;
          if (nz <= k) {
            add(nf[j][nz], mul(ft, j + 1));
          }
        }
        if (j > 0) {
          int nz = z + (a[id + 1] - a[id]) * (j - 1);
          if (nz <= k) {
            add(nf[j - 1][nz], mul(ft, j));
          }
        }
      }
    }
    for (int j = 0; j <= id + 1; j++) {
      for (int z = 0; z <= k; z++) {
        f[j][z] = nf[j][z];
      }
    }
  }
  int ans = 0;
  for (int z = 0; z <= k; z++) {
    add(ans, f[0][z]);
  }
  printf("%d\n", ans);
  return 0;
}