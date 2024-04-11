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

int n, i, j, k;
int a[111][111];

int main() {
  scanf("%d",&n);
  memset(a,0,sizeof(a));
  int m = 0;
  while (n > 0)
    for (i=100;i>=3;i--)
      if (i*(i-1)*(i-2)/6 <= n) {
        m += i;
        for (j=m-i;j<m;j++)
          for (k=m-i;k<m;k++) a[j][k] = (j != k);
        n -= i*(i-1)*(i-2)/6;
        for (int z=i;z>=2;z--)
          if (z*(z-1)/2 <= n) {
            m++;
            for (j=m-z-1;j<m-1;j++) a[j][m-1] = a[m-1][j] = 1;
            n -= z*(z-1)/2;
            for (int y=z+1;y>=2;y--)
              if (y*(y-1)/2 <= n) {
                m++;
                for (j=m-y-1;j<m-1;j++) a[j][m-1] = a[m-1][j] = 1;
                n -= y*(y-1)/2;
                break;
              }
            break;
          }
        break;
      }
  printf("%d\n",m);
  for (i=0;i<m;i++) {
    for (j=0;j<m;j++) printf("%d",a[i][j]);
    printf("\n");
  }
  return 0;
}