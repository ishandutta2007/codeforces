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

namespace SCC {
const int MAXN = 100050;
int C, N; int scc[MAXN]; vector<int> graph[MAXN], rev[MAXN], st;
void ae(int u, int v) {
  graph[u].push_back(v);
  rev[v].push_back(u);
}
void visit0(int p) {
	scc[p] = -1;
	for (auto q : graph[p]) if (!scc[q]) visit0(q);
	st.push_back(p);
}
void visit1(int p) {
	scc[p] = C;
	for (auto q : rev[p]) if (scc[q]<0) visit1(q);
}
void scc_go() {
	memset(scc, 0, N * 4); C = 0;
	for (int i = 0; i < N; ++i) if (!scc[i]) visit0(i);
	for (int i = N - 1; i >= 0; --i) if (scc[st[i]]<0) ++C, visit1(st[i]);
}
}

int U[100050], cnt[100050], out[100050];

int main() {
  int N = in();
  int M = in();
  int H = in();
  for (int i = 0; i < N; ++i) {
    U[i] = in();
  }

  SCC::N = N;
  for (int i = 0; i < M; ++i) {
    int a = in() - 1;
    int b = in() - 1;
    if ((U[a] + 1) % H == U[b]) {
      SCC::ae(a, b);
    }
    if ((U[b] + 1) % H == U[a]) {
      SCC::ae(b, a);
    }
  }
  SCC::scc_go();
  for (int i = 0; i < SCC::N; ++i) {
    --SCC::scc[i];
  }

  for (int i = 0; i < N; ++i) {
    ++cnt[SCC::scc[i]];
    for (const int j : SCC::graph[i]) {
      if (SCC::scc[i] != SCC::scc[j]) {
        out[SCC::scc[i]] = 1;
      }
    }
  }
  int res = N + 1, res_c = -1;
  for (int i = 0; i < SCC::C; ++i) {
    if (out[i] == 0 && res > cnt[i]) {
      res = cnt[i];
      res_c = i;
    }
  }

  vector<int> vs;
  for (int i = 0; i < N; ++i) {
    if (SCC::scc[i] == res_c) {
      vs.push_back(i);
    }
  }

  printf("%d\n", res);
  for (int i = 0; i < res; ++i) {
    printf("%d%c", 1 + vs[i], i+1 == res ? '\n' : ' ');
  }

  return 0;
}