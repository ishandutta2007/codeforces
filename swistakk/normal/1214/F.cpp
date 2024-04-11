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

const int kInf = 1e18;
const int N = 1e6 + 5;
int pref_sum[N];
struct Obj {
  int st, nd, id;
};
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int m, n;
  cin>>m>>n;
  vector<Obj> zioms;
  RE (i, n) {
    int a;
    cin>>a;
    zioms.PB({a, 1, i});
    zioms.PB({a + m, 1, i});
  }
  VI last_bil(4 * n + 5, -1);
  int best = kInf;
  RE (i, n) {
    int a;
    cin>>a;
    zioms.PB({a, -1, i});
    zioms.PB({a + m, -1, i});
  }
  zioms.PB({-1, -1});
  sort(ALL(zioms), [&](Obj a, Obj b) { if (a.st != b.st) {return a.st < b.st;} if (a.nd != b.nd) { return a.nd < b.nd; }; return a.id < b.id; });
  int bil = 2 * n;
  last_bil[bil] = 0;
  VI wh_prv(4 * n + 5);
  VI dp(4 * n + 5);
  int wh_res = -1;
  VI bil_at(4 * n + 5);
  RE (i, SZ(zioms) - 1) {
    int pos = zioms[i].st;
    int typ = zioms[i].nd;
    pref_sum[i] = pref_sum[i - 1] + pos * typ;
    bil += typ;
    bil_at[i] = bil;
    if (last_bil[bil] != -1) {
      wh_prv[i] = last_bil[bil];
      dp[i] = dp[last_bil[bil]] + abs(pref_sum[i] - pref_sum[last_bil[bil]]);
    }
    //debug(i, pos, typ, bil, dp[i]);
    if (i >= 2 * n) {
      //debug(i, dp[i] - dp[i - 2 * n]);
      if (best > dp[i] - dp[i - 2 * n]) {
        wh_res = i;
      }
      mini(best, dp[i] - dp[i - 2 * n]);
    }
    last_bil[bil] = i;
  }
  cout<<best<<endl;
  int stop = wh_res - 2 * n;
  debug(bil_at[stop]);
  VI res(n + 2);
  while (wh_res != stop) {
    int skok = wh_prv[wh_res];
    if (wh_res) {
      debug(wh_res, stop, skok, bil_at[wh_res]);
    }
    VI vac, guys;
    FOR (i, skok + 1, wh_res) {
      if (zioms[i].nd == 1) {
        vac.PB(zioms[i].id);
      } else {
        guys.PB(zioms[i].id);
      }
    }
    REP (i, SZ(guys)) {
      res[vac[i]] = guys[i];
    }
    wh_res = skok;
  }
  RE (i, n) {
    cout<<res[i]<<" ";
  }
  cout<<endl;
    
  
  
  return 0;
}