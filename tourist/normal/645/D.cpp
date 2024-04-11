#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

vector <int> g[N];
int qs[N], qf[N], deg[N], x[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", qs + i, qf + i);
    qs[i]--; qf[i]--;
  }
  int low = 0, high = m + 1;
  while (low < high) {
    int mid = (low + high) >> 1;
    for (int i = 0; i < n; i++) {
      g[i].clear();
      deg[i] = 0;
    }
    for (int j = 0; j < mid; j++) {
      g[qs[j]].push_back(qf[j]);
      deg[qf[j]]++;
    }
    int e = 0;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        x[e++] = i;
      }
    }
    int b = 0;
    while (b < e) {
      int who = x[b];
      for (int j = 0; j < (int) g[who].size(); j++) {
        int u = g[who][j];
        deg[u]--;
        if (deg[u] == 0) {
          x[e++] = u;
        }
      }
      b++;
    }
    bool ok = true;
    for (int i = 0; i < e - 1; i++) {
      int u = x[i];
      int v = x[i + 1];
      bool has = false;
      for (int j = 0; j < (int) g[u].size(); j++) {
        if (g[u][j] == v) {
          has = true;
          break;
        }
      }
      if (!has) {
        ok = false;
        break;
      }
    }
    if (ok) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  printf("%d\n", low <= m ? low : -1);
  return 0;
}