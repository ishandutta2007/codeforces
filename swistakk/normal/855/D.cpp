#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
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
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
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

const int N = 1e5 + 5;
int is_root[N];

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

VVI slo;
int cnt1[N], cnt2[N], dep[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  slo.resize(n + 5);
  RE (i, n) {
    int par, typ;
    cin>>par>>typ;
    if (par == -1) {
      par = n + 1;
      typ = 2;
    }
    slo[par].PB(i);
    slo[i].PB(par);
    cnt1[i] = cnt1[par] + (typ == 0);
    cnt2[i] = cnt2[par] + (typ == 1);
    dep[i] = dep[par] + 1; 
  }
  LCA lca(slo, n + 1);
  int q;
  cin>>q;
  RE (i, q) {
    int typ, u, v;
    cin>>typ>>u>>v;
    if (u == v) {
      cout<<"NO\n";
      continue;
    }
    int L = lca.Lca(u, v);
    if (typ == 1) {
      if (L == u && dep[v] - dep[u] == cnt1[v] - cnt1[u]) {
        cout<<"YES\n";
      } else {
        cout<<"NO\n";
      }
    } else {
      if (L != v && dep[v] - dep[L] == cnt2[v] - cnt2[L] && dep[u] - dep[L] == cnt1[u] - cnt1[L]) {
        cout<<"YES\n";
      } else {
        cout<<"NO\n";
      }
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}