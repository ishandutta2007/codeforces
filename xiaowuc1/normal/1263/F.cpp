#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
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

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> state;

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
int amt;
typedef bitset<1000> bs;

void dfs(int curr, vector<vector<int>>& edges, map<int, int>& assign, vector<bs>& ret) {
  if(assign.count(curr)) {
    ret[curr].set(assign[curr]);
    return;
  }
  for(int out: edges[curr]) {
    dfs(out, edges, assign, ret);
    ret[curr] |= ret[out];
  }
}

vector<bs> readGraph(vector<vector<int>>& edges) {
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int par;
    cin >> par;
    par--;
    while(par >= sz(edges)) edges.push_back({});
    edges[par].push_back(i);
  }
  map<int, int> assign;
  for(int i = 0; i < amt; i++) {
    int t;
    cin >> t;
    t--;
    assign[t] = i;
  }
  vector<bs> ret;
  ret.resize(n);
  dfs(0, edges, assign, ret);
  return ret;
}

vector<pii> init(vector<vector<int>>& edges) {
  vector<pii> ret;
  for(int i = 0; i < sz(edges); i++) {
    for(int out: edges[i]) {
      ret.push_back({i, out});
    }
  }
  return ret;
}

void solve() {
  cin >> amt;
  vector<vector<int>> aedges, bedges;
  vector<bs> a = readGraph(aedges);
  vector<bs> b = readGraph(bedges);
  vector<pii> ag = init(aedges);
  vector<pii> bg = init(bedges);
  int n = sz(ag) + sz(bg) + 2;
  dinic = new Dinic(n);
  for(int i = 0; i < sz(ag); i++) dinic->AddEdge(n-2, i, 1);
  for(int i = 0; i < sz(bg); i++) dinic->AddEdge(sz(ag) + i, n-1, 1);
  {
    int idx = 0;
    for(pii out: ag) {
      int idx2 = sz(ag);
      for(pii out2: bg) {
        bool found = (a[out.second]&b[out2.second]).count();
        if(found) dinic->AddEdge(idx, idx2, 1);
        idx2++;
      }
      idx++;
    }
  }
  cout << n-dinic->MaxFlow(n-2, n-1)-2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}