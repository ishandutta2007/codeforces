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

const int N = 5e3 + 5;
int dp[N][N][2]; // dp[i][j][tr] - z poddrzewa i kupuje j oraz kupilem korzen z przecena iff tr==1
const int kInf = 1e18 + 5;
int c[N], d[N], x[N];
VI child[N];
int sz[N];
void Dfs(int v) {
  sz[v] = 1;
  dp[v][0][0] = 0;
  dp[v][1][0] = c[v];
  dp[v][1][1] = c[v] - d[v];
  
  for (auto nei : child[v]) {
    Dfs(nei);
    FORD (l, sz[v], 0) {
      FORD (r, sz[nei], 1) {
        mini(dp[v][l + r][0], dp[v][l][0] + dp[nei][r][0]); // duh, I'm stupid
        mini(dp[v][l + r][1], dp[v][l][1] + dp[nei][r][0]);
        mini(dp[v][l + r][1], dp[v][l][1] + dp[nei][r][1]);
      }
    }
    sz[v] += sz[nei];
  }
  debug(v);
  RE (i, sz[v]) {
    cerr<<dp[v][i][0]<<" ";
  }
  cerr<<endl;
  RE (i, sz[v]) {
    cerr<<dp[v][i][1]<<" ";
  }
  cerr<<endl;
  
}
  
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, b;
  cin>>n>>b;
  RE (i, n) {
    cin>>c[i]>>d[i];
    if (i >= 2) {
      cin>>x[i];
      child[x[i]].PB(i);
    }
  }
  RE (i, n) {
    FOR (cnt, 0, n) {
      REP (tr, 2) {
        dp[i][cnt][tr] = kInf;
      }
    }
  }
  
  Dfs(1);
  int best = 0;
  RE (i, n) {
    if (dp[1][i][0] <= b || dp[1][i][1] <= b) {
      best = i;
    }
  }
  cout<<best<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}