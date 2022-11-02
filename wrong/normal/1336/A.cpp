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

vector<int> to[200050];
int dep[200050], sz[200050], par[200050];

void dfs(int u, int d = 0, int p = -1) {
  par[u] = p;
  dep[u] = d;
  for (const int v : to[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, d + 1, u);
    sz[u] += sz[v] + 1;
  }
}

int main() {
  int n = in();
  int k = in();

  for (int i = 0; i < n - 1; ++i) {
    int u = in() - 1;
    int v = in() - 1;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  dfs(0);

  priority_queue<pair<int, int>> Q;
  Q.emplace(sz[0] - dep[0], 0);

  Int res = 0;
  for (int i = 0; i < n - k; ++i) {
    const auto t = Q.top();
    Q.pop();
    res += t.first;
    for (const int v : to[t.second]) {
      if (v == par[t.second]) {
        continue;
      }
      Q.emplace(sz[v] - dep[v], v);
    }
  }

  cout << res << endl;

  return 0;
}