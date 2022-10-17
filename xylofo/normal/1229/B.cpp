#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


const ll md = 1000000007;

pair<vector<vi>, vector<vi> > treeJump(vi& P, vi& G){
  int on = 1, d = 1;
  while(on < sz(P)) on *= 2, d++;
  vector<vi> jmp(d, P);
  vector<vi> g(d, G);
  rep(i,1,d) rep(j,0,sz(P)) {
    jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    g[i][j] = __gcd(g[i-1][j], g[i-1][jmp[i-1][j]]);
  }
  return {jmp,g};
}

int jmp(vector<vi>& tbl, int nod, int steps){
  rep(i,0,sz(tbl))
    if(steps&(1<<i)) nod = tbl[i][nod];
  return nod;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n;
  cin>>n;
  ++n;
  vi a(n);
  rep(i,1,n) cin>>a[i];
  vector<vi> g(n);
  rep(i,1,n-1) {
    int x,y;
    cin>>x>>y;
    g[x].eb(y);
    g[y].eb(x);
  }
  g[0].eb(1);
  vi p(n,0), depth(n,0);
  function<void(int)> dfs = [&](int x){
    trav(y, g[x]) if(y != p[x]) {
      p[y] = x;
      depth[y] = depth[x] + 1;
      dfs(y);
    }
  };
  dfs(0);
  vector<vi> jmp, G;
  tie(jmp, G) = treeJump(p,a);
  int lg = sz(jmp);

  ll ans = 0;
  p[0] = -1;
  rep(x,1,n) {
    ll q = a[x];
    int y = x;
    do {
      ll old = depth[y];
      for(int t = lg-1; t >= 0; --t) {
        if(__gcd(q, G[t][y]) == q) {
          y = jmp[t][y];
        }
      }

      ll delta = (q % md) * (old-depth[y]) % md;
      ans = (ans + delta) % md;
      q = __gcd(q, a[y]);
    } while(y != 0);
  }

  cout << ans << endl;
}