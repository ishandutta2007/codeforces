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
#include <memory.h>
#include <cassert>

using namespace std;

const int inf = (int)1e9;
const int N = 30010;
const int K = 210;

int f[N][K][2][3][3];
int a[N];

void check(int &a, int b) {
  if (b > a) a = b;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int in = 0; in < 2; in++) {
        for (int c1 = 0; c1 < 3; c1++) {
          for (int c2 = 0; c2 < 3; c2++) {
            f[i][j][in][c1][c2] = -inf;
          }
        }
      }
    }
  }
  f[0][0][0][1][1] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int in = 1; in >= 0; in--) {
        for (int c1 = 0; c1 < 3; c1++) {
          for (int c2 = 0; c2 < 3; c2++) {
            int ft = f[i][j][in][c1][c2];
            if (ft == -inf) {
              continue;
            }
            if (!in) {
              check(f[i + 1][j][0][c1][c2], ft);
              if (j < k) {
                for (int nc2 = 0; nc2 < 3; nc2++) {
                  if ((nc2 == 1) != (j + 1 == k)) {
                    continue;
                  }
                  check(f[i + 1][j + 1][1][c1][nc2], ft + a[i] * ((c1 - 1) + (nc2 - 1)));
                }
              }
            } else {
              check(f[i + 1][j][1][c1][c2], ft + a[i] * ((c1 - 1) + (c2 - 1)));
              check(f[i][j][0][2 - c2][1], ft);
            }
          }
        }
      }
    }
  }
  printf("%d\n", max(f[n][k][0][1][1], max(f[n][k][1][2][1], f[n][k][1][0][1])));
  return 0;
}