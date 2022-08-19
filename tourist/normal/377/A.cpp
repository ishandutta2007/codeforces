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

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

const int N = 1234;

char a[N][N];
bool was[N][N];
int x[N * N], y[N * N];

int main() {
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  for (int i = 0; i < n; i++) scanf("%s", a[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) was[i][j] = false;
  bool found = false;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!found && a[i][j] == '.') {
        int b = 1, e = 1;
        x[1] = i;
        y[1] = j;
        was[i][j] = true;
        while (b <= e) {
          for (int q = 0; q < 4; q++) {
            int xk = x[b] + dx[q];
            int yk = y[b] + dy[q];
            if (xk >= 0 && yk >= 0 && xk < n && yk < m)
              if (a[xk][yk] == '.' && !was[xk][yk]) {
                e++;
                x[e] = xk;
                y[e] = yk;
                was[xk][yk] = true;
              }
          }
          b++;
        }
        for (int id = e - s + 1; id <= e; id++) a[x[id]][y[id]] = 'X';
        found = true;
      }
  for (int i = 0; i < n; i++) printf("%s\n", a[i]);
  return 0;
}