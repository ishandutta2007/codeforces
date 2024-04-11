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

const int B = 320;

int N, M, Q;

struct edge {
  int a, b, c;
  edge() { }
  edge(int a, int b, int c) : a(a), b(b), c(c) { }
} E[100050];
bool operator < (const edge& e, const edge& f) {
  return e.c < f.c;
}

vector<int> to[100050];

struct uf {
  vector<int> U;
  uf(int n) : U(n, -1) {}
  int find(int x) {
    return U[x] < 0 ? x : U[x] = find(U[x]);
  }
  void uni(int x, int y) {
    x = find(x); y = find(y);
    if (x != y) {
      if (U[x] > U[y]) swap(x, y);
      U[x] += U[y];
      U[y] = x;
    }
  }
};

vector<map<int, int>> MS;
vector<uf> US;

int main() {
  N = in();
  M = in();

  for (int i = 0; i < M; ++i) {
    E[i].a = in() - 1;
    E[i].b = in() - 1;
    E[i].c = in();
  }
  sort(E, E + M);

  for (int i = 0; i < M; ) {
    int j = i;
    vector<int> vs;
    while (j < M && E[i].c == E[j].c) {
      vs.push_back(E[j].a);
      vs.push_back(E[j].b);
      ++j;
    }

    int m = j - i;
    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    
    uf u(vs.size());
    for (int k = i; k < j; ++k) {
      int a = lower_bound(vs.begin(), vs.end(), E[k].a) - vs.begin();
      int b = lower_bound(vs.begin(), vs.end(), E[k].b) - vs.begin();
      u.uni(a, b);
    }

    if (m < B) {
      for (int ai = 0; ai < vs.size(); ++ai) {
        for (int bi = ai + 1; bi < vs.size(); ++bi) {
          if (u.find(ai) == u.find(bi)) {
            to[vs[ai]].push_back(vs[bi]);
          }
        }
      }
    } else {
      MS.push_back(map<int, int>());
      for (int k = 0; k < vs.size(); ++k) {
        MS.back()[vs[k]] = k;
      }
      US.push_back(move(u));
    }
    i = j;
  }

  for (int i = 0; i < N; ++i) {
    sort(to[i].begin(), to[i].end());
  }

  Q = in();
  for (int i = 0; i < Q; ++i) {
    int u = in() - 1;
    int v = in() - 1;
    if (u > v) {
      swap(u, v);
    }

    int res = 0;
    auto eq = equal_range(to[u].begin(), to[u].end(), v);
    if (eq.first != to[u].end() && *eq.first == v) {
      res += eq.second - eq.first;
    }
    for (int j = 0; j < MS.size(); ++j) {
      int uu = -1, vv = -1;
      if (MS[j].count(u)) {
        uu = MS[j][u];
      } else {
        continue;
      }
      if (MS[j].count(v)) {
        vv = MS[j][v];
      } else {
        continue;
      }
      if (US[j].find(uu) == US[j].find(vv)) {
        ++res;
      }
    }

    printf("%d\n", res);
  }

  return 0;
}