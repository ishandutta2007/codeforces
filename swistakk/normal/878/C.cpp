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

struct CC {
  VI fir, sec;
  int sz;
  bool operator<(const CC& oth) const {
    return fir < oth.fir;
  }
};
int k;
CC Merge(CC a, CC b) {
  a.sz += b.sz;
  REP (i, k) {
    mini(a.fir[i], b.fir[i]);
    maxi(a.sec[i], b.sec[i]);
  }
  return a;
}
  
bool WinWithAny(VI& strs, CC cc) {
  REP (i, k) {
    if (strs[i] > cc.fir[i]) {
      return true;
    }
  }
  return false;
}
bool LoseWithAny(VI& strs, CC cc) {
  REP (i, k) {
    if (strs[i] < cc.sec[i]) {
      return true;
    }
  }
  return false;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n>>k;
  set<CC> ccs;
  RE (i, n) {
    VI strs;
    RE (j, k) {
      int a;
      cin>>a;
      strs.PB(a);
    }
    CC me{strs, strs, 1};
    if (i == 1) {
      ccs.insert({strs, strs, 1});
    } else {
      while (1) {
        auto nxt = ccs.lower_bound(me);
        if (nxt == ccs.end()) {
          break;
        }
        if (WinWithAny(strs, *nxt)) {
          me = Merge(me, *nxt);
          ccs.erase(nxt);
        } else {
          break;
        }
      }
      while (1) {
        auto prv = ccs.lower_bound(me);
        if (prv == ccs.begin()) {
          break;
        }
        prv--;
        if (LoseWithAny(strs, *prv)) {
          me = Merge(me, *prv);
          ccs.erase(prv);
        } else {
          break;
        }
      }
      ccs.insert(me);
    }
    auto last = prev(ccs.end());
    cout<<last->sz<<"\n";
  }
      
      

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}