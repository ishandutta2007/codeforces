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

struct edge {
  int src, dst, face, nxt;
  edge(int src, int dst) : src(src), dst(dst), face(-1), nxt(-1) { }
};
vector<int> adj[100050];

struct fc {
  vector<int> vs;
  int col;
  fc(const vector<int>& vs) : vs(vs), col(-1) { }
};

map<pair<int, int>, int> es;
vector<edge> E;
vector<fc> F;

struct gedge {
  int src, dst;
  gedge(int s, int d) : src(s), dst(d) { }
};
typedef vector<gedge> edges;
typedef vector<edges> graph;

int sz[100050];

int sdfs(const graph& g, int u, int p = -1) {
  int r = 1;
  for (const gedge e : g[u]) {
    if (F[e.dst].col != -1 || e.dst == p) {
      continue;
    }
    r += sdfs(g, e.dst, u);
  }
  return r;
}

void cdfs(int V, const graph& g, int u, int& c, int p = -1) {
  int mx = 0;
  sz[u] = 1;
  for (const gedge e : g[u]) {
    if (F[e.dst].col != -1 || e.dst == p) {
      continue;
    }
    cdfs(V, g, e.dst, c, u);
    chmax(mx, sz[e.dst]);
    sz[u] += sz[e.dst];
  }
  if (mx * 2 <= V && (V - sz[u]) * 2 <= V) {
    c = u;
  }
}

void color(const graph& g, int r, int col) {
  int center = -1;
  int V = sdfs(g, r);
  cdfs(V, g, r, center);

  F[center].col = col;
  for (const gedge e : g[center]) {
    if (F[e.dst].col != -1) {
      continue;
    }
    color(g, e.dst, col + 1);
  }
}

int main() {
  int N = in();
  int M = in();

  for (int i = 0; i < N; ++i) {
    int ii = (i + 1) % N;
    E.emplace_back(i, ii);
    es[{i, ii}] = i;
    adj[i].push_back(ii);
    adj[ii].push_back(i);
  }

  for (int i = 0; i < M; ++i) {
    int a = in() - 1;
    int b = in() - 1;
    es[{a, b}] = E.size();
    E.emplace_back(a, b);
    es[{b, a}] = E.size();
    E.emplace_back(b, a);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < N; ++i) {
    sort(adj[i].begin(), adj[i].end(), [=](const int x, const int y) {
      return ((x + N - i) % N) < ((y + N - i) % N);
    });
    for (int j = 1; j < adj[i].size(); ++j) {
      int e = es[{adj[i][j], i}];
      E[e].nxt = es[{i, adj[i][j - 1]}];
    }
  }

  vector<int> vis(E.size(), 0);
  for (int ei = 0; ei < E.size(); ++ei) {
    if (vis[ei]) {
      continue;
    }

    vector<int> vs;
    for (int ej = ei; ;) {
      vs.push_back(E[ej].src);
      E[ej].face = F.size();
      vis[ej] = 1;
      ej = E[ej].nxt;
      if (ej == ei) {
        break;
      }
    }
    sort(vs.begin(), vs.end());
    reverse(vs.begin(), vs.end());
    while (vs.size() > 3) {
      vs.pop_back();
    }
    F.emplace_back(vs);
  }

  graph G(F.size());
  for (int i = 0; i < E.size(); ++i) {
    if ((E[i].src + 1) % N != E[i].dst && E[i].src < E[i].dst) {
      const edge& e = E[i];
      const edge& r = E[es[{E[i].dst, E[i].src}]];
      G[e.face].emplace_back(e.face, r.face);
      G[r.face].emplace_back(r.face, e.face);
    }
  }

  color(G, 0, 1);
  vector<int> ord(F.size());
  for (int i = 0; i < F.size(); ++i) {
    ord[i] = i;
  }
  sort(ord.begin(), ord.end(), [&] (const int a, const int b) {
    return F[a].vs < F[b].vs;
  });

  for (int i = 0; i < F.size(); ++i) {
    printf("%d%c", F[ord[i]].col, i+1 == F.size() ? '\n' : ' ');
  }

  return 0;
}