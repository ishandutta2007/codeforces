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
#define pow10 DUPAUDPA
const int N = 1e6;
int pow2[N + 5], pow10[N + 5];
int sum[N][3];
const int P = 1e9 + 7;
int GetDig(int x, int dig) {
  return (x / pow10[dig]) % 10;
}
int res[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  pow2[0] = 1;
  pow10[0] = 1;
  RE (i, N) {
    pow2[i] = pow2[i - 1] * 2 % P;
    pow10[i] = pow10[i - 1] * 10 % P;
  }
  
  int n;
  cin>>n;
  RE (i, n) {
    int x;
    cin>>x;
    sum[x][0]++;
    sum[x][1] += x;
    sum[x][2] += x * x;
  }
  REP (i, N) {
    REP (tr, 3) {
      sum[i][tr] %= P;
    }
  }
  REP (dig, 6) {
    FORD (x, N - 1, 0) {
      if (GetDig(x, dig)) {
        int prv = x - pow10[dig];
        REP (tr, 3) {
          sum[prv][tr] += sum[x][tr];
          sum[prv][tr] %= P;
        }
      }
    }
  }
  REP (i, N) {
    int c = sum[i][0];
    //debug(c);
    if (c >= 1) {
      res[i] = pow2[c - 1] * sum[i][2];
    }
    if (c >= 2) {
      res[i] += pow2[c - 2] * (sum[i][1] * sum[i][1] % P - sum[i][2] + P) % P;
    }
    res[i] %= P;
  }
  //~ REP (i, N) {
    //~ if (res[i]) {
      //~ debug(i, res[i]);
    //~ }
  //~ }
  int R = 0;
  REP (dig, 6) {
    REP (x, N) {
      if (GetDig(x, dig) != 9) {
        int nxt = x + pow10[dig];
        res[x] = (res[x] - res[nxt] + P) % P;
      }
    }
  }
  REP (i, N) {
    //~ if (res[i]) {
      //~ debug(i, res[i]);
    //~ }
    R = R ^ (i * res[i]);
  }
    
  cout<<R<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}