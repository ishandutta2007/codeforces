#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 30010;
const int NN = (N >> 5) + 10;

unsigned int one = 1;
unsigned int a[N][NN];

int pr[N], ne[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int nn = (n >> 5) + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < nn; j++) a[i][j] = 0;
  while (m--) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    a[foo][bar >> 5] |= (one << (bar & 31));
  }
  ne[0] = 1; pr[1] = 0;
  ne[1] = n + 1; pr[n + 1] = 1;
  for (int i = 2; i <= n; i++) {
    int t = 0;
    while (true) {
      if (a[t][i >> 5] & (one << (i & 31))) {
        t = ne[t];
        continue;
      }
      if (a[i][ne[t] >> 5] & (one << (ne[t] & 31))) {
        t = ne[t];
        continue;
      }
      pr[i] = t;
      ne[i] = ne[t];
      pr[ne[i]] = i;
      ne[pr[i]] = i;
      break;
    }
  }
  int t = ne[0];
  printf("%d", t);
  while (ne[t] <= n) {
    t = ne[t];
    printf(" %d", t);
  }
  printf("\n");
  return 0;
}