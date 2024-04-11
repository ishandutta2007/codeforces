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

const long long inf = (long long)1e18;

int x[8][3];
long long vx[8][3];
long long d[8];

void dfs(int v) {
  if (v == 8) {
    long long side = -1;
    for (int i = 0; i < 8; i++) {
      long long mn = inf;
      int id1 = -1;
      int id2 = -1;
      int id3 = -1;
      int id4 = -1;
      for (int j = 0; j < 8; j++) {
        if (i == j) {
          continue;
        }
        d[j] = 0;
        for (int q = 0; q < 3; q++) {
          vx[j][q] = x[j][q] - x[i][q];
          d[j] += vx[j][q] * vx[j][q];
        }
        if (d[j] < mn) {
          mn = d[j];
          id1 = -1;
          id2 = -1;
          id3 = -1;
          id4 = -1;
        }
        if (d[j] == mn) {
          id4 = id3;
          id3 = id2;
          id2 = id1;
          id1 = j;
        }
      }
      if (id4 != -1 || id3 == -1) {
        return;
      }
      if (mn == 0) {
        return;
      }
      if (side == -1) {
        side = mn;
      }
      if (side != mn) {
        return;
      }
      if (vx[id1][0] * vx[id2][0] + vx[id1][1] * vx[id2][1] + vx[id1][2] * vx[id2][2] != 0) {
        return;
      }
      if (vx[id1][0] * vx[id3][0] + vx[id1][1] * vx[id3][1] + vx[id1][2] * vx[id3][2] != 0) {
        return;
      }
      if (vx[id3][0] * vx[id2][0] + vx[id3][1] * vx[id2][1] + vx[id3][2] * vx[id2][2] != 0) {
        return;
      }
    }
    puts("YES");
    for (int i = 0; i < 8; i++) {
      printf("%d %d %d\n", x[i][0], x[i][1], x[i][2]);
    }
    exit(0);
    return;
  }
  sort(x[v], x[v] + 3);
  do {
    dfs(v + 1);
  } while (next_permutation(x[v], x[v] + 3));
}

int main() {
  for (int i = 0; i < 8; i++) {
    scanf("%d %d %d", x[i] + 0, x[i] + 1, x[i] + 2);
  }
  dfs(1);
  puts("NO");
  return 0;
}