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
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
using namespace std;
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
const int N = 1e6 + 5;
int pots[N + 5];
const int P = 1e9 + 7;
vector<TIII> slo[N];
int sz[N];
int dfsSz(int v) {
  sz[v] = 1;
  for (auto e : slo[v]) {
    int nei = e.st;
    if (sz[nei]) { continue; }
    sz[v] += dfsSz(nei);
  }
  return sz[v];
}
int n, k;
int begs[N], endss[N];
int res;
VI occ[N];
bool cur[N][22];
VI coll[22];
void Add(int x, int v, int log) {
  if (cur[x + 1][log]) {
    begs[v]--;
  } else {
    if (x + 1 <= k) {
      endss[v]++;
    }
  }
  if (cur[x - 1][log]) {
    endss[v]--;
  } else {
    if (x > 1) {
      begs[v]++;
    }
  }
  coll[log].PB(x);
  cur[x][log] = 1;
}
void DfsDp(int v, int par, int log) {
  cerr<<"From "<<par<<" to "<<v<<endl;
  int larg_sz = -1;
  int wh = -1;
  for (auto e : slo[v]) {
    int nei = e.st;
    if (nei == par) { continue; }
    if (sz[nei] > larg_sz) {
      wh = nei;
      larg_sz = sz[nei];
    }
  }
  if (wh != -1) {
    DfsDp(wh, v, log);
    begs[v] = begs[wh];
    endss[v] = endss[wh]; 
  }
  for (auto x : occ[v]) {
    Add(x, v, log);
  }
  for (auto e : slo[v]) {
    int nei = e.st;
    if (nei == par || nei == wh) { continue; }
    DfsDp(nei, v, log + 1);
    for (auto x : coll[log + 1]) {
      Add(x, v, log);
      cur[x][log + 1] = 0; 
    }
    coll[log + 1].clear();
  }
  for (auto e : slo[v]) {
    int nei = e.st;
    if (nei == par || e.nd == 0) { continue; }
    if (e.rd == 0) {
      res += pots[begs[nei]];
      cerr<<"Add 2^"<<begs[nei]<<" "<<v<<" "<<nei<<endl;
    } else {
      res += pots[endss[nei]];
      cerr<<"Add 2^"<<endss[nei]<<" "<<v<<" "<<nei<<endl;
    }
  }
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  pots[0] = 1;
  RE (i, N) {
    pots[i] = 2 * pots[i - 1] % P;
  }
  cin>>n;
  res = P;
  RE (i, n - 1) {
    make3(int, a, b, c);
    slo[a].PB({b, c, 1});
    slo[b].PB({a, c, c ^ 1});
    cerr<<a<<"<->"<<b<<endl;
    res -= c;
  }
  cin>>k;
  occ[1].PB(1);
  RE (i, k) {
    make(int, c);
    occ[c].PB(i + 1);
  }
  k++;
  dfsSz(1);
  DfsDp(1, -1, 0);
  cout<<res % P << endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}