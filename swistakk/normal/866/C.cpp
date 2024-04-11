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

const int S = 6e3 + 5;
const int N = 55;
int f[N], s[N];
LD p[N];
LD E[N][S];
const int kInf = 1e18 + 5;
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(2);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, R;
  cin>>n>>R;
  RE (i, n) {
    cin>>f[i]>>s[i]>>p[i];
    p[i] /= 100;
  }
  REP (i, S) {
    E[n + 1][i] = 0; // lol
  }
  // E[i][j] - oczekiwany czas sukcesu, jezeli jestem w itym i mam j sekund zapasu
  LD kl = 0, kp = 1e16;
  REP (tr, 100) {
    LD aktc = (kl + kp) / 2;
    debug(aktc, "beg");
    FORD (i, n, 1) {
      auto Get = [&](int a, int b) {
        if (b < 0) {
          return aktc;
        }
        return E[a][b];
      };
      REP (t, S - 111) {
        LD cand = p[i] * (f[i] + Get(i + 1, t - f[i])) + (1 - p[i]) * (s[i] + Get(i + 1, t - s[i]));
//         if (35 < aktc && aktc < 36 && t == 2) {
//           LD gf = Get(i + 1, t - f[i]);
//           LD gs = Get(i + 1, t - s[i]);
//           debug(gf, gs, p[i] * gf + (1 - p[i]) * gs, cand);
//         }
        E[i][t] = min(cand, aktc);
//         if (t <= R) {
//           cerr<<E[i][t]<<" ";
//         }
      }
      //cerr<<endl;
    }
    //debug(aktc, "res=", E[1][R]);
    if (E[1][R] > aktc - 1e-9) {
      kl = aktc;
    } else {
      kp = aktc;
    }
  }
  cout<<kl<<endl;
  
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}