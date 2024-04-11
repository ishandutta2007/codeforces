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

map<pair<int, set<int>>, int> mex;
int CountMex(int l, set<int> done) {
  if (l == 0) {
    return 0;
  }
  if (mex.count({l, done})) {
    return mex[{l, done}];
  }
  set<int> zium;
  RE (k, l) {
    if (done.count(k)) { continue; }
    set<int> new_done = done;
    new_done.insert(k);
    zium.insert(CountMex(l - k, new_done));
  }
  REP (i, 10000) {
    if (zium.count(i)) { continue; }
    return mex[{l, done}] = i;
  }
}
int val[66];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  //~ RE (i, 60) {
    //~ val[i] = CountMex(i, {});
    //~ cerr<<"val["<<i<<"]="<<val[i]<<";\n";
    //~ //debug(val[i]);
  //~ }
  val[1]=1;
val[2]=1;
val[3]=2;
val[4]=2;
val[5]=2;
val[6]=3;
val[7]=3;
val[8]=3;
val[9]=3;
val[10]=4;
val[11]=4;
val[12]=4;
val[13]=4;
val[14]=4;
val[15]=5;
val[16]=5;
val[17]=5;
val[18]=5;
val[19]=5;
val[20]=5;
val[21]=6;
val[22]=6;
val[23]=6;
val[24]=6;
val[25]=6;
val[26]=6;
val[27]=6;
val[28]=7;
val[29]=7;
val[30]=7;
val[31]=7;
val[32]=7;
val[33]=7;
val[34]=7;
val[35]=7;
val[36]=8;
val[37]=8;
val[38]=8;
val[39]=8;
val[40]=8;
val[41]=8;
val[42]=8;
val[43]=8;
val[44]=8;
val[45]=9;
val[46]=9;
val[47]=9;
val[48]=9;
val[49]=9;
val[50]=9;
val[51]=9;
val[52]=9;
val[53]=9;
val[54]=9;
val[55]=10;
val[56]=10;
val[57]=10;
val[58]=10;
val[59]=10;
val[60]=10;

  int n;
  cin>>n;
  int xorr = 0;
  RE (i, n) {
    int s;
    cin>>s;
    xorr ^= val[s];
  }
  if (xorr == 0) {
    cout<<"YES\n";
  } else {
    cout<<"NO\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}