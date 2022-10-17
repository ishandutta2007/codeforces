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


template <bool VALS_EDGES> struct HLD {
  int N, tim = 0;
  vector<vi> adj;
  vi par, siz, depth, rt, pos;
  HLD(vector<vi> adj_)
    : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
    rt(N),pos(N) { dfsSz(0); dfsHld(0); }
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
  template <class B> int process(int u, int v, B op) {
    for (; rt[u] != rt[v]; v = par[rt[v]]) {
      if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
      op(pos[rt[v]], pos[v] + 1);
    }
    if (depth[u] > depth[v]) swap(u, v);
    op(pos[u] + VALS_EDGES, pos[v] + 1);
    return u;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  ++n;
  vi a(q), b(q), w(q), ans(q);
  rep(i,0,q) {
    cin>>a[i]>>b[i]>>w[i];
  }

  const int BAD = 0;
  const int TREE = 1;
  const int CYC = 2;

  vector<vi> g(n); // tree edges
  UF uf(n);
  rep(i,0,q) if(uf.join(a[i], b[i])) {
    ans[i] = TREE;
    g[a[i]].emplace_back(b[i]);
    g[b[i]].emplace_back(a[i]);
  }
  rep(x,1,n) if(uf.join(0,x)) {
    g[0].emplace_back(x);
    g[x].emplace_back(0);
  }

  HLD<true> hld(g);
  vi pos_xor(n);
  rep(i,0,q) if(ans[i] == TREE) {
    hld.process(a[i],b[i],[&](int l, int r){
        if(l == r) return;
        assert(r == l+1);
        pos_xor[l] ^= w[i];
    });
  }
  vi pref_xor(n+1);
  rep(i,0,n) pref_xor[i+1] = (pref_xor[i] ^ pos_xor[i]);

  auto path_xor = [&](int x, int y) {
    ll ans = 0;
    hld.process(x,y,[&](int l, int r){
        ans ^= (pref_xor[r]^pref_xor[l]);
    });
    return ans;
  };

  set<int> bad;
  auto mark_bad = [&](int x, int y) {
    hld.process(x,y,[&](int l, int r){
        rep(z,l,r) {
          assert(!bad.count(z));
          bad.emplace(z);
        }
    });
  };
  auto is_bad = [&](int x, int y) {
    bool good = true;
    hld.process(x,y,[&](int l, int r){
        auto it = bad.lower_bound(l);
        if(it != end(bad) && *it < r) good = false;
    });
    return !good;
  };

  rep(i,0,q) if(ans[i] != TREE) {
    if(1 != (w[i] ^ path_xor(a[i], b[i]))) continue;
    if((w[i] ^ path_xor(a[i], b[i])) != 1) continue;
    if(is_bad(a[i],b[i])) continue;
    mark_bad(a[i],b[i]);
    ans[i] = CYC;
  }

  debug(ans);

  rep(i,0,q) cout << (ans[i] ? "YES" : "NO") << "\n";
}