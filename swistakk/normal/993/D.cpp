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
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

const int kInf = 1e18;


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  VPII tasks(n);
  map<int, VI> groups;
  REP (i, n) {
    cin>>tasks[i].st;
  }
  REP (i, n) {
    cin>>tasks[i].nd;
  }
  REP (i, n) {
    groups[-tasks[i].st].PB(tasks[i].nd);
  }
  
  //sort(ALL(tasks), greater<PII>());
  debug(tasks);
  VVI dp(n + 2, VI((n + 2) * 100, kInf));
  dp[0][0] = 0;
  //tasks.insert(tasks.begin(), {0, 0});
  //RE (i, n) {
  for (auto group : groups) {
    int pow = -group.st;
    VI prs = group.nd;
    sort(ALL(prs), greater<int>());
    VI pref_sums{0};
    for (auto x : prs) {
      pref_sums.PB(pref_sums.back() + x);
    }
    VVI new_dp(n + 2, VI((n + 2) * 100, kInf));
    FOR (bil, 0, n) {
      FOR (not_used_here, 0, min(bil, SZ(prs))) {
        int used_here = SZ(prs) - not_used_here;
        int new_bil = bil - not_used_here + used_here;
        REP (pr_used, (n + 1) * 100 -1) {
          if (dp[bil][pr_used] == kInf) { continue; }
          int new_pr = pr_used + pref_sums[used_here];
          debug(new_bil, new_pr, bil, pr_used);
          mini(new_dp[new_bil][new_pr], dp[bil][pr_used] + used_here * pow);
        }
      //REP (me_use, 2) {
//         int new_used = used_prv + me_use;
//         if (2 * new_used < i) { continue; }
//         REP (pr_used, 100 * used_prv + 1) {
//           int new_pr = pr_used + me_use * tasks[i].nd;
//           mini(dp[new_used][new_pr], dp[used_prv][pr_used] + me_use * tasks[i].st);
//         }
      }
    }
    dp = new_dp;
//     debug(i);
//     REP (used, n) {
//       if (2 * used < i) {
//         dp[used] = VI((n + 2) * 100, kInf);
//       } else {
//         debug(used);
//         REP (j, 5) {
//           debug(dp[used][j]);
//         }
//       }
//       REP (pr_used, SZ(dp[used])) {
//         if (2 * used < i) { dp[used][pr_used] = kInf; }
//       }
  }
  LD best = kInf;
  //FOR (used, (n + 1) / 2, n) {
  FOR (bil, 0, n) {
    FOR (pr_used, 1, SZ(dp[bil]) - 1) {
      mini(best, (LD)1 * dp[bil][pr_used] / pr_used);
    }
  }
  cout<<(int)ceil(1000 * best - 1e-9)<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}