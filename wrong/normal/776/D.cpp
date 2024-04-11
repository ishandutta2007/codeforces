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

int R[100050], S[100050][2];

#define VAR(x) ((x)<<1)
#define NOT(x) ((x)^1)

struct edge {
  int src, dst;
  edge(int s, int d) : src(s), dst(d) { }
};
typedef vector<edge> edges;
typedef vector<edges> graph;

void dfs(int v, const graph& g, vector<int>& ord, vector<int>& num, int k) {
  if (num[v] >= 0) {
    return;
  }
  num[v] = k;
  for (int i = 0; i < g[v].size(); ++i) {
    dfs(g[v][i].dst, g, ord, num, k);
  }
  ord.push_back(v);
}

bool sat2(int m, const vector<pair<int, int>>& cs) {
  int n = m * 2;
  graph g(n), h(n);
  for (int i = 0; i < cs.size(); ++i) {
    int u = cs[i].first, v = cs[i].second;
    g[NOT(u)].push_back(edge(NOT(u), v));
    g[NOT(v)].push_back(edge(NOT(v), u));
    h[v].push_back(edge(v, NOT(u)));
    h[u].push_back(edge(u, NOT(v)));
  }
  vector<int> num(n, -1), ord, dro;
  for (int i = 0; i < n; ++i)
    dfs(i, g, ord, num, i);
  reverse(ord.begin(), ord.end());
  fill(num.begin(), num.end(), -1);
  for (int i = 0; i < n; ++i)
    dfs(ord[i], h, dro, num, i);
  for (int i = 0; i < n; ++i)
    if (num[i] == num[NOT(i)])
      return false;
  return true;
}

int main() {
  int N = in();
  int M = in();

  for (int i = 0; i < N; ++i) {
    R[i] = in();
    S[i][0] = S[i][1] = -1;
  }

  for (int i = 0; i < M; ++i) {
    int k = in();
    for (int j = 0; j < k; ++j) {
      int u = in() - 1;
      if (S[u][0] < 0) {
        S[u][0] = i;
      } else {
        S[u][1] = i;
      }
    }
  }

  vector<pair<int, int>> cs;
  for (int i = 0; i < N; ++i) {
    if (R[i] == 0) {
      cs.emplace_back(VAR(S[i][0]), VAR(S[i][1]));
      cs.emplace_back(NOT(VAR(S[i][0])), NOT(VAR(S[i][1])));
    } else {
      cs.emplace_back(VAR(S[i][0]), NOT(VAR(S[i][1])));
      cs.emplace_back(NOT(VAR(S[i][0])), VAR(S[i][1]));
    }
  }

  if (sat2(M, cs)) {
    puts("YES");
  } else {
    puts("NO");
  }

  return 0;
}