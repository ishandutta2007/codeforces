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

const int N = 22;
int cov[1 << N];
int par[1 << N];
bool can[1 << N];
int neis[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  REP (i, n) {
    neis[i] |= 1 << i;
  }
  if (m == n * (n - 1) / 2) {
    cout<<"0\n";
    return 0;
  }
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    a--;
    b--;
    neis[a] |= 1 << b;
    neis[b] |= 1 << a;
    //edge[a][b] = 1;
    //edge[b][a] = 1;
  }
  int full = (1 << n) - 1;
//   REP (i, 1 << n) {
//     dp[i] = N;
//   }
  REP (i, n) {
    if (neis[i] == full) {
      cout<<"1\n";
      cout<<i + 1<<endl;
      return 0;
    }
    //dp[1 << i] = 1;
    cov[1 << i] = neis[i];
    can[1 << i] = 1;
    par[1 << i] = i;
  }
  REP (mask, 1 << n) {
    if (mask  == 0) { continue; }
    REP (bit, n) {
      if ((mask & (1 << bit)) == 0) {
        continue;
      }
      int prv = mask - (1 << bit);
      if (can[prv] && (cov[prv] & (1 << bit))) {
        cov[mask] = cov[prv] | neis[bit];
        par[mask] = bit;
        can[mask] = 1;
      }
    }
  }
  int who = full;
  int best = n;
  REP (mask, 1 << n) {
    if (can[mask] && cov[mask] == full && __builtin_popcount(mask) < best) {
      who = mask;
      best = __builtin_popcount(mask);
    }
  }
  cout<<best<<endl;
  int cur = who;
  while (cur) {
    debug(cur, par[cur]);
    cout<<par[cur] + 1<<" ";
    cur  = cur - (1 << par[cur]);
  }
  cout<<endl;
        
  
  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}