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
int is_nei1[N];
VPII slo[N];
int to1[N];
VI Schodkuj(VI& vs) {
  if (vs.empty()) { return {}; }
  if (vs[0] == -1) { return {-1}; }
  REP (i, SZ(vs)) {
    int wh_biggest = i;
    FOR (j, i + 1, SZ(vs) - 1) {
      if (vs[j] > vs[wh_biggest]) {
        wh_biggest = j;
      }
    }
    swap(vs[wh_biggest], vs[i]);
    FOR (j, 0, SZ(vs) - 1) {
      if (j != i) {
        vs[j] = min(vs[j], vs[j] ^ vs[i]);
      }
    }
  }
  if (vs.back() == 0) { return {-1}; }
//   while (vs.back() == 0) {
//     vs.pop_back();
//   }
  return vs;
}
int vis[N];
int xorr[N];
int last_root;
void Dfs(int v, int par, VI& lin) {
  vis[v] = 1;
  for (auto e : slo[v]) {
    int nei = e.st;
    int w = e.nd;
    if ((is_nei1[nei] && nei != last_root) || nei == 1) { continue; }
    if (nei == par) { continue; }
    if (vis[nei]) {
      //debug(v, nei);
      if (nei < v) {
        int vec = xorr[v] ^ xorr[nei] ^ w;
        //debug(v, nei, vec);
        //int lin_sz = SZ(lin);
        lin.PB(vec);
        lin = Schodkuj(lin);
        if (lin == VI{-1}) { return; }
      }
//       if (SZ(lin) == lin_sz) {
//         lin = {-1};
//         return;
//       }
    } else {
      
      xorr[nei] = xorr[v] ^ w;
      //debug(v, "->", nei);
      Dfs(nei, v, lin);
      if (lin == VI{-1}) { return; }
    }
  }
}
    
VI Merge(VI m1, VI m2) {
  if (m1 == VI{-1} || m2 == VI{-1}) { return {-1}; }
  m1.insert(m1.end(), ALL(m2));
  m1 = Schodkuj(m1);
  return m1;
}

VI ToMat(int m) {
  if (m == -1) { return {-1}; }
  VI heh;
  REP (i, 32) {
    if (m & (1ll << i)) {
      heh.PB(i);
    }
  }
  return heh;
}
int ToInt(VI& m) {
  int res = 0;
  if (m == VI{-1}) { return -1; }
  for (auto x : m) {
    res |= (1 << x);
  }
  return res;
}
map<PII, int> memo;
int calls;
int Merge(int m1, int m2) {
  if (m1 == 0 || m2 == 0) { return m1 + m2; }
  calls++;
  auto it = memo.find({m1, m2});
  if (it != memo.end()) {
    return it->nd;
  }
  VI heh = Merge(ToMat(m1), ToMat(m2));
  return memo[{m1, m2}] = ToInt(heh);
}
map<int, int> ids;
map<int, int> inv_ids;
int Id(int v) {
  if (v == -1) { return -1; }
  if (ids.count(v)) { return ids[v]; }
  int sz = SZ(ids);
  inv_ids[sz] = v;
  return ids[v] = sz;
}
const int M = 505 + 5;
int memo_ids[M][M];
int MergeIds(int id1, int id2) {
  if (id1 == -1 || id2 == -1) { return -1; }
  if (memo_ids[id1][id2] != -2) {
    return memo_ids[id1][id2];
  }
  return memo_ids[id1][id2] = Id(Merge(inv_ids[id1], inv_ids[id2]));
}
const int P = 1e9 + 7;
VI lin[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  REP (i, M) {
    REP (j, M) {
      memo_ids[i][j] = -2;
    }
  }
  
  int n, m;
  cin>>n>>m;
  VI neis1;
  RE (i, m) {
    int a, b, w;
    cin>>a>>b>>w;
    if (a > b) { swap(a, b); }
    slo[a].PB({b, w});
    slo[b].PB({a, w});
    if (a == 1) {
      is_nei1[b] = 1;
      to1[b] = w;
    }
  }
  
  FOR (v, 2, n) {
    if (is_nei1[v]) {
      last_root = v;
      Dfs(v, -1, lin[v]);
    }
  }
  vector<VVI> cands;
  FOR (v, 2, n) {
    if (is_nei1[v]) {
      int has_nei = 0;
      for (auto e : slo[v]) {
        int nei = e.st;
        if (is_nei1[nei]) {
          has_nei = 1;
          if (nei > v) {
            lin[v] = Merge(lin[v], lin[nei]);
//             if (lin[v] == {-1} || lin[nei] == {-1}) { continue; }
//             lin[v].insert(lin[v].end(), ALL(lin[nei]));
//             lin[v] = Schodkuj(lin[v]);
            if (lin[v] == VI{-1}) { continue; }
            int triangle = to1[v] ^ to1[nei] ^ e.nd;
            VI with_tr = lin[v];
            with_tr.PB(triangle);
            with_tr = Schodkuj(with_tr);
            //debug(lin[v], with_tr);
            cands.PB({lin[v], with_tr});
          }
        }
      }
      if (!has_nei) {
        //debug(lin[v]);
        cands.PB({lin[v]});
      }
    }
  }
  debug("here");
  debug(cands);
  debug(SZ(cands));
  VI dp(M);
  dp[Id(0)] = 1;
  for (auto cand : cands) {
    if (cand == VVI{{-1}}) { continue; }
    VI ndp = dp;
    VI idd;
    REP (i, SZ(cand)) {
      idd.PB(Id(ToInt(cand[i])));
    }
    
    REP (i, SZ(dp)) {
      if (dp[i] == 0) { continue; }
      if (SZ(cand) == 1) {
        int nowy = MergeIds(i, idd[0]);
        if (nowy != -1) {
          ndp[nowy] += dp[i];
          if (ndp[nowy] >= P) { ndp[nowy] -= P; }
        }
      } else {
        int nowy_bez = MergeIds(i, idd[0]);
        if (nowy_bez == -1) { continue; }
        ndp[nowy_bez] += 2 * dp[i];
        while (ndp[nowy_bez] >= P) { ndp[nowy_bez] -= P; }
        int nowy_z = MergeIds(i, idd[1]);
        if (nowy_z == -1) { continue; }
        //debug(nowy_z);
        ndp[nowy_z] += dp[i];
        if (ndp[nowy_z] >= P) { ndp[nowy_z] -= P; }
      }
    }
    dp = ndp;
  }
  debug(SZ(dp));
  debug(calls);
  debug(SZ(memo));
  debug(SZ(ids));
  int res = 0;
  REP (i, SZ(dp)) {
    res = (res + dp[i]) % P;
  }
  cout<<res<<endl;
      
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}