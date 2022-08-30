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
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
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

const int N = 1e5 + 5;
const int K = 212;
int dp[N][K];
int coeff[K];
const int P = 1e9 + 7;
int newt[K][K];
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
int n, k;
int p2[N];
int res;
int ndp[K];
VI slo[N];
int sz[N];
void Dfs(int v, int p) {
  //vis[v] = 1;
  sz[v] = 1;
  dp[v][0] = 2;
  for (auto nei : slo[v]) {
    if (nei == p) { continue; }
    Dfs(nei, v);
    REP (i, K) {
      ndp[i] = 0;
    }
    dp[nei][0] = p2[sz[nei]];
    FOR (l, 0, min(sz[v], k)) {
      FOR (r, 0, min(sz[nei], k - l)) {
        ndp[l + r] = (ndp[l + r] + dp[v][l] * dp[nei][r]) % P;
      }
    }
    REP (i, K) {
      dp[v][i] = ndp[i];
    }
    sz[v] += sz[nei];
  }
  debug(v);
  RE (i, k) {
    cerr<<dp[v][i]<<" ";
  }
  cerr<<endl;
    
  RE (es, k) {
    int sum_sons = 0;
    for (auto nei : slo[v]) {
      if (nei == p) { continue; }
      sum_sons += dp[nei][es] * p2[sz[v] - sz[nei]];
      sum_sons %= P;
    }
    res = (res + (dp[v][es] - sum_sons + P) * coeff[es] % P * p2[n - sz[v]]) % P;
  }
  
  dp[v][0] = p2[sz[v]] - 1;
  if (p != -1) {
    REP (prv, k) {
      debug(prv, dp[v][prv], (p2[n - sz[v]] - 1), coeff[prv + 1]);
      res = (res + dp[v][prv] * (p2[n - sz[v]] - 1) % P * coeff[prv + 1]) % P;
    }
  }
  FORD (prv, k, 1) {
    dp[v][prv] += dp[v][prv - 1];
    if (dp[v][prv] >= P) {
      dp[v][prv] -= P;
    }
  }
  RE (i, k) {
    cerr<<dp[v][i]<<" ";
  }
  cerr<<endl;
  //dp[v][1] = (dp[v][1] + p2[sz[v]] - 1) % P;
  //res = (res + (p2[sz[v]] - 1) * (p2[n - sz[v]] - 1)) % P; // single edge
  
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n>>k;
  REP (i, K) {
    newt[i][i] = newt[i][0] = 1;
    RE (j, i - 1) {
      newt[i][j] = (newt[i - 1][j] + newt[i - 1][j - 1]) % P;
    }
  }
  RE (j, k) {
    REP (lack, j) {
      int sign = 1;
      if (lack % 2) {
        sign = P - 1;
      }
      coeff[j] = (coeff[j] + spow(j - lack, k) * newt[j][lack] % P * sign) % P;
    }
    debug(coeff[j]);
  }
  p2[0] = 1;
  RE (i, n) {
    p2[i] = 2 * p2[i - 1] % P;
  }
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  Dfs(1, -1);
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}