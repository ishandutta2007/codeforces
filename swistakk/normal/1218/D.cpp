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

const int M = 1 << 17;
VVI cycles;
VPII stos;
VPII slo[M];
int vis[M];
int d;
int pre[M];
void Dfs(int v) {
  vis[v] = 1;
  pre[v] = d++;
  for (auto e : slo[v]) {
    int nei = e.st;
    int w = e.nd;
    if (vis[nei]) {
      if (SZ(stos) >= 2 && stos[SZ(stos) - 2].st == nei) { continue; }
      if (pre[nei] > pre[v]) { continue; }
      debug(nei, v);
      cycles.PB(VI{w});
      FORD (ind, SZ(stos) - 1, 0){
        if (stos[ind].st == nei) { break; }
        cycles.back().PB(stos[ind].nd);
      }
      continue;
    }
    stos.PB({nei, w});
    Dfs(nei);
    stos.pop_back();
  }
}
int MOD = 1e9 + 7;
const int M2 = 999999197;
const int INV2 = (MOD + 1) / 2;
void SelfMod(int& a) {
  while (a >= MOD) {
    a -= MOD;
  }
}
void Dziel(int& a) {
  if (a % 2 == 0) {
    a /= 2;
  } else {
    a = (a + MOD) / 2;
  }
}
//const int N = 1 << 20;
// Transforms the interval [x, y) in a.
void transform(int x, int y, int* a)
{
  if ( x == y - 1) {
    return;
  }
  int l2 = ( y - x ) / 2;
  int z = x + l2;
  transform(x, z, a);
  transform(z, y, a);
  for (int i=x; i<z; i++) {
    int x1 = a[i];
    int x2 = a[i+l2];
    a[i] = (x1 - x2 + MOD);
    a[i+l2] = (x1 + x2);
    SelfMod(a[i]);
    SelfMod(a[i + l2]);
  }
}
// Reverses the transform in
// the interval [x, y) in a.
void untransform(int x, int y, int* a)
{
  if ( x == y - 1) {
    return;
  }
  int l2 = ( y - x ) / 2;
  int z = x + l2;
  for (int i=x; i<z; i++) {
    long long y1 = a[i];
    long long y2 = a[i+l2];
    // x1 - x2 = y1
    // x1 + x2 = y2
    // 2 * x1  = y1 + y2
    // 2 * x2  = y2 - y1
    
    // In order to solve those equations, we need to divide by 2
    // But we are performing operations modulo 1000000007
    // that needs us to find the modular multiplicative inverse of 2.
    // That is saved in the INV2 variable.
    
    a[i] = (y1 + y2);
    a[i+l2] = (y2 - y1 + MOD);
    SelfMod(a[i]);
    SelfMod(a[i + l2]);
    Dziel(a[i]);
    Dziel(a[i + l2]);
  }
  untransform(x, z, a);
  untransform(z, y, a);
}

// void Mnoz(VI& A, VI& B) {
//   transform(0, M, &A[0]);
//   transform(0, M, &B[0]);
//   REP (i, M) {
//     A[i] = (long long) A[i] * B[i] % MOD;
//   }
//   untransform(0, M, &A[0]);
//   //return A;
// }

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  int xorr = 0;
  RE (i, m) {
    int a, b, w;
    cin>>a>>b>>w;
    xorr ^= w;
    slo[a].PB({b, w});
    slo[b].PB({a, w});
  }
  stos.PB({1, 0});
  Dfs(1);
  debug(cycles);
  VI cur(M), cur2(M);
  cur[0] = 1;
  transform(0, M, &cur[0]);
  MOD = M2;
  cur2[0] = 1;
  transform(0, M, &cur2[0]);
  for (auto cycle : cycles) {
    VI cyc_cnt(M);
    for (auto x : cycle) {
      cyc_cnt[x]++;
    }
    MOD = 1e9 + 7;
    transform(0, M, &cyc_cnt[0]);
    REP (i, M) {
      cur[i] = 1ll * cur[i] * cyc_cnt[i] % MOD;
    }
    REP (i, M) {
      cyc_cnt[i] = 0;
    }
    for (auto x : cycle) {
      cyc_cnt[x]++;
    }
    MOD = M2;
    transform(0, M, &cyc_cnt[0]);
    REP (i, M) {
      cur2[i] = 1ll * cur2[i] * cyc_cnt[i] % MOD;
    }
    //Mnoz(cur, cyc_cnt);
//     MOD = M2;
//     cur2 = Mnoz(cur2, cyc_cnt);
  }
  int min_res = 1e9;
  int wh_min = -1;
  MOD = 1e9 + 7;
  untransform(0, M, &cur[0]);
  MOD = M2;
  untransform(0, M, &cur2[0]);
  if (n < 45) {
    assert(cur == cur2);
  }
  REP (i, M) {
    if (cur[i] || cur2[i]) {
      int cand_xor = xorr ^ i;
      if (cand_xor < min_res) {
        min_res = cand_xor;
        wh_min = i;
      }
    }
  }
  cout<<min_res<<" "<<cur[wh_min]<<"\n";
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}