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

const int N = 2e5 + 5;
int phi[N];
int wh[N];
VI prods_at_g[N];
int is_forb[N];
int dp[N];
int par[N];
typedef long long LL;
LL gcd(LL a, LL b, LL& x, LL& y){
  if (a < b) return gcd(b, a, y, x);
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  LL xp;
  LL pom = gcd(b, a % b, xp, x);
  y = xp - x * (a / b);
  return pom;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int mod, forb_cnt;
  cin>>forb_cnt>>mod;
  //set<int> forb;
  RE (i, forb_cnt) {
    int a;
    cin>>a;
    is_forb[a] = 1;
  }
  REP (i, N) {
    phi[i] = i;
  }
  VI ds{1};
  FOR (i, 2, mod) {
    if (phi[i] == i) {
      for (int j = i; j < N; j += i) {
        phi[j] = phi[j] * (i - 1) / i;
      }
    }
    if (mod % i == 0) {
      ds.PB(i);
    }
  }
  debug(ds);
  REP (i, SZ(ds)) {
    wh[ds[i]] = i;
  }
  RE (i, mod - 1) {
    if (!is_forb[i]) {
      prods_at_g[__gcd(i, mod)].PB(i);
    }
  }
  dp[1] = SZ(prods_at_g[1]);
  int wh_best = 1;
  for (auto d1 : ds) { // wiekszy dzielnik
    debug(d1, SZ(prods_at_g[d1]));
    for (auto d2 : ds) {
      if (d1 == d2) { break; }
      if (d1 % d2) { continue; }
      int cand = dp[d2] + SZ(prods_at_g[d1]);
      if (cand > dp[d1]) {
        par[d1] = d2;
        dp[d1] = cand;
      }
    }
    if (dp[d1] > dp[wh_best]) {
      wh_best = d1;
    }
  }
  VI g_path;
  int cur_v = wh_best;
  while (cur_v) {
    g_path.PB(cur_v);
    cur_v = par[cur_v];
  }
  reverse(ALL(g_path));
  debug(g_path);
  debug(dp[wh_best], wh_best);
  int cur_prod = 1;
  VI res;
  int last_g = 1;
  for (auto g : g_path) {
    debug(g, prods_at_g[g]);
    for (auto p : prods_at_g[g]) {
      //int fix_g = g / last_g;
      int x, y;
      //int prod_coprime = cur_prod / last_g;
      int old_g = gcd(cur_prod, mod, x, y); // last_coprime * x + mod * y == 1
      debug(cur_prod, mod, x, y);
      assert(cur_prod * x + mod * y == old_g);
      //int cur_coprime = p / g;
      //int to_mult = fix_g * cur_coprime % mod * x % mod;
      int to_mult = x * p / old_g;
      to_mult %= mod;
      to_mult = (to_mult + mod) % mod;
      res.PB(to_mult);
      cur_prod = cur_prod * to_mult % mod;
      debug(cur_prod);
      assert(cur_prod == p);
      last_g = g;
    }
  }
  if (!is_forb[0]) {
    res.PB(0);
  }
  cout<<SZ(res)<<endl;
  for (auto x : res) {
    cout<<x<<" ";
  }
  cout<<endl;
    
  
  
  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}