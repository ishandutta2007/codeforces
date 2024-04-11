#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

struct State {
  int ba, ca, bil, code;
};
const int N = 1e5;
int pot3[N];

int a[N], b[N], c[N];
string Decode(int code, int len) {
  string s;
  RE (i, len) {
    if (code % 3 == 0) {
      s += "MW\n";
    } else if (code % 3 == 1) {
      s += "LW\n";
    } else if (code % 3 == 2) {
      s += "LM\n";
    }
    code /= 3;
  }
  return s;
}


int main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  RE (i, n) {
    cin>>a[i]>>b[i]>>c[i];
  }
  pot3[0] = 1;
  RE (i, n) {
    pot3[i] = 3 * pot3[i - 1];
  }
//   vector<TII> fir, sec;
  int half = n / 2;
//   for (int i = 1; i <= half; i++) {
//     fir.PB({a[i], b[i], c[i]});
//   }
//   FOR (i, half + 1, n) {
//     sec.PB({a[i], b[i], c[i]});
//   }
  vector<State> halfs[2];
  REP (phase, 2) {
    map<long long, State> mapka;
    int beg = 1, en = half;
    int len = half;
    if (phase) {
      beg = half + 1;
      en = n;
      len = n - half;
    }
    REP (mask, pot3[len]) {
      VI bits;
      int tmp = mask;
      int aa = 0;
      int ba = 0, ca = 0;
      FOR (tr, beg, en) {
        //bits.PB(tmp % 3);
        if (tmp % 3 == 0) {
          ba += b[tr];
          ca += c[tr];
        } else if (tmp % 3 == 1) {
          aa += a[tr];
          ba -= a[tr];
          ca += c[tr] - a[tr];
        } else if (tmp % 3 == 2) {
          aa += a[tr];
          ba += b[tr] - a[tr];
          ca -= a[tr];
        }
        tmp /= 3;
      }
      long long ind = ((ll)1e9) * ba + ca; 
      auto it = mapka.find(ind);
      if (it == mapka.end() || it->nd.bil < aa) {
        mapka[ind] = {ba, ca, aa, mask};
      }
    }
    for (auto& s : mapka) {
      halfs[phase].PB(s.nd);
    }
  }
  int pal = SZ(halfs[1]) - 1;
  int best_bil = -2e9;
  string best_hist = "";
  for (auto& s : halfs[0]) {
    while (pal && (halfs[1][pal].ba + s.ba > 0 || (halfs[1][pal].ba + s.ba == 0 && halfs[1][pal].ca + s.ca > 0))) {
      pal--;
    }
    int cand_bil = s.bil + halfs[1][pal].bil;
    if (halfs[1][pal].ba + s.ba == 0 && halfs[1][pal].ca + s.ca == 0 && cand_bil > best_bil) {
      best_bil = cand_bil;
      best_hist = Decode(s.code, half) + Decode(halfs[1][pal].code, n - half);
    }
  }
  if (best_hist != "") {
    cout<<best_hist;
  } else {
    cout<<"Impossible\n";
  }
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}