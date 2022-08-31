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

bool b[424], good[424];
int g[424];
int kd[424], d[424][424];
int mask[424];
int q[424];
int aw[4444444], ax[4444444], ay[4444444], az[4444444];

int main() {
  int cnt;
  scanf("%d", &cnt);
  for (int i=0;i<10;i++) b[i] = false;
  int need = 0;
  for (int i=0;i<cnt;i++) {
    int foo;
    scanf("%d", &foo);
    need |= (1 << foo);
    b[foo] = true;
  }
  if (cnt > 6) printf("%d\n", 0); else {
    int kg = 0;
    for (int i=0;i<256;i++) {
      good[i] = true;
      int x = i;
      mask[i] = 0;
      kd[i] = 0;
      while (x > 0) {
        d[i][kd[i]++] = x % 10;
        if (!b[x % 10]) good[i] = false;
        mask[i] |= (1 << (x % 10));
        x /= 10;
      }
      if (i == 0 && !b[0]) good[i] = false;
      if (i == 0) {
        d[i][kd[i]++] = 0;
        mask[i] |= (1 << 0);
      }
      if (good[i]) g[kg++] = i;
    }
    int ka = 0;
    for (int w=0;w<256;w++)
      if (good[w])
        for (int x=0;x<256;x++)
          if (good[x])
            for (int y=0;y<256;y++)
              if (good[y]) {
                if ((mask[w] | mask[x] | mask[y]) != need) continue;
                for (int z=0;z<256;z++)
                  if (good[z]) {
                    int u = 0;
                    for (int i=kd[w]-1;i>=0;i--) q[u++] = d[w][i];
                    for (int i=kd[x]-1;i>=0;i--) q[u++] = d[x][i];
                    for (int i=kd[y]-1;i>=0;i--) q[u++] = d[y][i];
                    for (int i=kd[z]-1;i>=0;i--) q[u++] = d[z][i];
                    int ok = 1;
                    for (int i=0;i<u-i-1;i++)
                      if (q[i] != q[u-i-1]) {
                        ok = 0;
                        break;
                      }
                    if (ok) {
                      aw[ka] = w;
                      ax[ka] = x;
                      ay[ka] = y;
                      az[ka] = z;
                      ka++;
                    }
                  }
              }
    printf("%d\n", ka);
    for (int i=0;i<ka;i++) printf("%d.%d.%d.%d\n", aw[i], ax[i], ay[i], az[i]);
  }
  return 0;
}