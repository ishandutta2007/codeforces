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
#define R(i,n) REP(i,n)
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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

// struct SAT{
//   int n,io;
//   vector<int> o, cz, co;
//   vector<vector<int>> d;
//   SAT(int _n):n(_n), io(0){
//     o.resize(2*n); d.resize(2*n);
//     cz.resize(2*n); co.resize(2*n);
//   }
//   void dfs(int nr){
//     if(cz[nr])return;
//     cz[nr]=1;
//     for(int ak:d[nr]) dfs(ak);
//     o[io++]=nr;
//   }
//   bool dfs2(int nr){
//     if(!cz[nr])
//       return !co[nr];
//     cz[nr]=0; co[nr]=1;
//     for(int ak:d[nr])
//       if(dfs2(ak))
//         return 1;
//     return 0;
//   }
//   vector<bool> licz(){
//     R(i,2*n) if(!cz[i]) dfs(i);
//     while(io--){
//       if(cz[o[io]]){
//         cz[o[io]] = co[o[io]] = 0;
//         if(dfs2(o[io]^1)) return {};
//       }
//     }
//     R(i,n) if(co[i*2] == co[i*2+1]) return {};
//     vector<bool> res; R(i,n) res.PB(co[i*2]);
//     return res;
//   }
//   void add(int a,bool nega,int b,bool negb){
//     a *= 2; a += nega; b *= 2; b += negb;
//     d[a^1].PB(b); d[b^1].PB(a);
//   }
// };
const int N = 1e6 + 5;
int u[N];
struct SSS{
  vector<vector<int>> d,drev; vector<int> ord,ss,cz;
  int is,n;
  SSS(int _n) : n(_n) {
    d.resize(n); drev.resize(n);
    cz.resize(n); ss.resize(n, -1);
  }
  void add_edge(int a,int b){
    d[a].PB(b); drev[b].PB(a);
  }
  void dfs(int nr){
    if(cz[nr]) return;
    cz[nr] = 1;
    for(int ak:d[nr])
      dfs(ak);
    ord.PB(nr);
  }
  void dfs2(int nr,int s){
    if(ss[nr] != -1) return;
    ss[nr] = s;
    for(int ak:drev[nr])
      dfs2(ak,s);
  }
  void licz(){
    R(i,n) dfs(i);
    is = 0;
    reverse(ALL(ord));
    for(int el:ord){
      if(ss[el] == -1){
        dfs2(el, is);
        is++;
      }
    }
  }
  vector<vector<int>> stworzgraf() {
    vector<vector<int>> res(is);
    R(i,n)for(int ak:d[i]){
      if(ss[i] != ss[ak])
        res[ss[i]].PB(ss[ak]);
    }
    for(auto &el:res){
      sort(ALL(el));
      el.resize(unique(ALL(el)) - el.begin());
    }
    return res;
  }
};
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m, h;
  cin>>n>>m>>h;
  RE (i, n) {
    cin>>u[i];
  }
//   SAT sat(n + 2);
//   RE (i, m) {
//     int a, b;
//     cin>>a>>b;
//     if (u[a] == u[b]) {
//       sat.add(a, 0, b, 0);
//       sat.add(a, 1, b, 1);
//     } else if ((u[a] + 1) % h == u[b]) {
//       sat.add(a, 1, b, 0);
//     } else if ((u[b] + 1) % h == u[a]) {
//       sat.add(a, 0, b, 1);
//     }
//   }
//   vector<bool> res = sat.licz();
//   if (res.empty()) {
//     cout<<"-1\n";
//     return 0;
//   }
//   cout<<SZ(res)<<endl;
//   RE (i, n) {
//     if (res[i]) {
//       cout<<i<<" ";
//     }
//   }
//   cout<<endl;
  SSS sss(n);
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    if ((u[a] + 1) % h == u[b]) {
      //slo[a].PB(b);
      sss.add_edge(a - 1, b - 1);
    }
    if ((u[b] + 1) % h == u[a]) {
      //slo[b].PB(a);
      sss.add_edge(b - 1, a - 1);
    }
  }
  int who_best = -1;
  sss.licz();
  VVI graf = sss.stworzgraf();
  vector<int> szs(n + 2);
  REP (i, n) {
    szs[sss.ss[i]]++;
  }
  REP (i, SZ(graf)) {
    if (graf[i].empty() && (who_best == -1 || szs[i] < szs[who_best])) {
      who_best = i;
    }
  }
  cout<<szs[who_best]<<endl;
  REP (i, n) {
    if (sss.ss[i] == who_best) {
      cout<<i+1<<" ";
    }
  }
  cout<<endl;
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}