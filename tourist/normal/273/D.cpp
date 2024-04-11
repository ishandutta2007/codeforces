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

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

int f[155][155][2][2], oldf[155][155][2][2], trueoldf[155][155][2][2];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  memset(f, 0, sizeof(f));
  for (int a=1;a<=m;a++)
    for (int b=a;b<=m;b++) f[a][b][1][1] = 1;
  int ans = 0;
  for (int i=1;i<=n;i++) {
    long long cnt = 0;
    for (int a=1;a<=m;a++)
      for (int b=a;b<=m;b++)
        for (int ka=0;ka<=1;ka++)
          for (int kb=0;kb<=1;kb++) cnt += f[a][b][ka][kb];
    ans = (ans+cnt*(n-i+1)) % md;

    for (int a=1;a<=m;a++)
      for (int b=a+1;b<=m;b++)
        for (int kb=0;kb<=1;kb++) {
          add(f[a+1][b][0][kb], f[a][b][0][kb]);
          add(f[a+1][b][0][kb], f[a][b][1][kb]);
        }
    for (int a=1;a<=m;a++)
      for (int b=m;b>=a+1;b--)
        for (int ka=0;ka<=1;ka++) {
          add(f[a][b-1][ka][0], f[a][b][ka][0]);
          add(f[a][b-1][ka][0], f[a][b][ka][1]);
        }
    for (int a=m;a>=2;a--)
      for (int b=a;b<=m;b++)
        for (int kb=0;kb<=1;kb++) {
          add(f[a-1][b][1][kb], f[a][b][1][kb]);
        }
    for (int a=m;a>=1;a--)
      for (int b=a;b<=m-1;b++)
        for (int ka=0;ka<=1;ka++) {
          add(f[a][b+1][ka][1], f[a][b][ka][1]);
        }
  }
  printf("%d\n", ans);
  return 0;
}