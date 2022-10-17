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


void bad(string s = "-1") {
  cout << s << endl;
  exit(0);
}

template <bool VALS_EDGES> struct HLD {
  int N, tim = 0;
  vector<vi> adj;
  vi par, siz, depth, rt, pos;
  HLD(vector<vi> adj_)
    : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
    rt(N),pos(N){ dfsSz(0); dfsHld(0); }
  void dfsSz(int v) {
    if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
    for (int& u : adj[v]) {
      par[u] = v, depth[u] = depth[v] + 1;
      dfsSz(u);
      siz[v] += siz[u];
      if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
    }
  }
  void dfsHld(int v) {
    pos[v] = tim++;
    for (int u : adj[v]) {
      rt[u] = (u == adj[v][0] ? rt[v] : u);
      dfsHld(u);
    }
  }
  template <class B> void process(int u, int v, B op) {
    for (; rt[u] != rt[v]; v = par[rt[v]]) {
      if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
      op(pos[rt[v]], pos[v] + 1);
    }
    if (depth[u] > depth[v]) swap(u, v);
    op(pos[u] + VALS_EDGES, pos[v] + 1);
  }
  bool is_anc(int x, int anc) {
    return pos[anc] <= pos[x] && pos[x] < pos[anc]+siz[anc];
  }
  void subtree(int v, auto&& op) {
    return op(pos[v] + VALS_EDGES, pos[v] + siz[v]);
  }
  int towards(int anc, int x) {
    int l = 0, r = sz(adj[anc]);
    assert(r != 0);
    while(l+1 != r) {
      int q = (l+r)/2;
      int v = adj[anc][q];
      if(pos[v] <= pos[x]) l = q;
      else r = q;
    }
    int v = adj[anc][l];
    assert(is_anc(x,v));
    return v;
  }
};



struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
  ll query(int l, int r) { return query(r)-query(l); };
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  rep(x,1,n) {
    int y;
    cin>>y;
    --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  vector<pii> queries(m);
  for(auto&[x,y]:queries) {
    cin>>x>>y;
    --x,--y;
  }

  HLD<false> hld(g);

  vector<pii> climb, cross;
  for(auto&[x,y]:queries) {
    if(hld.is_anc(x,y)) climb.emplace_back(x,y);
    else if(hld.is_anc(y,x)) climb.emplace_back(y,x);
    else cross.emplace_back(x,y);
  }

  //debug(climb, cross);

  int tot = 0;
  FT ft(n);
  auto mark = [&](int x) {
    //debug(x+1);
    ft.update(hld.pos[x],+1);
    ++tot;
  };
  auto already_ok = [&](int x,int y) {
    if(hld.is_anc(y,x)) swap(x,y);
    int q = 0;
    if(hld.is_anc(x,y)) {
      hld.subtree(hld.towards(y,x),[&](int l, int r){ q += ft.query(l,r); });
      hld.subtree(x,[&](int l, int r){ q -= ft.query(l,r); });
    }
    else {
      q += tot;
      hld.subtree(x,[&](int l, int r){ q -= ft.query(l,r); });
      hld.subtree(y,[&](int l, int r){ q -= ft.query(l,r); });
    }
    assert(q >= 0);
    return q > 0;
  };

  sort(all(climb), [&](pii a, pii b){
      return tie(hld.depth[a.second],a) > tie(hld.depth[b.second],b);
      });

  for(auto [x,anc] : climb) {
    if(already_ok(x,anc)) continue;
    int v = hld.towards(anc, x);
    //debug(anc, v, x);
    if(v == x) bad();
    mark(v);
  }

  for(auto [x,y] : cross) if(!already_ok(x,y)) mark(0);

  for(auto [x,y] : queries)  assert(already_ok(x,y));

  cout << tot << endl;
}