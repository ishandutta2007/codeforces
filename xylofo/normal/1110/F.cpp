/*
 *
 * Solves problem without eulerian order constraint.
 *
 * */
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


bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 
bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 

const int R = 5e5+10;
const int LG = 21;
ll query_ans[R];
ll closest_active[R];
vector<ll> dist[R];
int when[R];
int cen_parent0[R];


int main() {
  auto BEGIN = clock();

  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;

  vi p(n,-1);
  vector<vector<pair<int,ll>>> g(n);
  rep(i,1,n) {
    int w;
    cin>>p[i]>>w;
    //p[i] = 1; w = 1;

    --p[i];
    g[p[i]].emplace_back(i, w);
    g[i].emplace_back(p[i], w);
  }
  rep(i,0,n) cen_parent0[i] = -1;
  rep(i,0,n) dist[i] = vector<ll>(LG,-1e18);


  vi dead(n,0);
  vi siz(n,0);
  int cen = -1;
  function<void(int,int,int,int,int)> dfs
    = [&](int x, int p, int SIZ, int rt, int lev) {
      //cen_parent[lev][x] = rt;
      if(rt != x && rt != -1) cen_parent0[x] = rt;

      siz[x] = 1;
      int mx_ch = 0;
      for(auto [y,w] : g[x]) if(!dead[y] && y != p) {
        dist[y][lev] = dist[x][lev]+w;
        dfs(y,x,SIZ,rt,lev);
        siz[x] += siz[y];
        mx_ch = max(mx_ch, siz[y]);
      }
      mx_ch = max(mx_ch, SIZ-siz[x]);
      if(2*mx_ch <= SIZ) cen = x;
    };

  function<void(int,int,int)> decompose = [&](int x, int SIZ,int lev) {
    cen = -1;
    dfs(x,-1,SIZ,-1,lev);
    x = cen;
    assert(cen != -1);
    dist[x][lev] = 0;
    dfs(x,-1,SIZ,x,lev);

    dead[x] = true;
    for(auto [y,w] : g[x]) if(!dead[y]) decompose(y,siz[y],lev+1);
    return x;
  };

  decompose(0,n,0);

  rep(i,0,n) {
    while(dist[i].back() < 0) dist[i].pop_back();
    reverse(all(dist[i]));
  }
  debug("centroid done", ld(clock()-BEGIN)/CLOCKS_PER_SEC);

  //debug(cen_parent0);
  //debug(cen_parent);


  struct Query {
    int idx;
    int v;
  };

  vector<vector<Query>> seg_tree(2*n);

  rep(i,0,q) {
    int v, l, r;
    cin>>v>>l>>r;
    //v = rand()%n+1;
    //l = rand()%n+1, r = rand()%n+1;
    //if(l > r) swap(l,r);

    --v,--l;

    Query q{i, v};

    ll best = 1e18;
    for(l+=n, r+=n; l < r; l /= 2, r /= 2) {
      if(l&1) seg_tree[l++].emplace_back(q);
      if(r&1) seg_tree[--r].emplace_back(q);
    }
    //assert(best != 1e18);
    //cout << best << "\n";
  }

  vector<vi> in_range(2*n);
  rep(i,0,n) if(sz(g[i]) == 1) for(int p = i+n; p; p/=2) in_range[p].emplace_back(i);

  debug("prebuild done", ld(clock()-BEGIN)/CLOCKS_PER_SEC);

  int T = 9;

  auto activate = [&](int x) {
    int p = x;
    rep(lev,0,LG) {
      if(when[p] != T) when[p] = T, closest_active[p] = 1e18;
      smin(closest_active[p], dist[x][lev]);
      p = cen_parent0[p];
      if(p == -1) break;
    }
  };

  auto query = [&](Query q) {
    int p = q.v;
    rep(lev,0,LG) {
      if(when[p] != T) when[p] = T, closest_active[p] = 1e18;
      smin(query_ans[q.idx], dist[q.v][lev] + closest_active[p]);
      p = cen_parent0[p];
      if(p == -1) break;
    }
  };

  rep(i,0,q) query_ans[i] = 1e18;

  function<void(int)> st_dfs = [&](int p) {
    if(p >= 2*n) return;
    ++T;
    for(int x : in_range[p]) activate(x);
    for(auto q : seg_tree[p]) query(q);
    st_dfs(2*p);
    st_dfs(2*p+1);
  };
  st_dfs(1);

  debug("dfs done", ld(clock()-BEGIN)/CLOCKS_PER_SEC);

  rep(i,0,q) cout << query_ans[i] << "\n";

}