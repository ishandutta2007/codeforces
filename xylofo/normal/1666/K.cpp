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

  int A, B;
  cin>>A>>B;
  --A,--B;

  Dinic mf(2*n+2);
  int source = 2*n, sink = 2*n+1;
  auto L = [&](int x){ return x; };
  auto R = [&](int x){ return x+n; };

  mf.addEdge(source, L(A), 1e18);
  mf.addEdge(R(A), sink, 1e18);
  mf.addEdge(L(B), sink, 1e18);
  mf.addEdge(source, R(B), 1e18);


  auto ae = [&](int a, int b, int c){
    mf.addEdge(L(a), R(b), c);
    mf.addEdge(R(a), L(b), c);
    mf.addEdge(L(b), R(a), c);
    mf.addEdge(R(b), L(a), c);
  };

  rep(i,0,m) {
    int x,y,c;
    cin>>x>>y>>c;
    --x,--y;
    ae(x,y,c);
  }

  ll rk  = mf.calc(source, sink);
  cout << rk << endl;
  rep(i,0,n) {
    bool left_red = mf.leftOfMinCut(L(i));
    bool right_red = mf.leftOfMinCut(R(i));
    if(left_red == right_red) cout << "C";
    else if(left_red) cout << "A";
    else cout << "B";
  }
  cout << endl;
}