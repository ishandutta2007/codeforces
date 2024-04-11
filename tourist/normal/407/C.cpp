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

const int md = 1000000007;
const int N = 100010;
const int K = 100;
const int K10 = K + 10;

int inv[K10];
int ans[K10][N];

void init() {
  for (int k = 0; k <= K; k++) {
    inv[k] = 1;
    int step = 1 << 30;
    while (step > 0) {
      inv[k] = (long long)inv[k] * inv[k] % md;
      if (step & (md - 2)) inv[k] = (long long)inv[k] * k % md;
      step >>= 1;
    }
  }
}

inline void add(int &x, int y) {
  x += y;
  if (x >= md) x -= md;
}

int nouse[N];

int main() {
  init();
  int n, tt;
  scanf("%d %d", &n, &tt);
  for (int i = 1; i <= n; i++) scanf("%d", nouse + i);
  for (int i = 0; i <= K; i++)
    for (int j = 0; j <= n + 1; j++) ans[i][j] = 0;
  while (tt--) {
    int ll, rr, k;
    scanf("%d %d %d", &ll, &rr, &k);
    add(ans[K - k][ll], 1);
    add(ans[K - k][rr + 1], md - 1);
    int u = 1;
    for (int i = K - k + 1; i <= K; i++) {
      int t = i - (K - k);
      u = (long long)u * (t + rr - ll) % md;
      u = (long long)u * inv[t] % md;
      add(ans[i][rr + 1], md - u);
    }
  }
  for (int j = 0; j <= K; j++)
    for (int i = 1; i <= n; i++) {
      add(ans[j][i], ans[j][i - 1]);
      if (j > 0) {
        add(ans[j][i], ans[j - 1][i]);
      }
    }
  for (int i = 1; i <= n; i++) {
    add(nouse[i], ans[K][i]);
    printf("%d", nouse[i] % md);
    if (i < n) printf(" ");
  }
  printf("\n");
  return 0;
}