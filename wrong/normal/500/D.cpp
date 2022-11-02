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

vector<int> to[100050], id[100050];

int N, S[100050];
Int W[100050], L[100050];

int dfs(int u, int p = -1) {
  S[u] = 1;
  for (int i = 0; i < to[u].size(); ++i) {
    int v = to[u][i];
    if (v != p) {
      int s = dfs(v, u);
      Int pat = 0;
      pat += (Int)s * (N - s) * (N - s - 1) * 6;
      pat += (Int)s * (s - 1) * (N - s) * 6;
      W[id[u][i]] = pat;
      S[u] += s;
    }
  }
  return S[u];
}

int main() {
  N = in();
  for (int i = 0; i < N - 1; ++i) {
    int a = in() - 1;
    int b = in() - 1;
    int c = in();
    L[i] = c;
    to[a].push_back(b); id[a].push_back(i);
    to[b].push_back(a); id[b].push_back(i);
  }

  dfs(0);

  Int all = (Int)N * (N - 1) * (N - 2);
  Int rez = 0, rer = 0;
  for (int i = 0; i < N - 1; ++i) {
    rez += W[i] * L[i] / all;
    rer += W[i] * L[i] % all;
    rez += rer / all;
    rer %= all;
  }

  int Q = in();
  for (int i = 0; i < Q; ++i) {
    int a = in() - 1;
    int w = in();
    Int d = L[a] - w;
    L[a] = w;
    rez -= W[a] * d / all;
    rer -= W[a] * d % all;
    if (rer < 0) {
      --rez;
      rer += all;
    }
    printf("%.9f\n", rez + rer / (double)all);
  }

  return 0;
}