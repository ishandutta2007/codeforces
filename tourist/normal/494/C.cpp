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

const int MAX = 200010;

int a[MAX];

const int N = 5010;

vector <int> g[N];
vector <double> f[N];
int start[N], finish[N];
double prob[N];
int from[N], to[N];

void solve(int i) {
  int sz = g[i].size();
  from[i] = 0;
  if (sz == 0) {
    for (int pos = start[i]; pos <= finish[i]; pos++) {
      if (a[pos] > from[i]) {
        from[i] = a[pos];
      }
    }
  } else {
    for (int pos = start[i]; pos < start[g[i][0]]; pos++) {
      if (a[pos] > from[i]) {
        from[i] = a[pos];
      }
    }
    for (int j = 0; j + 1 < sz; j++) {
      for (int pos = finish[g[i][j]] + 1; pos < start[g[i][j + 1]]; pos++) {
        if (a[pos] > from[i]) {
          from[i] = a[pos];
        }
      }
    }
    for (int pos = finish[g[i][sz - 1]] + 1; pos <= finish[i]; pos++) {
      if (a[pos] > from[i]) {
        from[i] = a[pos];
      }
    }
  }
  to[i] = from[i];
  for (int j = 0; j < sz; j++) {
    int u = g[i][j];
    solve(u);
    if (from[u] > from[i]) {
      from[i] = from[u];
    }
    if (to[u] > to[i]) {
      to[i] = to[u];
    }
  }
  f[i].resize(to[i] - from[i] + 1);
  for (int v = to[i]; v >= from[i]; v--) {
    double cur = 1.0;
    for (int j = 0; j < sz; j++) {
      int u = g[i][j];
      if (to[u] >= v) {
        cur *= (1.0 - f[u][v - from[u]]);
      }
    }
    f[i][v - from[i]] = 1.0 - cur;
  }
  f[i][0] = 1.0;
  f[i].push_back(f[i][to[i] - from[i]] * prob[i]);
  for (int v = to[i]; v > from[i]; v--) {
    f[i][v - from[i]] = f[i][v - from[i]] * (1 - prob[i]) + f[i][v - from[i] - 1] * prob[i];
  }
  to[i]++;
}

int st[N];
pair < pair <int, int>, int > adds[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  q++;
  for (int i = 0; i < q; i++) {
    if (i == q - 1) {
      start[i] = 1;
      finish[i] = n + 1;
      prob[i] = 0.0;
    } else {
      scanf("%d %d %lf", start + i, finish + i, prob + i);
    }
    adds[i] = make_pair(make_pair(start[i], -finish[i]), i);
  }
  sort(adds, adds + q);
  for (int i = 0; i < q; i++) {
    g[i].clear();
  }
  int e = 0;
  for (int id = 0; id < q; id++) {
    int i = adds[id].second;
    while (e > 0 && finish[st[e - 1]] < start[i]) {
      e--;
    }
    if (e > 0) {
      g[st[e - 1]].push_back(i);
    }
    st[e++] = i;
  }
  finish[q - 1] = n;
  solve(q - 1);
  double ans = from[q - 1];
  for (int j = from[q - 1] + 1; j <= to[q - 1]; j++) {
    ans += f[q - 1][j - from[q - 1]];
  }
  printf("%.17f\n", ans);
  return 0;
}