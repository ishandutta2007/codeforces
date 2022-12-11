#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int MaxN = 200000;

int N;
std::vector<int> Gr[MaxN + 5];
int Col[MaxN + 5], Buc[2];

void init() {
  scanf("%d", &N);
  for (int i = 1; i < N; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    Gr[u].push_back(v);
    Gr[v].push_back(u);
  }
}

void dfs(int u, int f) {
  Buc[Col[u]]++;
  for (int v : Gr[u]) {
    if (v == f) continue;
    Col[v] = Col[u] ^ 1;
    dfs(v, u);
  }
}

void solve() {
  dfs(1, 0);
  printf("%d\n", std::min(Buc[0], Buc[1]) - 1);
}

int main() {
  init();
  solve();
  return 0;
}