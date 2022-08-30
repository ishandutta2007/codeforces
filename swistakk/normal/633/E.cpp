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

const int N = 1e6 + 5;
LD fac[N];
LD newt(int n, int k) {
  if (n < k || k < 0) { return 0; }
  return exp(fac[n] - fac[k] - fac[n - k]);
}
int v[N], r[N];
int rr[N][20];
int larg[N];
int MM(int i, int j) {
  int len = j - i + 1;
  return min(rr[i][larg[len]], rr[j + 1 - (1 << larg[len])][larg[len]]);
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  RE (i, N - 1) {
    fac[i] = fac[i - 1] + log(i);
  }
  int n, k;
  cin>>n>>k;
  RE (i, n) {
    cin>>v[i];
    v[i] *= 100;
  }
  larg[0] = -1;
  RE (i, n) {
    cin>>r[i];
    rr[i][0] = r[i];
    larg[i] = larg[i - 1] + ((i & (i - 1)) == 0);
  }
  int part = 1;
  RE (l, 19) {
    part *= 2;
    RE (i, n) {
      if (i + part - 1 <= n) {
        rr[i][l] = min(rr[i][l - 1], rr[i + part / 2][l-1]);
      }
    }
  }
  
  
  vector<PII> stac;
  vector<int> vals;
  FORD (i, n, 1) {
    while (!stac.empty() && (stac.back().st <= v[i] /*|| stac.back().nd >= r[i]*/)) {
      stac.pop_back();
    }
    stac.PB({v[i], i});
    int kl = 0, kp = SZ(stac) - 1, faj = 0;
    while (kl <= kp) {
      int aktc = (kl + kp) / 2;
      int ziom = MM(i, stac[aktc].nd);
      if (stac[aktc].st > ziom) {
        kl = aktc + 1;
      } else {
        kp = aktc - 1;
      }
      maxi(faj, min(stac[aktc].st, ziom));
    }
    vals.PB(faj);
    cerr<<faj<<" ";
  }
  cerr<<endl;
    
  
  
  
  
  
  
  assert(SZ(vals) == n);
  sort(ALL(vals));
  LD res = 0;
  RE (i, n) {
    //res += newt(n - i, k - 1) / newt(n, k) * vals[i - 1];
    if (n - i < k - 1) { break; }
    res += exp(fac[n - i] - fac[n - i - k + 1] - fac[k - 1] -fac[n] + fac[k] + fac[n - k]) * vals[i - 1]; 
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}