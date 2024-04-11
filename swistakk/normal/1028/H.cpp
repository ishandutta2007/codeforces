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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

const int N = 6e6 + 5;
int sito[N];
const int M = 5e5 + 5;
int r[M][15];
//int furthest[N][20];
int a[M];
int32_t furthest[N][15];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  FOR (i, 2, N - 1) {
    if (sito[i] == 0) {
      for (int j = 1; i * j < N; j++) {
        sito[i * j] = i;
      }
    }
  }
  
  int n;
  cin>>n;
  int q;
  cin>>q;
  //map<int, VI> furthest;
  RE (i, n) {
    REP (cand, 15) {
      r[i][cand] = n + 1;
    }
  }
  RE (i, n) {
    cin>>a[i];
    int tmp = a[i];
    VI ps;
    while (tmp > 1) {
      int p = sito[tmp];
      int ex = 0;
      while (tmp % p == 0) {
        tmp /= p;
        ex ^= 1;
      }
      if (ex) {
        ps.PB(p);
      }
    }
    debug(ps);
    REP (mask, 1 << SZ(ps)) {
      int ha = 1;
      REP (bit, SZ(ps)) {
        if (mask & (1 << bit)) {
          ha = ha * ps[bit];
        }
      }
      int lack = SZ(ps) - __builtin_popcount(mask);
      REP (cand, 8) {
        //assert(furthest[ha][cand] < i);
        //assert(cand + lack < 15);
        mini(r[furthest[ha][cand]][cand + lack], i);
      }
    }
    REP (mask, 1 << SZ(ps)) {
      int ha = 1;
      REP (bit, SZ(ps)) {
        if (mask & (1 << bit)) {
          ha = ha * ps[bit];
        }
      }
      int lack = SZ(ps) - __builtin_popcount(mask);
      furthest[ha][lack] = i;
    }
  }
  RE (i, n) {
    REP (cand, 15) {
      cerr<<r[i][cand]<<" ";
    }
    cerr<<endl;
  }
  FORD (i, n - 1, 1) {
    REP (cand, 15) {
      mini(r[i][cand], r[i + 1][cand]);
    }
  }
  
  RE (i, q) {
    int l, rr;
    cin>>l>>rr;
    REP (cand, N) {
      if (rr >= r[l][cand]) {
        cout<<cand<<"\n";
        break;
      }
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}