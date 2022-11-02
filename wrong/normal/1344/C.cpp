#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

int N, M;

struct edge {
  int src, dst;
  edge(int s, int d) : src(s), dst(d) { }
};
typedef vector<edge> edges;
typedef vector<edges> graph;

bool dfs_cycle(const graph& g, int u, vector<int>& vis) {
  vis[u] = 1;
  for (const edge& e : g[u]) {
    if (vis[e.dst] == 1) {
      return true;
    }
    if (vis[e.dst] == 0) {
      if (dfs_cycle(g, e.dst, vis)) {
        return true;
      }
    }
  }
  vis[u] = 2;
  return false;
}

bool has_cycle(const graph& g) {
  vector<int> vis(N, 0);
  for (int u = 0; u < N; ++u) {
    if (vis[u] == 0) {
      if (dfs_cycle(g, u, vis)) {
        return true;
      }
    }
  }
  return false;
}

int dfs_min(const graph& g, int u, vector<int>& ms) {
  if (ms[u] < INF) {
    return ms[u];
  }
  int res = INF;
  for (const edge& e : g[u]) {
    chmin(res, min(e.dst, dfs_min(g, e.dst, ms)));
  }
  return ms[u] = res;
}

int main() {
  N = in();
  M = in();
  graph g(N), r(N);
  for (int i = 0; i < M; ++i) {
    int a = in() - 1;
    int b = in() - 1;
    g[a].emplace_back(a, b);
    r[b].emplace_back(b, a);
  }

  if (has_cycle(g)) {
    puts("-1");
    return 0;
  }

  vector<int> lo_min(N, INF), up_min(N, INF);
  for (int u = 0; u < N; ++u) {
    dfs_min(g, u, lo_min);
    dfs_min(r, u, up_min);
  }

  int res = 0;
  vector<int> qs(N, 0);
  for (int u = 0; u < N; ++u) {
    if (u < lo_min[u] && u < up_min[u]) {
      ++res;
      qs[u] = 1;
    }
  }

  printf("%d\n", res);
  for (int u = 0; u < N; ++u) {
    putchar("EA"[qs[u]]);
  }
  puts("");

  return 0;
}