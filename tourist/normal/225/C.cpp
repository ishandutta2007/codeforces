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

int f[1111][3];
int col[1111], to0[1111], to1[1111];
int i, j, q, need, n, m, x, y;

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  scanf("%d %d %d %d",&n,&m,&x,&y);
  for (i=0;i<n;i++)
    for (j=0;j<m;j++) {
      char ch = getchar();
      while (ch != '.' && ch != '#') ch = getchar();
      col[j] += (ch == '#');
    }
  for (j=0;j<m;j++) {
    to0[j] = col[j];
    to1[j] = n-col[j];
  }
  memset(f,50,sizeof(f));
  f[0][0] = 0; f[0][1] = 0;
  for (j=0;j<m;j++)
    for (q=0;q<2;q++)
      if (f[j][q] < 1e7) {
        need = 0;
        for (i=j;i<m;i++) {
          if (q == 0) need += to1[i];
          else need += to0[i];
          if (i-j+1 >= x && i-j+1 <= y)
            if (f[j][q]+need < f[i+1][1-q]) f[i+1][1-q] = f[j][q]+need;
        }
      }
  printf("%d\n",min(f[m][0],f[m][1]));
  return 0;
}