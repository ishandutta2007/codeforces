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

void solve(int tc) {
  int n;
  cin >> n;
  vi a(n);
  vector<vi> g(n);
  rep(i,0,n) {
    cin >> a[i];
    --a[i];
    g[a[i]].emplace_back(i);
  }

  vector<vi> cycs;
  vector<vi> paths;

  vi vis(n);

  function<void(int,vi&)> dfs = [&](int x, vi& pth) {
    vis[x] = 2;
    pth.emplace_back(x);
    for(int y : g[x]) if(vis[y] != 2) {
      dfs(y,pth);
      pth = {};
    }
    if(sz(pth)) paths.emplace_back(pth);
  };

  rep(i,0,n) if(!vis[i]) {
    int x = i, y = a[i];
    while(x != y) x = a[x], y = a[a[y]];
    vi c;
    do {
      c.emplace_back(x);
      vis[x] = 1;
      x = a[x];
    } while(x != y);

    int rt = -1;
    for(int x : c) if(sz(g[a[x]]) > 1) {
      rt = x;
      break;
    }

    if(rt == -1) {
      cycs.emplace_back(c);
      continue;
    }

    vi pth;
    dfs(rt, pth);
    assert(sz(pth) == 0);
  }

  debug()
  debug(cycs);
  debug(paths);

  vi c;
  for(auto p : paths) for(auto x : p) c.emplace_back(x);
  reverse(all(c));
  if(sz(c) > 1) cycs.emplace_back(c);
  if(sz(c) == 1) for(int x : c) cycs.back().emplace_back(x);
  debug(cycs);

  vi b(n);
  for(auto c : cycs) {
    rep(i,0,sz(c)) b[c[i]] = c[(i+1)%sz(c)];
  }
  debug(b);

  int cnt = 0;
  rep(i,0,n) if(b[i] == a[i]) ++cnt;

  cout << cnt << "\n";
  rep(i,0,n) cout << b[i]+1 << " ";
  cout << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}