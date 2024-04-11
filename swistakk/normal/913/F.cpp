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
const int P = 998244353;
int spow(int a, int b) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = r * a % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}
int inv(int a) {
  return spow(a, P - 2);
}
const int N = 2e3 + 5;
int powp[N];
int powq[N];
int dp[N][N]; // dp[s][w] pstwo ze pewna grupa wielkosci w wsrod s osob wygrywa z reszta
int trwaj[N]; // pstwo ze jest cykl hamiltona w wielkosci n
int res[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  

  int n;
  int a, b;
  cin>>n>>a>>b;
  int p = a * inv(b) % P;
  int q = (1 - p + P) % P;
  powp[0] = powq[0] = 1;
  RE (i, n) {
    powp[i] = p * powp[i - 1] % P;
    powq[i] = q * powq[i - 1] % P;
  }
  dp[0][0] = 1;
  RE (s, n) {
    REP (prv, s) {
      dp[s][prv] = (dp[s][prv] + dp[s - 1][prv] * powp[prv]) % P;  // nie wygrywa
      dp[s][prv + 1] = (dp[s][prv + 1] + dp[s - 1][prv] * powq[s - prv - 1]) % P; // wygrywa
    }
  }
  trwaj[1] = 1;
  FOR (s, 3, n) {
    trwaj[s] = 1;
    RE (prv, s - 1) {
      trwaj[s] = ((trwaj[s] - dp[s][prv] * trwaj[prv]) % P + P) % P;
    }
    //debug(s, 9 * trwaj[s] % P);
  }
  res[2] = 1;
  FOR (s, 3, n) {
    int tmp = s * (s - 1) / 2;
    RE (lam, s - 1) {
      int rest = s - lam;
      tmp = (tmp + dp[s][lam] * trwaj[lam] % P * (res[lam] + res[rest] - (rest * (rest - 1)) / 2 + P)) % P;
    }
    res[s] = tmp * inv(P + 1 - trwaj[s]) % P;
  }
  cout<<res[n]<<endl;
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}