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
    while (M <= 2 * SZ(their_slo)) {
      M *= 2;
    }
    my_slo.resize(M);
    REP (i, SZ(their_slo)) {
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
 
const int N = 2e5 + 5;
int dep[N];
int hei[N];
int par[N];
int vis[N];
VVI slo;
int furthest;
int dis0[N], dis1[N], dis2[N];
void Dfs(int v) {
  vis[v] = 1;
  if (dis0[v] > dis0[furthest]) {
    furthest = v;
  }
  hei[v] = 0;
  for (auto nei : slo[v]) {
    if (vis[nei]) { continue; }
    dis0[nei] = dis0[v] + 1;
    par[nei] = v;
    Dfs(nei);
    maxi(hei[v], hei[nei] + 1);
  }
}
int32_t main() {
 
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, k;
  cin>>n>>k;
  slo.resize(n + 2);
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  LCA lca(slo);
  Dfs(1);
  int e1 = furthest;
  RE (i, n) {
    vis[i] = 0;
    dis0[i] = 0;
  }
  Dfs(e1);
  RE (i, n) {
    vis[i] = 0;
    dis1[i] = dis0[i];
    dis0[i] = 0;
  }
  int e2 = furthest;
  Dfs(e2);
  RE (i, n) {
    dis2[i] = dis0[i];
    vis[i] = 0;
    dis0[i] = 0;
  }
  Dfs(e1);
  int diam = dis1[e2];
  if (k == 2 || diam < k - 1) {
    cout<<"Yes\n";
    RE (i, n) {
      cout<<1 + (dis1[i] % 2)<<" ";
    }
    cout<<endl;
    return 0;
  }
  VI res(n + 2);
  RE (i, n) {
    int is_on_diam = ((dis1[i] + dis2[i]) == diam);
    VI sons;
    for (auto son : slo[i]) {
      if (par[i] == son) { continue; }
      sons.PB(hei[son] + 1);
    }
    sort(ALL(sons), greater<int>());
    int third = 0;
    if (SZ(sons) <= is_on_diam) {
      third = 0;
    } else {
      third = sons[is_on_diam];
    }
    if (!is_on_diam && min(dis1[i], dis2[i]) + 1 >= k) {
      cout<<"No\n";
      return 0;
    }
    int to_diam = (dis1[i] + dis2[i] - diam) / 2;
    if (dis2[i] <= dis1[i]) {
      res[i] = dis1[i] % k;
    } else {
      res[i] = (dis1[i] - 2 * to_diam) % k;
    }
  }
  cout<<"Yes\n";
  RE (i, n) {
    cout<<res[i] + 1<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}