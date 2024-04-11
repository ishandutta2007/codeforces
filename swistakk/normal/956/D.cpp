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

int phase;
struct Frac {
  int num, den, id;
  bool operator<(const Frac& oth) const {
    int heh1 = num * oth.den;
    int heh2 = oth.num * den;
    int ch1 = (den < 0) ^ (oth.den < 0);
    if (heh1 != heh2) {
      return (heh1 < heh2) ^ ch1;
    }
    if (phase == 0) {
      return (den > oth.den) ^ ch1;
    }
    return (den < oth.den) ^ ch1;
  }
};
const int N = 1e6 + 5;
int drz[N];
int Magic(int n) {
  return n - (n & (n - 1));
}
int Sum(int x) {
  int res = 0;
  while (x < N) {
    res += drz[x];
    x += Magic(x);
  }
  return res;
}
void Add(int x, int r) {
  while (x) {
    drz[x] += r;
    x -= Magic(x);
  }
}

int x[N];
int v[N];

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, w;
  cin>>n>>w;
  vector<Frac> fir, sec;
  RE (i, n) {
    cin>>x[i]>>v[i];
    v[i] *= -1; 
    debug(i, x[i], v[i]);
    fir.PB({x[i], v[i] - w, i});
    sec.PB({x[i], v[i] + w, i});
  }
  sort(ALL(fir));
  phase = 1;
  sort(ALL(sec));
  VI my_ind(n + 2);
  REP (i, n) {
    my_ind[fir[i].id] = i + 1;
    debug(i, fir[i].id, fir[i].num, fir[i].den);
  }
  int res = 0;
  REP (i, n) {
    debug(i, sec[i].id, sec[i].num, sec[i].den);
    res += Sum(my_ind[sec[i].id]);
    Add(my_ind[sec[i].id], 1);
  }
  cout<<res<<endl;
//   int res = n * (n - 1) / 2;
//   REP (tr, 2) {
//     vector<Frac> earliest;
//     RE (i, n) {
//       if (x[i] < 0) {
//         earliest.PB({-x[i], -v[i] + w});
//       }
//     }
//     sort(ALL(earliest));
//     vector<Frac> pos;
//     RE (i, n) {
//       if (x[i] > 0) {
//         pos.PB({x[i], v[i]});
//         Frac latest = {x[i], v[i] - w};
//         int faj = -1, kl = 0, kp = SZ(earliest) - 1;
//         while (kl <= kp) {
//           int aktc = (kl + kp) / 2;
//           if (earliest[aktc] > latest) {
//             faj = aktc;
//             kl = aktc + 1;
//           } else {
//             kp = aktc - 1;
//           }
//         }
//         // faj - pierwszy co jest zle
//         res -= (SZ(earliest) - faj + 1);
//       }
//     }
//     
//     
//     
//     RE (i, n) {
//       x[i] *= -1;
//       v[i] *= -1;
//     }
//   }
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}