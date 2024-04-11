#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int co = 1000010;
const int N = 6*co+10;

long long yN[N], yd[N];
long long bn[42], bd[42];
int pred[N];
int last[2*co+10];
int x[100010], y[100010];
int m;

void add(int xa, int ya, int xb, int yb) {
  if (xa == xb) return;
  if (xa > xb) {
    int tmp = xa; xa = xb; xb = tmp;
    tmp = ya; ya = yb; yb = tmp;
  }
  for (int xx=xa;xx<=xb;xx++) {
    m++;
    yN[m] = (long long)ya*(xb-xa) + (long long)(yb-ya)*(xx-xa);
    yd[m] = xb-xa;
    pred[m] = last[xx+co];
    last[xx+co] = m;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0;i<n;i++) scanf("%d %d", x+i, y+i);
  double ans = 0.0;
  for (int r=0;r<2;r++) {
    x[n] = x[0]; y[n] = y[0];
    m = 0;
    for (int i=0;i<=2*co;i++) last[i] = 0;
    for (int i=0;i<n;i++) add(x[i], y[i], x[i+1], y[i+1]);
    double sum = 0, sq = 0, cnt = 0;
    for (int xx=-co;xx<=co;xx++) {
      int k = 0;
      int j = last[xx+co];
      while (j > 0) {
        bn[k] = yN[j];
        bd[k] = yd[j];
        k++;
        j = pred[j];
      }
      if (k == 0) continue;
      for (int i=0;i<k;i++)
        for (int j=i+1;j<k;j++)
          if (bn[i]*bd[j] > bn[j]*bd[i]) {
            long long tmp = bn[i]; bn[i] = bn[j]; bn[j] = tmp;
            tmp = bd[i]; bd[i] = bd[j]; bd[j] = tmp;
          }
      long long up = bn[k-1]/bd[k-1];
      while (up*bd[k-1] > bn[k-1]) up--;
      while ((up+1)*bd[k-1] <= bn[k-1]) up++;
      long long down = bn[0]/bd[0];
      while (down*bd[0] < bn[0]) down++;
      while ((down-1)*bd[0] >= bn[0]) down--;
      cnt += 1.0*(up-down+1);
      sum += 1.0*xx*(up-down+1);
      sq += 1.0*xx*xx*(up-down+1);
    }
    ans += (sq-sum*sum/cnt)/(cnt-1);
    for (int i=0;i<n;i++) {
      int tmp = x[i];
      x[i] = y[i];
      y[i] = tmp;
    }
  }
  printf("%.17lf\n", ans);
  return 0;
}