#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

const int md = 1000000007;

int f[555][555], c[555][555];
int fact[555];

int main() {
  int n;
  scanf("%d", &n);
  int k1 = 0, k2 = 0;
  for (int i=0;i<n;i++) {
    int foo;
    scanf("%d", &foo);
    if (foo == 1) k1++;
    else k2++;
  }
  memset(c, 0, sizeof(c));
  for (int i=0;i<=n;i++) c[i][0] = 1;
  for (int i=1;i<=n;i++)
    for (int j=1;j<=i;j++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % md;
  fact[0] = 1;
  for (int i=1;i<=n;i++) fact[i] = (long long)fact[i-1] * i % md;
  for (int i=0;i<=k1;i++)
    for (int j=0;j<=k2;j++) {
      if (i == 0) f[i][j] = fact[j]; else {
        f[i][j] = 0;
        for (int x=0;x<=i-1 && x<=1;x++)
          for (int y=0;y<=j;y++) {
            int ft = (long long)f[i-1-x][j-y] * c[j][y] % md;
            if (x == 1) ft = (long long)ft * (i-1) % md;
            ft = (long long)ft * fact[x+y] % md;
            f[i][j] += ft;
            if (f[i][j] >= md) f[i][j] -= md;
          }
      }
    }
  printf("%d\n", f[k1][k2]);
  return 0;
}