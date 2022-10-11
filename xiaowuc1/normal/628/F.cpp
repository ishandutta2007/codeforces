#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

typedef int LL;

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

Dinic* dinic;

void solve() {
  int n, b, q;
  cin >> n >> b >> q;
  vector<pii> v;
  while(q--) {
    int sz, have;
    cin >> sz >> have;
    v.push_back({sz, have});
  }
  v.push_back({b, n});
  sort(v.begin(), v.end());
  // {1 to n, k of them exist}
  for(int i = 1; i < v.size(); i++) {
    if(v[i].second < v[i-1].second) {
      cout << "unfair\n";
      return;
    }
    if(v[i].first == v[i-1].first && v[i].second != v[i-1].second) {
      cout << "unfair\n";
      return;
    }
  }
  /*
  construction is
  0 is source
  1 to b are the given values
  b+1 to b+v.size() are gadgets
  b+v.size()+1 to b+v.size()+5 are modulo
  b+v.size()+6 is sink
  */
  dinic = new Dinic(b+v.size()+7);
  for(int i = 1; i <= b; i++) {
    int inc = i%5 == 0 ? 5 : i%5;
    dinic->AddEdge(i, b+v.size()+inc, 1);
  }
  for(int i = 1; i <= 5; i++) {
    dinic->AddEdge(b+v.size()+i, b+v.size()+6, n/5);
  }
  for(int i = 0; i < v.size(); i++) {
    int last = i == 0 ? 0 : v[i-1].second;
    if(last < v[i].second) dinic->AddEdge(0, b+1+i, v[i].second-last);
    last = i == 0 ? 0 : v[i-1].first;
    for(int a = last+1; a <= v[i].first; a++) {
      dinic->AddEdge(b+1+i, a, 1);
    }
  }
  int flow = dinic->MaxFlow(0, b+v.size()+6);
  if(flow != n) {
    cout << "unfair\n";
  }
  else {
    cout << "fair\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}