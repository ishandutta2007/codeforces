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

const int N = 2137;
const int kInf = 1e18;
int dp[N][N]; // dp[a][m] - najwiekszy profit taki e ostatni co wszed ma agrr=a i maska jest m 
int best[N]; // best[a] = max_m dp[a][m];

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  VI aggr(n + 2), cost(n + 2);
  VI profs(n + m + 2);
  RE (i, n) {
    cin>>aggr[i];
  }
  RE (i, n) {
    cin>>cost[i];
  }
  RE (i, n + m) {
    cin>>profs[i];
  }
  REP (i, N) {
    REP (j, N) {
      dp[i][j] = -kInf;
    }
  }
  REP (i, N) {
    best[i] = -kInf;
  }
  best[0] = 0;
  dp[0][0] = 0;
  int L = 12;
  FORD (i, n, 1) {
    int a = aggr[i];
    FORD (prv_a, a, max(0ll, a - L)) {
      int diff = a - prv_a;
      VI best_here(n / (1 << diff) + 1, -kInf);
      REP (prv_m, n + 1) {
        maxi(best_here[prv_m / (1 << diff)], dp[prv_a][prv_m]);
      }
      REP (j, SZ(best_here)) {
        if (best_here[j] < -kInf / 2) { continue; }
        int cur = profs[a] - cost[i];
        int cur_mask = j;
        REP (bit, L) {
          if (cur_mask & (1 << bit)) {
            cur_mask -= (1 << bit);
            cur += profs[a + bit + 1];
          } else {
            cur_mask += (1 << bit);
            break;
          }
        }
        assert(cur_mask == j + 1);
        if (dp[a][cur_mask] < best_here[j] + cur) {
          debug(a, cur_mask, j, best_here[j], cur);
        }
        maxi(dp[a][cur_mask], best_here[j] + cur);
        maxi(best[a], dp[a][cur_mask]);
      }
    }
    REP (prv_a, a - L) {
      maxi(dp[a][1], best[prv_a] + profs[a] - cost[i]);
      maxi(best[a], dp[a][1]);
    }
  }
  int res = -kInf;
  REP (i, N) {
    REP (j, N) {
      maxi(res, dp[i][j]);
    }
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}