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


struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;

  ll W = 0;
  vector<vector<pair<int,ll>>> g(n);
  vector<tuple<ll,int,int>> edges;
  rep(i,0,m) {
    int x,y,w;
    cin>>x>>y>>w;
    --x,--y;
    g[x].emplace_back(y,w);
    g[y].emplace_back(x,w);
    edges.emplace_back(w,x,y);
    W ^= w;
  }

  ll have0 = (ll(n)*ll(n-1))/2 - m;
  ll use0 = 0;

  UF uf(n);

  set<int> remain;
  rep(i,0,n) remain.emplace(i);
  queue<int> todo;

  while(sz(remain)) {
    int x = *begin(remain);
    todo.emplace(x);
    remain.erase(x);
    while(sz(todo)) {
      int y = todo.front();
      todo.pop();
      if(x != y) {
        int k = uf.join(x,y);
        debug(x,y);
        assert(k);
        ++use0;
      }

      set<int> rem(all(remain));
      for(auto [z,w] : g[y]) rem.erase(z);
      for(auto z : rem) {
        remain.erase(z);
        todo.emplace(z);
      }
    }
  }

  UF uf_nonzero(n);

  debug(use0, have0);
  assert(use0 <= have0);

  ll ans = 0;
  ll extra = W;
  if(use0 < have0) extra = 0;

  sort(all(edges));
  for(auto [w,x,y] : edges) {
    if(uf.join(x,y)) {
      ans += w;
      uf_nonzero.join(x,y);
    }
    else if(!uf_nonzero.sameSet(x,y)) {
      extra = min(extra, w);
    }
  }

  debug(ans, W);

  cout << (ans + extra) << endl;
}