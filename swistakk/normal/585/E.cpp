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
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
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

const int R = 1e7 + 5;
VI sq_free_divs[R];
short mu[R];
bool sito[R];
const int P = 1e9 + 7;
const int N = 1e6 + 5;
int pow2[N];
bool cnt_ex[R];
int cnt_mult[R];
int a[N];
void AddSelf(int& a, int b) {
  a = a + b;
  if (a < 0) {
    a += P;
  }
  if (a >= P) {
    a -= P;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, R - 1) {
    mu[i] = 1;
  }
  sito[1] = 1;
  pow2[0] = 1;
  RE (i, n) {
    cin>>a[i];
    cnt_ex[a[i]]++;
  }
  for (int i = 1; i < R; i++) {
    if (i < N) {
      pow2[i] = pow2[i - 1] * 2 % P;
    }
    if (sito[i] == 0) {
      for (int j = 1; i * j < R; j++) {
        mu[i * j] *= -1;
        if (j % i == 0) {
          mu[i * j] = 0;
        }
        sito[i * j] = 1;
      }
    }
    if (mu[i]) {
      for (int j = 1; i * j < R; j++) {
        if (cnt_ex[i * j]) {
          sq_free_divs[i * j].PB(i);
        }
      }
    }
  }
  RE (i, n) {
    debug(a[i]);
    debugv(sq_free_divs[a[i]]);
    for (auto& div : sq_free_divs[a[i]]) {
      cnt_mult[div]++;
    }
  }
  int S = 0;
  RE (i, R - 1) {
    if (cnt_mult[i]) {
      debug(i, cnt_mult[i], mu[i], pow2[cnt_mult[i]] - 1);
      AddSelf(S, (pow2[cnt_mult[i]] - 1) * mu[i]);
    }
  }
  debug(S);
  int res = 0;
  RE (ii, n) {
    int S_here = S;
    int c2 = 0;
    for (int& div : sq_free_divs[a[ii]]) {
      AddSelf(S_here, -mu[div] * pow2[cnt_mult[div] - 1]);
      AddSelf(c2, mu[div] * (pow2[cnt_mult[div] - 1] - 1));
    }
    debug(c2, S_here);
    AddSelf(res, c2);
    AddSelf(res, -S_here);
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}