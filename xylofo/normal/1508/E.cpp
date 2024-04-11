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


void bad(string s = "NO") {
  cout << s << endl;
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vi a(n);
  rep(i,0,n) cin >> a[i];
  vector<vi> g(n);
  vi par(n,-1);
  rep(i,1,n) {
    int x, y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    par[y] = x;
  }

  rep(x,0,n) sort(all(g[x]), [&](int i, int j){ return a[i] < a[j]; });

  vi b(n), depth(n,0);
  int ord = 0;
  function<void(int)> dfs = [&](int x) {
    b[x] = ++ord;
    for(int y : g[x]) {
      depth[y] = depth[x]+1;
      dfs(y);
    }
  };
  dfs(0);

  debug(b);

  set<pii> leaves;
  vi deg(n);
  rep(x,0,n) {
    deg[x] = sz(g[x]);
    if(deg[x] == 0) leaves.emplace(b[x],x);
  }

  vi dead(n,0);

  vi ia(n+1);
  rep(i,0,n) ia[a[i]] = i;

  vi c(n,-1);

  ll days = 0;
  rep(i,1,n+1) {
    int x = ia[i];
    days += depth[x];
    if(deg[x] != 0) {

      ord = i;
      function<void(int)> dfs2 = [&](int x) {
        if(dead[x]) return;
        c[x] = ord++;
        for(int y : g[x]) {
          depth[y] = depth[x]+1;
          dfs2(y);
        }
      };
      dfs2(0);
      debug(c);

      int y = 0;
      rep(_,0,depth[x]) {
        int s = -1;
        for(int z : g[y]) if(c[z] > c[y]) { s = z; break; }
        debug(y, s);
        if(s == -1) bad();
        swap(c[s], c[y]);
        y = s;
      }

      debug(c);
      debug(a);
      if(c != a) bad();


      break;
    }
    if(begin(leaves)->second != x) bad();
    leaves.erase(begin(leaves));
    if(par[x] != -1) {
      --deg[par[x]];
      if(deg[par[x]] == 0) leaves.emplace(b[par[x]],par[x]);
    }
    else assert(x == 0);
    dead[x] = 1;
    c[x] = i;
  }

  cout << "YES" << endl;
  cout << days << endl;
  rep(i,0,n) cout << b[i] << " ";
  cout << endl;
}