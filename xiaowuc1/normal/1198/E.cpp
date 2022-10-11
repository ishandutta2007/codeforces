#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

typedef long long LL;

struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;

  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(u, v, cap);
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(v, u, 0);
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

int xa[55];
int ya[55];
int xb[55];
int yb[55];

int solve(int n) {
  vector<int> xs, ys;
  for(int i = 0; i < n; i++) {
    xs.push_back(xa[i]);
    xs.push_back(xb[i]);
    ys.push_back(ya[i]);
    ys.push_back(yb[i]);
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
  ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
  vector<pii> yIntervals;
  for(int i = 0; i < ys.size(); i++) {
    yIntervals.emplace_back(ys[i], ys[i]);
    if(i + 1 < ys.size() && ys[i+1] - ys[i] != 1) {
      yIntervals.emplace_back(ys[i]+1, ys[i+1]-1);
    }
  }
  vector<pii> xIntervals;
  for(int i = 0; i < xs.size(); i++) {
    xIntervals.emplace_back(xs[i], xs[i]);
    if(i + 1 < xs.size() && xs[i+1] - xs[i] != 1) {
      xIntervals.emplace_back(xs[i]+1, xs[i+1]-1);
    }
  }
  /*
  construction is
  0 to xs.size()-1 is xs
  xs.size() to ys.size()-1 is ys
  xs.size() + ys.size() is source
  xs.size() + ys.size() + 1 is sink
  */
  xs.clear();
  ys.clear();
  Dinic dinic(xIntervals.size() + yIntervals.size() + 2);
  for(int i = 0; i < xIntervals.size(); i++) {
    dinic.AddEdge(xIntervals.size() + yIntervals.size(), i, xIntervals[i].second - xIntervals[i].first + 1);
  }
  for(int i = 0; i < yIntervals.size(); i++) {
    dinic.AddEdge(xIntervals.size() + i, xIntervals.size() + yIntervals.size() + 1, yIntervals[i].second - yIntervals[i].first + 1);
  }
  for(int i = 0; i < xIntervals.size(); i++) {
    int xLow = xIntervals[i].first;
    int xHigh = xIntervals[i].first;
    vector<pii> covered;
    for(int a = 0; a < n; a++) {
      if(xa[a] <= xLow && xb[a] >= xHigh) {
        covered.emplace_back(ya[a], yb[a]);
      }
    }
    sort(covered.begin(), covered.end());
    {
      vector<pii> realCovered;
      for(pii out: covered) {
        if(realCovered.empty()) {
          realCovered.push_back(out);
          continue;
        }
        if(realCovered.back().second >= out.first) {
          realCovered.back().second = max(realCovered.back().second, out.second);
        }
        else {
          realCovered.push_back(out);
        }
      }
      covered = realCovered;
    }
    for(int a = 0; a < yIntervals.size(); a++) {
      int cover = 0;
      for(pii out: covered) {
        int lhs = max(out.first, yIntervals[a].first);
        int rhs = min(out.second, yIntervals[a].second);
        if(lhs <= rhs) cover += rhs-lhs+1;
      }
      if(cover) {
        dinic.AddEdge(i, xIntervals.size() + a, cover);
      }
    }
  }
  return dinic.MaxFlow(xIntervals.size() + yIntervals.size(), xIntervals.size() + yIntervals.size() + 1);
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
  cout << solve(m) << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}