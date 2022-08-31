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

int base[6];
int tim[130][6];
int getSc(int a, int b) { // a out of b
  if (a == 0) {
    return 3000;
  }
  int aa = a;
  int L = 0;
  while (a <= b) {
    a = 2 * a;
    L++;
  }
  debug(aa, b, L);
  return 500 * min(L, 6ll);
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int parts;
  cin>>parts;
  RE (i, parts) {
    RE (j, 5) {
      cin>>tim[i][j];
      if (tim[i][j] == -1) {
        tim[i][j] = 250;
      } else {
        base[j]++;
      }
    }
  }
  
  function<bool(int)> Check = [&](int aktc) {
    int vas = 0, pet = 0;
    RE (j, 5) {
      int sc;
      if (tim[1][j] < tim[2][j] || tim[1][j] == 250) {
        sc = getSc(base[j], parts + aktc);
      } else {
        sc = getSc(base[j] + aktc, parts + aktc);
      }
      vas += (250 - tim[1][j]) * sc / 250;
      pet += (250 - tim[2][j]) * sc / 250;
      if (aktc == 1) {
        debug((250 - tim[1][j]) * sc / 250, (250 - tim[2][j]) * sc / 250);
      }
    }
    return vas > pet;
  };
  int duzo = 1e9 + 7;
  int kl = 0, kp = duzo, faj = duzo + 1;
  while (kl <= kp) {
    int aktc = (kl + kp) / 2;
    
    //debug(aktc, vas, pet);
    if (Check(aktc)) {
      faj = aktc;
      kp = aktc - 1;
    } else {
      kl = aktc + 1;
    }
  }
  REP (i, 4000) {
    if (Check(i)) {
      cout<<i<<endl;
      return 0;
    }
  }
  if (faj > duzo) {
    cout<<"-1\n";
  } else {
    cout<<faj<<endl;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}