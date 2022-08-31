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

const int N = 200010;
const int BLOCK = 350;

vector <int> g[N];
int pv[N];
int value[N];
long long coeff[N];
bool imp[N];
int down[N];
long long change[N], total[N];
int up[N];
long long sz[N];
int depth[N];
long long ans;

void dfs(int v) {
  coeff[v] = 0;
  sz[v] = 1;
  down[v] = -1;
  int only = -1;
  for (int j = 0; j < (int)g[v].size(); j++) {
    int u = g[v][j];
    depth[u] = depth[v] + 1;
    dfs(u);
    sz[v] += sz[u];
    coeff[v] -= sz[u] * sz[u];
    if (down[u] != -1) {
      if (down[v] == -1) {
        down[v] = down[u];
        only = u;
      } else {
        imp[v] = true;
      }
    }
  }
  if (imp[v]) {
    down[v] = v;
  }
  coeff[v] += sz[v] * sz[v];
  ans += value[v] * coeff[v];
  if (!imp[v] && only != -1) {
    change[v] = (sz[v] + 1) * (sz[v] + 1) - sz[v] * sz[v];
    change[v] -= (sz[only] + 1) * (sz[only] + 1) - sz[only] * sz[only];
    change[v] *= value[v];
  } else {
    change[v] = 0;
  }
}

char op[N];
int arg1[N], arg2[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  pv[1] = -1;
  for (int i = 2; i <= n; i++) {
    scanf("%d", pv + i);
    g[pv[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", value + i);
  }
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    char ch = getchar();
    while (ch != 'P' && ch != 'V') {
      ch = getchar();
    }
    op[qq] = ch;
    scanf("%d %d", arg1 + qq, arg2 + qq);
  }
  int next_q = 1;
  while (next_q <= tt) {
    int last_q = next_q + BLOCK - 1;
    if (last_q > tt) {
      last_q = tt;
    }
    for (int i = 1; i <= n; i++) {
      imp[i] = false;
    }
    for (int qq = next_q; qq <= last_q; qq++) {
      if (op[qq] == 'P') {
        imp[arg1[qq]] = true;
        imp[arg2[qq]] = true;
      } else {
        imp[arg1[qq]] = true;
      }
    }
    ans = 0;
    depth[1] = 0;
    dfs(1);
    for (int i = 1; i <= n; i++) {
      up[i] = i;
      total[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      if (down[i] != -1) {
        total[down[i]] += change[i];
        if (depth[i] < depth[up[down[i]]]) {
          up[down[i]] = i;
        }
      }
    }
    if (next_q == 1) {
      printf("%.15lf\n", (double)(1.0 * ans / n / n));
    }
    for (int qq = next_q; qq <= last_q; qq++) {
      if (op[qq] == 'P') {
        int v = arg1[qq];
        int u = arg2[qq];
        int z = u;
        while (z != v && z != -1) {
          z = pv[up[z]];
        }
        if (z == v) {
          swap(u, v);
        }
        {
          int z = v;
          while (z != -1) {
            ans -= total[z] * sz[v];
            int new_z = pv[up[z]];
            if (new_z == -1) {
              break;
            }
            ans -= coeff[new_z] * value[new_z];
            coeff[new_z] -= sz[new_z] * sz[new_z];
            sz[new_z] -= sz[v];
            coeff[new_z] += sz[new_z] * sz[new_z];
            if (up[z] != z) {
              coeff[new_z] += sz[up[z]] * sz[up[z]];
              sz[up[z]] -= sz[v];
              coeff[new_z] -= sz[up[z]] * sz[up[z]];
            } else {
              if (z != v) {
                coeff[new_z] += (sz[up[z]] + sz[v]) * (sz[up[z]] + sz[v]);
                coeff[new_z] -= sz[up[z]] * sz[up[z]];
              } else {
                coeff[new_z] += sz[up[z]] * sz[up[z]];
              }
            }
            ans += coeff[new_z] * value[new_z];
            z = new_z;
          }
        }
        {
          ans -= coeff[u] * value[u];
          coeff[u] -= sz[u] * sz[u];
          sz[u] += sz[v];
          coeff[u] += sz[u] * sz[u];
          coeff[u] -= sz[v] * sz[v];
          ans += coeff[u] * value[u];
        }
        {
          int z = u;
          while (z != -1) {
            ans += total[z] * sz[v];
            int new_z = pv[up[z]];
            if (new_z == -1) {
              break;
            }
            ans -= coeff[new_z] * value[new_z];
            coeff[new_z] -= sz[new_z] * sz[new_z];
            sz[new_z] += sz[v];
            coeff[new_z] += sz[new_z] * sz[new_z];
            if (up[z] != z) {
              coeff[new_z] += sz[up[z]] * sz[up[z]];
              sz[up[z]] += sz[v];
              coeff[new_z] -= sz[up[z]] * sz[up[z]];
            } else {
              coeff[new_z] += (sz[up[z]] - sz[v]) * (sz[up[z]] - sz[v]);
              coeff[new_z] -= sz[up[z]] * sz[up[z]];
            }
            ans += coeff[new_z] * value[new_z];
            z = new_z;
          }
        }
        pv[v] = u;
        total[v] = 0;
        up[v] = v;
      } else {
        int v = arg1[qq];
        ans += (arg2[qq] - value[v]) * coeff[v];
        value[v] = arg2[qq];
      }
      printf("%.15lf\n", (double)(1.0 * ans / n / n));
    }
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
    for (int i = 2; i <= n; i++) {
      g[pv[i]].push_back(i);
    }
    next_q = last_q + 1;
  }
  return 0;
}