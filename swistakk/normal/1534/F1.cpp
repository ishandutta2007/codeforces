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

const int N = 1e6 + 5;
vector<int> slo[N];
vector<int> trans[N];
void AddEdge(int a, int b) {
  slo[a].PB(b);
  trans[b].PB(a);
  debug(a, b);
}
bool vis[N];
int ktop[N];
int ss[N];
int d;
int n, m;
int licz;
vector<int> tmp[N];
vector<int> nowy[N];
int czybyl[N];
void dfs1(int w) // liczy postorder^{-1}, tzn jak post[v]=d, to ktop[d]=w
{
  vis[w]=1;
  for(int g=0; g<(int)slo[w].size(); g++)
  {
    if(vis[slo[w][g]]==0)
    {
      dfs1(slo[w][g]);
    }
  }
  d++;
  ktop[d]=w;
}
void dfs2(int v) // lazi po jednej silnie spojnej
{
  ss[v]=licz;
  for(int i=0; i<(int)trans[v].size(); i++)
  {
    if(ss[trans[v][i]]==0)
    {
      dfs2(trans[v][i]);
    }
  }
}
void podziel() // przypisuje wierzcholkom numer ich silnie spojnej
{
  for(int i=1; i<=n; i++)
  {
    if(vis[i]==0)
    {
      dfs1(i);
    }
  }
  licz=0;
  for(int i=n; i>0; i--) // idzie od najwiekszych numerow postorder
  {
    if(ss[ktop[i]]==0) // jezeli ktop[i] nie jest przydzielony do zadnej, to pomaluj jego silnie spojna
    {
      licz++;
      dfs2(ktop[i]);
    }
  }
}
void stworzgraf() // jezeli potrzebne jest stworzenie grafu silnie spojnych, to bedzie on w tablicy wektorow "nowy"
{
  for(int i=1; i<=n; i++)
  {
    for(int j=0; j<(int)slo[i].size(); j++)
    {
      int s1=ss[i];
      int s2=ss[slo[i][j]];
      if(s1!=s2)
      {
        tmp[s1].push_back(s2);
      }
    }
  }
  for(int i=1; i<=licz; i++)
  {
    for(int j=0; j<(int)tmp[i].size(); j++)
    {
      if(czybyl[tmp[i][j]]!=i)
      {
        czybyl[tmp[i][j]]=i;
        nowy[i].push_back(tmp[i][j]);
      }
    }
  }
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int r, c;
  cin>>r>>c;
  vector<vector<char>> b(r + 2, vector<char>(c + 2));
  VVI id(r + 2, VI(c + 2));
  int nxt = 1;
  RE (i, r) {
    RE (j, c) {
      cin>>b[i][j];
      if (b[i][j] == '#') {
        id[i][j] = nxt++;
      }
    }
  }
  RE (j, c) {
    int last_left = -1, last_here = -1, last_right = -1;
    FORD (i, r, 1) {
      if (b[i][j - 1] == '#') {
        last_left = i;
      }
      if (b[i][j + 1] == '#') {
        last_right = i;
      }
      if (b[i][j] == '.') { continue; }
      if (b[i - 1][j] == '#') {
        AddEdge(id[i][j], id[i - 1][j]);
      }
      if (last_here != -1) {
        AddEdge(id[i][j], id[last_here][j]);
      }
      last_here = i;
      if (last_left != -1) {
        AddEdge(id[i][j], id[last_left][j - 1]);
      }
      if (last_right != -1) {
        AddEdge(id[i][j], id[last_right][j + 1]);
      }
    }
  }
  n = nxt - 1;
  podziel();
  stworzgraf();
  int res = 0;
  VI is_in(licz + 2);
  RE (i, licz) {
    debug(nowy[i]);
    for (auto nei : nowy[i]) {
      is_in[nei] = 1;
    }
  }
  debug(licz);
  RE (i, licz) {
    if (is_in[i] == 0) {
      res++;
    }
  }
  cout<<res<<endl;
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}