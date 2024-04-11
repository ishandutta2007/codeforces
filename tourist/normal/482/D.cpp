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

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long)a * b % md;
}

const int N = 200010;

vector <int> g[N];
int f[N][2];
int aux[7][7], new_aux[7][7];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 2; i <= n; i++) {
    int foo;
    scanf("%d", &foo);
    g[foo].push_back(i);
  }
  for (int i = n; i >= 1; i--) {
    for (int tot = 0; tot < 2; tot++) {
      for (int all = 0; all < 4; all++) {
        aux[tot][all] = 0;
      }
    }
    aux[0][0] = 1;
    int sz = g[i].size();
    for (int j = 0; j < sz; j++) {
      int u = g[i][j];
      for (int tot = 0; tot < 2; tot++) {
        for (int all = 0; all < 4; all++) {
          new_aux[tot][all] = aux[tot][all];
        }
      }
      for (int tot = 0; tot < 2; tot++) {
        for (int all = 0; all < 4; all++) {
          for (int cur = 0; cur < 2; cur++) {
            add(new_aux[tot ^ cur][all | (1 << cur)], mul(aux[tot][all], f[u][cur]));
          }
        }
      }
      for (int tot = 0; tot < 2; tot++) {
        for (int all = 0; all < 4; all++) {
          aux[tot][all] = new_aux[tot][all];
        }
      }
    }
    f[i][0] = f[i][1] = 0;
    for (int tot = 0; tot < 2; tot++) {
      for (int all = 0; all < 4; all++) {
        add(f[i][tot ^ 1], aux[tot][all]);
        if (all == 3 || (all == 2 && tot == 0)) {
          add(f[i][tot ^ 1], aux[tot][all]);
        }
      }
    }
  }
  printf("%d\n", (f[1][0] + f[1][1]) % md);
  return 0;
}