#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
  template<class T> void ResizeVec(T&, vector<int>) {}
  template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
    vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
    for (T& v : vec) { ResizeVec(v, sz); }
  }
  typedef Triple<int, int, int> TIII;
  template<class A, class B, class C>
  ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
  template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  
  struct LCA {
    LCA(const vector<vector<int> >& their_slo, int root = 1) {
      M = 1;
      while (M <= 2 * (int)their_slo.size()) {
        M *= 2;
      }
      my_slo.resize(M);
      REP (i, (int)their_slo.size()) {
        for (auto nei : their_slo[i]) {
          my_slo[i].PB(nei);
        }
      }
      drz.resize(2 * M + 5);
      pre.resize(M);
      inv.resize(M);
      vis.resize(M);
      ind.resize(M);
      dep.resize(M);
      d=1;
      akt=1;
      dfs(root);
      for(int i=M-1; i>=1; i--)
      {
        drz[i]=min(drz[2*i], drz[2*i+1]);
      }
    }
    int M;
    vector<int> drz;
    vector<int> pre;
    vector<int> inv;
    vector<int> vis;
    vector<int> ind;
    vector<int> dep;
    vector<vector<int> > my_slo;
    int d;
    int akt;
    
    int Lca(int a, int b) // pobiera a i b, a zwraca ich lca (przy ukorzenieniu w jedynce (ale to mozna zmienic zapuszczajac skad inad dfsa) )
    {
      a=pre[a];
      b=pre[b];
      int w;
      w=czyt(min(ind[a], ind[b]), max(ind[a], ind[b]) );
      return inv[w];
    }
    
    int Dis(int a, int b) {
      return dep[a] + dep[b] - 2 * dep[Lca(a, b)];
    }
    
  private:
    int czyt(int a, int b)
    {
      a+=M-1;
      b+=M-1;
      int mini=M;
      mini=min(mini, drz[a]);
      mini=min(mini, drz[b]);
      while(a/2 != b/2)
      {
        if(a%2==0)
        {
          mini=min(mini, drz[a+1]);
        }
        if(b%2==1)
        {
          mini=min(mini, drz[b-1]);
        }
        a/=2;
        b/=2;
      }
      return mini;
    }
    void dfs(int v)
    {
      vis[v]=1;
      pre[v]=d;
      inv[d]=v;
      d++;
      drz[akt+M-1]=pre[v];
      ind[pre[v]]=akt;
      akt++;
      for (int nei : my_slo[v]) {
        if (vis[nei]) {
          continue;
        }
        dep[nei] = dep[v] + 1;
        dfs(nei);
        drz[akt+M-1]=pre[v];
        ind[pre[v]]=akt;
        akt++;
      }
    }
  }; 
  const int N = 3e5 + 5;
  // int kl[N];
  // int kp[N];
  // int aktc[N];
  // int l[N];
  // int r[N];
  //VI slo[N];
  VVI slo;
  struct Node {
    int32_t li, ri;
    int64_t xi;
  };
  vector<Node> nodes;
  VI roots;
  int d;
  int pre[N];
  int sz[N];
  void Dfs(int v) {
    pre[v] = ++d;
    sz[v] = 1;
    for (auto nei : slo[v]) {
      if (pre[nei]) { continue; }
      Dfs(nei);
      sz[v] += sz[nei];
    }
  }
  // #ifdef LOCAL
  // const int M = 1 << 3;
  // #else
  const int M = 1 << 19;
  //#endif
  int phase;
  int Add(int bl, int br, int l, int r, int64_t x, int id) {
    //if (bl == 1 && br == M) {
    //debug(bl, br, l, r, x, id, phase);
    if (bl > r || br < l) { return id; }
    if (l <= bl && br <= r) {
      nodes.PB({nodes[id].li, nodes[id].ri, nodes[id].xi ^ x});
      //debug(SZ(nodes) - 1, nodes[id].xi ^ x);
      return SZ(nodes) - 1;
    }
    int m = (bl + br) / 2;
    nodes.PB({Add(bl, m, l, r, x, nodes[id].li), Add(m + 1, br, l, r, x, nodes[id].ri), nodes[id].xi});
    return SZ(nodes) - 1;
  }
  int guy;
  int64_t Read(int bl, int br, int id) {
    //debug(bl, br, guy, id, nodes[id].xi);
    //   assert(id != -1);
    //   if (nodes[id].xi == -1) {
    //     debug(bl, br, guy, id);
    //   }
    //   //if (bl > r || br < l) { return 0; }
    //   assert(nodes[id].xi != -1);
    if (bl == br) { return nodes[id].xi; }
    int m = (bl + br) / 2;
    if (guy <= m) {
      return nodes[id].xi ^ Read(bl, m, nodes[id].li);
    } else {
      return nodes[id].xi ^ Read(m + 1, br, nodes[id].ri);
    }
  }
  
  int64_t rdd[N];
  int a[N];
  int32_t main() {
    
    ios_base::sync_with_stdio(0);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
    cin.tie(0);
    //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
    
    
    int n, q;
    
    cin>>n>>q;
    
    RE (i, n) {
      rdd[i] = (1ll * rand() % (1 << 30)) + (1ll * rand() % (1 << 30)) * (1 << 30);
      //debug(rdd[i]);
    }
    VVI by_a(n + 2);
    RE (i, n) {
      cin>>a[i];
      by_a[a[i]].PB(i);
    }
    nodes.PB({-1, -1, -1});
    RE (i, M - 1) {
      nodes.PB({2 * i, 2 * i + 1, 0});
    }
    FOR (i, M, 2 * M - 1) {
      nodes.PB({-1, -1, 0});
    }
    roots.PB(1);
    
    slo.resize(n + 2);
    RE (i, n - 1) {
      int aa, bb;
      cin>>aa>>bb;
      slo[aa].PB(bb);
      slo[bb].PB(aa);
    }
    
    Dfs(1);
    int root = 1;
    RE (i, n) {
      phase = i;
      for (auto v : by_a[i]) {
        root = Add(1, M, pre[v], pre[v] + sz[v] - 1, rdd[i], root);
      }
      roots.PB(root);
    }
    debug(1. * clock() / CLOCKS_PER_SEC);
    //debug(roots);
    LCA lca(slo);
    function<int64_t(int, int, int)> Ask = [&](int u, int id1, int id2) {
      guy = pre[u] - 1;
      int64_t hhh = nodes[id1].xi ^ nodes[id2].xi;
      FORD (bit, 18, 0) {
        if (guy & (1 << bit)) {
          id1 = nodes[id1].ri;
          id2 = nodes[id2].ri;
        } else {
          id1 = nodes[id1].li;
          id2 = nodes[id2].li;
        }
        if (id1 == id2) { return hhh; }
        hhh ^= nodes[id1].xi ^ nodes[id2].xi;
      }
      return hhh;
    };
    function<int64_t(int, int, int, int, int)> Eval = [&](int u, int v, int l, int r, int ziom) {
      
      int64_t b = Ask(u, roots[l - 1], roots[r]);
      int64_t dd = Ask(v, roots[l - 1], roots[r]);
      //debug(u, v, l, r, v, b, c, dd, e);
      int64_t lel = b ^ dd;
      if (l <= a[ziom] && a[ziom] <= r) {
        return rdd[a[ziom]] ^ lel;
      } else {
        return lel;
      }
    };
    RE (i, q) {
      //if (i == 2.5e5) { return 0; }
      int u, v, l, r;
      cin>>u>>v>>l>>r;
      int L = lca.Lca(u, v);
      int64_t control = Eval(u, v, l, r, L);
      //debug(u, v, l, r, control);
      if (control == 0) {
        cout<<"-1\n";
        continue;
      }
      while (l < r) {
        int c = (l + r) / 2;
        if (Eval(u, v, l, c, L)) {
          r = c;
        } else {
          l = c + 1;
        }
      }
      cout<<l<<"\n";
      //cin>>u[i]>>v[i]>>l[i]>>r[i];
      //int L = lca.Lca(u[i], v[i]);
      
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
  }