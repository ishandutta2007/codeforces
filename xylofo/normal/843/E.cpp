#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


struct Dinic {
  struct Edge {
    int to, rev;
    ll c, oc;
    ll flow() { return max(oc - c, 0LL); } // if you need flows
  };
  vi lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(int a, int b, ll c, ll rcap = 0) {
    adj[a].push_back({b, sz(adj[b]), c, c});
    adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
  }

  ll dfs(int v, int t, ll f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < sz(adj[v]); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1)
        if (ll p = dfs(e.to, t, min(f, e.c))) {
          e.c -= p, adj[e.to][e.rev].c += p;
          return p;
        }
    }
    return 0;
  }

  ll calc(int s, int t) {
    ll flow = 0; q[0] = s;
    rep(L,0,31) do { // 'int L=30' maybe faster for random data
      lvl = ptr = vi(sz(q));
      int qi = 0, qe = lvl[s] = 1;
      while (qi < qe && !lvl[t]) {
        int v = q[qi++];
        for (Edge e : adj[v])
          if (!lvl[e.to] && e.c >> (30 - L))
            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
      }
      while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
    } while (lvl[t]);
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  int source, sink;
  cin>>source>>sink;
  --source;
  --sink;

  vector<tuple<int,int,int>> edges(m);
  vector<vi> scc_g(n);

  Dinic mf_cut(n);

  rep(i,0,m) {
    int x,y,w;
    cin>>x>>y>>w;
    --x,--y;
    edges[i] = {x,y,w};
  }

  for(auto [x,y,w] : edges) {
    if(w == 0) mf_cut.addEdge(x,y,1e9);
    else mf_cut.addEdge(x,y,1,1e9);
  }

  ll rk = mf_cut.calc(source, sink);
  debug(rk);
  assert(rk < 1e9);
  rep(i,0,n) debug(i,mf_cut.leftOfMinCut(i));
  debug(edges);
  debug(source, sink);

  const ll CUT = 1e4;

  vector<ll> delta(n);
  Dinic mf_circ(n+2);
  for(auto [x,y,w] : edges) {
    if(!w) continue;
    assert(!(mf_cut.leftOfMinCut(y) && !mf_cut.leftOfMinCut(x)));
    delta[x] -= 1;
    delta[y] += 1;
    if(mf_cut.leftOfMinCut(x) && !mf_cut.leftOfMinCut(y))
      mf_circ.addEdge(x,y,CUT-1);
    else {
      mf_circ.addEdge(x,y,1e8);
    }
  }
  delta[source] += CUT*rk;
  delta[sink] -= CUT*rk;
  int source2 = n, sink2 = n+1;
  ll out = 0;
  rep(i,0,n) {
    out += max<ll>(0,delta[i]);
    if(delta[i] > 0) mf_circ.addEdge(source2, i, delta[i]);
    if(delta[i] < 0) mf_circ.addEdge(i, sink2, -delta[i]);
  }
  ll rk_circ = mf_circ.calc(source2, sink2);
  debug(out, rk_circ);
  assert(rk_circ == out);

  map<pii,pair<ll,ll>> ff;
  rep(x,0,n) for(auto e : mf_circ.adj[x]) if(e.oc) {
    ff[pii(x,e.to)] = {e.flow()+1, e.oc+1};
  }

  cout << rk << endl;
  for(auto [x,y,w] : edges) {
    if(w) cout << ff[pii(x,y)].first << " " << ff[pii(x,y)].second << "\n";
    else cout << "0 1\n";
  }
}