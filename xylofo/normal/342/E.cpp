#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  rep(i,1,n) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }

  int centroid = -1;
  vi siz(n), dead(n);
  vector<vi> depth(n);
  function<void(int,int,int,int)> dfs = [&](int x, int p, int n, int lev) {
    if(sz(depth[x]) <= lev) depth[x].resize(lev+1);
    depth[x][lev] = p >= 0 ? depth[p][lev]+1 : 0;

    siz[x] = 1;
    int mx = 0;
    for(int y : g[x]) if(y != p && !dead[y]) {
      dfs(y,x,n, lev);
      siz[x] += siz[y];
      mx = max(mx, siz[y]);
    }
    mx = max(mx, n-siz[x]);
    if(2*mx <= n) centroid = x;
  };

  vi cen_par(n,-1), at_lev(n,-1);
  function<int(int,int,int)> decompose = [&](int rt, int n, int lev) {
    centroid = -1;
    dfs(rt,-1,n,lev);
    rt = centroid;
    assert(rt != -1);
    dfs(rt,-1,n,lev);
    dead[rt] = true;
    at_lev[rt] = lev;
    for(int x: g[rt]) if(!dead[x]) {
      int ch = decompose(x, siz[x], lev+1);
      cen_par[ch] = rt;
    }
    return rt;
  };
  decompose(0,n,0);

  vi closest_red(n,1e9);
  auto mark_red = [&](int x) {
    int y = x;
    while(y != -1) {
      int d = depth[x][at_lev[y]];
      closest_red[y] = min(closest_red[y], d);
      y = cen_par[y];
    }
  };
  auto query = [&](int x) {
    int y = x, ans = 1e9;
    while(y != -1) {
      int d = depth[x][at_lev[y]];
      ans = min(ans, closest_red[y] + d);
      y = cen_par[y];
    }
    return ans;
  };
  mark_red(0);

  rep(i,0,m) {
    int t, x;
    cin>>t>>x;
    --x;
    if(t == 1) mark_red(x);
    else if(t == 2) cout << query(x) << "\n";
    else assert(false);
  }
}