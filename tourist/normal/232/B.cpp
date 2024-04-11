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

int pw(int a, long long b) {
  long long step = 1LL << 61;
  int x = 1;
  while (step) {
    x = (long long)x*x % md;
    if (step & b) x = (long long)x*a % md;
    step >>= 1;
  }
  return x;
}

int n, k, i, j;
long long m;
int d[111], e[111];
int c[111][111];
int f[111][11111];

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  cin >> n >> m >> k;
  memset(c,0,sizeof(c));
  for (i=0;i<=n;i++) c[i][0] = 1;
  for (i=1;i<=n;i++)
    for (j=1;j<=i;j++) c[i][j] = (c[i-1][j-1]+c[i-1][j]) % md;
  for (j=0;j<=n;j++) {
    d[j] = pw(c[n][j], m/n);
    e[j] = pw(c[n][j], m/n+1);
  }
  int mm = m % n;
  memset(f,0,sizeof(f));
  f[0][0] = 1;
  for (i=0;i<n;i++)
    for (j=0;j<=k;j++)
      if (f[i][j]) {
        for (int q=0;q<=n;q++) {
          int ft;
          if (i < mm) ft = e[q];
          else ft = d[q];
          f[i+1][j+q] = (f[i+1][j+q]+(long long)ft*f[i][j]) % md;
        }
      }
  cout << f[n][k] << endl;
  return 0;
}