#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
  if (A[a] != L) return 0;
  A[a] = -1;
  for (int b : g[a]) if (B[b] == L + 1) {
    B[b] = 0;
    if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
      return btoa[b] = a, 1;
  }
  return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
  int res = 0;
  vi A(g.size()), B(btoa.size()), cur, next;
  for (;;) {
    fill(all(A), 0);
    fill(all(B), 0);
    /// Find the starting nodes for BFS (i.e. layer 0).
    cur.clear();
    for (int a : btoa) if(a != -1) A[a] = -1;
    rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
    /// Find all layers using bfs.
    for (int lay = 1;; lay++) {
      bool islast = 0;
      next.clear();
      for (int a : cur) for (int b : g[a]) {
        if (btoa[b] == -1) {
          B[b] = lay;
          islast = 1;
        }
        else if (btoa[b] != a && !B[b]) {
          B[b] = lay;
          next.push_back(btoa[b]);
        }
      }
      if (islast) break;
      if (next.empty()) return res;
      for (int a : next) A[a] = lay;
      cur.swap(next);
    }
    /// Use DFS to scan for augmenting paths.
    rep(a,0,sz(g))
      res += dfs(a, 0, g, btoa, A, B);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  rep(i,0,n) cin>>v[i];

  map<tuple<int,int,int>,int> verts;
  vector<vi> g;
  auto V = [&](int x, int y, int down_or_left) {
    auto q = tuple(x,y,down_or_left);
    if(!verts.count(q)) {
      verts[q] = sz(verts);
      g.emplace_back();
    }
    return verts[q];
  };
  auto E = [&](int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
  };


  int dx[] = {-1,0,1,0};
  int dy[] = {0,1,0,-1};
  auto valid = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };

  int blocks = 0;
  rep(x,0,n) rep(y,0,m) if(v[x][y] == '#') {
    ++blocks;
    vi NS, EW;
    rep(d,0,4) {
      int nx = x + dx[d], ny = y + dy[d];
      if(!valid(nx,ny)) continue;
      if(v[nx][ny] != '#') continue;
      (x==nx ? NS : EW).push_back(V(min(x,nx),min(y,ny),x==nx));
    }
    for(int p:NS) for(int q:EW) E(p,q);
  }

  vi btoa(sz(g), -1);
  int match = hopcroftKarp(g,btoa);
  assert(match % 2 == 0);
  match /= 2;
  int indep = sz(g) - match;
  int ans = blocks - indep;
  cout << ans << endl;
}