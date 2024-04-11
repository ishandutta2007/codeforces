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
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
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

struct Frac {
  int num, den;
  bool operator<(const Frac& other) const {
    return num * other.den > other.num * den;
  }
};
  
map<Frac, vector<PII>> mapka;
typedef pair<LD, LD> PLD;
const int N = 2e5 + 5;
int p[N], t[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>p[i];
  }
  int T = 0;
  RE (i, n) {
    cin>>t[i];
    T += t[i];
  }
  RE (i, n) {
    mapka[{p[i], t[i]}].PB({p[i], t[i]});
  }
  for (auto& vvv : mapka) {
    sort(ALL(vvv.nd));
  }
  
  LD kl = 0, kp = 1, faj = 0;
  while (kp - kl > 1e-7) {
    LD aktc = (kl + kp) / 2;
    int so_far = 0;
    set<pair<int, LD>> max_scores;
    bool can_par = 0;
    for (auto& vvv : mapka) {
      auto& v = vvv.nd;
      debug(v);
      int t_here = 0;
      for (auto& el : v) {
        t_here += el.nd;
      }
      for (auto& el : v) {
        LD max_score = el.st * (1 - aktc * (so_far + el.nd) / T);
        LD min_score = el.st * (1 - aktc * (so_far + t_here) / T);
        debug(max_score, min_score, el.st, el.nd);
        auto it_max = max_scores.upper_bound({el.st, -1});
        if (it_max != max_scores.begin()) {
          it_max--;
          if (it_max->nd > min_score) {
            can_par = 1;
          }
        }
        max_scores.insert({el.st, max_score});
      }
      so_far += t_here;
    }
    if (can_par) {
      kp = aktc;
    } else {
      faj = aktc;
      kl = aktc;
    }
  }
  cout<<faj<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}