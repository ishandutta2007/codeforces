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

//VI Rec(unordered_set<int> v, int mod) {
VI Rec(vector<int> v, int mod) {
//   REP (i, SZ(v)) {
//     while (v[i] == 0) {
//       swap(v[i], v.back());
//       v.pop_back();
//       i--;
//     }
//   }
  sort(ALL(v));
  v.resize(unique(ALL(v)) - v.begin());
//   if (v.count(0)) {
//     v.erase(0);
//   }
  if (v.empty()) {
    return {};
  }
  if (mod > 1 << 18) {
    assert(SZ(v) == 1);
    return v;
  }
  int any = 0;
  for (auto x : v) {
    if (x % mod) {
      any = 1;
    }
  }
  if (any == 0) {
    return Rec(v, 2 * mod);
  } else {
    VI cand{-mod / 2, mod / 2};
    VVI cands;
    for (auto c : cand) {
      vector<int> nv;
      //unordered_set<int> nv;
      for (auto x : v) {
        if (x % mod) {
          if (x != c) {
            nv.PB(x - c);
            //nv.insert(x - c);
          }
        } else {
          nv.PB(x);
          //nv.insert(x);
        }
      }
      cands.PB(Rec(nv, 2 * mod));
      cands.back().PB(c);
    }
    if (SZ(cands[0]) < SZ(cands[1])) {
      return cands[0];
    } else {
      return cands[1];
    }
  }
}
int realRand() {
  return rand() + ((1ll * rand()) << 16);
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
#define LOCAL
  int n;
#ifdef LOCAL
  cin>>n;
#else
  n = 1e5;
#endif
  int R = 1e5;
  //unordered_set<int> start;
  VI start;
  RE (i, n) {
    int a;
#ifdef LOCAL
    cin>>a;
#else
    a = realRand() % (2 * R) - R;
#endif
    if (a) {
      start.PB(a);
    }
    //start.insert(a);
  }
  VI best = Rec(start, 2);
  cout<<SZ(best)<<endl;
  for (auto x : best) {
    cout<<x<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}