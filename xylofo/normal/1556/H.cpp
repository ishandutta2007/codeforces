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


template<class M1, class M2> struct MatroidIsec {
  int n; // max weight matroid intersection
  ll cost = 0, inf = 1e18;
  vi iset; // iset[x] = true if x in indep set
  vector<ll> s1, s2; // split weight/potential functions
  M1 m1; M2 m2;
  MatroidIsec(M1 m1, M2 m2, vector<ll> w)
    : n(sz(w)), iset(n), s1(w), s2(n+1), m1(m1), m2(m2) {
      iset.push_back(1); // for dummy source/sink node
      s1.push_back(0);
    }
  vi nei(auto& m, int x) {
    vi res;
    m.clear(); // possible speed-up: precompute circuits
    rep(y,0,n) if(y != x && iset[y]) m.add(y);
    rep(y,0,n) if(!iset[y] && m.check(y)) res.push_back(y);
    return res;
  }
  bool augment() {
    vector<vector<pair<int,ll>>> g(n+1);
    rep(x,0,n+1) if(iset[x]) { // build exchange graph
      for(int y : nei(m1,x)) g[y].emplace_back(x, s1[x]-s1[y]);
      for(int y : nei(m2,x)) g[x].emplace_back(y, s2[x]-s2[y]);
    } // neg edges are either incident to n or unreachable
    int ed = 0;
    rep(i,0,sz(g)) ed += sz(g[i]);

    vector<ll> dist(n+1, inf);
    vi dad(n+1, -1);
    priority_queue<pair<ll,int> > q;
    q.emplace(0,n); // when unweighted, consider replacing
    while(!q.empty()) { // dijkstra with bfs
      auto [d,x] = q.top();
      q.pop();
      d = -d;
      if(x == n && dad[n] != -1) continue;
      if(d > dist[x]) continue;
      for(auto [y,w] : g[x]) if(dist[y] > d + w) {
        dist[y] = d + w;
        dad[y] = x;
        q.emplace(-dist[y], y);
      }
    }

    if(dad[n] == -1) return false;
    cost -= dist[n];
    rep(x,0,n) if(dad[x] != -1) {
      s1[x] -= dist[x];
      s2[x] += dist[x];
    }
    for(int x = dad[n]; x != n; x = dad[x]) iset[x] ^= 1;
    return true;
  }
  pair<int,ll> solve() { // (sz, cost)
    // >= 2*speedup for unweighted:
    // rep(i,0,n) if(m1.check(i) && m2.check(i))
    //   m1.add(i), m2.add(i), iset[i] = 1;
    while(augment());
    return {count(all(iset)-1,1), cost};
  }
};


struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  void clear() { fill(all(e),-1); }
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

struct ColorMat { // <= of each color
  vi cnt, col, mx;
  vi iset;
  ColorMat(vi col, vi mx) : cnt(sz(mx)), col(col), mx(mx), iset(sz(col)) {
    clear();
  }
  bool check(int x) { return cnt[col[x]]+1 <= mx[col[x]]; }
  void add(int x) {
    iset[x] = 1;
    //assert(check(x));
    cnt[col[x]]++;
  }
  void clear() {
    fill(all(cnt), 0);
  }
};
struct GraphMat { // acyclic
  UF uf;
  vector<pii> e, extra;
  GraphMat(int n, vector<pii> e, vector<pii> extra) : uf(n), e(e), extra(extra) {
    clear();
  }
  bool check(int x) { return !uf.sameSet(e[x].first, e[x].second); }
  void add(int x) {
    //assert(check(x));
    uf.join(e[x].first, e[x].second);
  }
  void clear() {
    //uf = UF(sz(uf.e));
    uf.clear();
    for(auto [a,b] : extra) uf.join(a,b);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  vi d(k+1,n+10);
  rep(i,0,k) cin>>d[i];

  vi cols;
  vector<pii> edges;
  vector<ll> weights;
  vector<tuple<int,int,int>> special;
  vector<tuple<int,int,int>> maybe;

  rep(i,0,n) {
    rep(j,i+1,n) {
      int w;
      cin>>w;
      //w = rand()%2+1;
      if(j < k) special.emplace_back(w,i,j);
      else if(i < k) {
        weights.emplace_back(-w);
        edges.emplace_back(i,j);
        cols.emplace_back(i);
      }
      else maybe.emplace_back(w,i,j);
    }
  }
  sort(all(maybe));
  {
    UF uf(n);
    for(auto [w,a,b] : maybe) {
      if(uf.join(a,b)) {
        weights.emplace_back(-w);
        edges.emplace_back(a,b);
        cols.emplace_back(k);
      }
    }
  }

  //debug('%');
  //rep(i,0,sz(weights)) {
  //  debug(i, weights[i], cols[i], edges[i]);
  //}
  //debug();
  //debug(special);
  //debug('%');
  //

  int isec_cnt = 0;
  ll ans = 1e18;
  assert(sz(special) <= 10);
  rep(msk,0,1<<sz(special)) {
    UF uf(n);
    vector<pii> extra;
    ll cur = 0;
    bool ok = true;
    int need = n-1;
    vi mx = d;
    rep(i,0,sz(special)) if(msk>>i&1) {
      auto [w,a,b] = special[i];
      cur += w;
      if(!uf.join(a,b)) ok = false;
      extra.emplace_back(a,b);
      --need;
      --mx[a]; --mx[b];
      if(mx[a] < 0 || mx[b] < 0) ok = false;
    }
    if(!ok) continue;

    //debug(); debug(extra); debug(mx); debug(cur);

    ColorMat m1(cols,mx);
    GraphMat m2(n,edges,extra);
    MatroidIsec isec(m2,m1,weights);
    auto [t, cost] = isec.solve();
    assert(t <= need);
    if(t == need) ans = min(ans, cur - cost);

    //debug(t, need, cost);
    ++isec_cnt;
  }
  debug(isec_cnt);

  cout << ans << endl;
}