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

map<int, int> mex;
int Go(int a) {
  if (a <= 1) {
    return a;
  }
  if (mex.count(a)) {
    return mex[a];
  }
  set<int> prvs;
  for (int k = 1; (1 << k) <= 2 * a; k++) {
    int cut = a >> k;
    debug(a, k, cut, (a & ((1 << (k - 1)) - 1)), cut | (a & ((1 << (k - 1)) - 1)));
    prvs.insert(Go(cut | (a & ((1 << (k - 1)) - 1))));
  }
  REP (i, 1e9) {
    if (prvs.count(i) == 0) {
      return mex[a] = i;
    }
  }
}
  

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  map<int, int> exps;
  int n;
  cin>>n;
  RE (_, n) {
    int a;
    cin>>a;
    for (int i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        int ex = 0;
        while (a % i == 0) {
          ex++;
          a /= i;
        }
        exps[i] |= 1ll << (ex - 1);
      }
    }
    if (a > 1) {
      exps[a] |= 1;
    }
//     if (a > 1) {
//       maxi(exps[a], 1ll);
//     }
  }
  debug(Go(3), Go(5), Go(9));
  //debug(Go((1 << 30) - 21233545));
  int xorr = 0;
  for (auto x : exps) {
    debug(x.nd);
    xorr ^= Go(x.nd);
  }
  if (xorr == 0) {
    cout<<"Arpa\n";
  } else {
    cout<<"Mojtaba\n";
  }
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}