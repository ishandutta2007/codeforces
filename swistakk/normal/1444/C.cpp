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

const int N = 1e6 + 5;
int rep[N];
int cost[N];
int sz[N];
PII Find(int v) { 
  if (v == rep[v]) {
    return {v, 0};
  }
  auto p = Find(rep[v]);
  return {p.st, p.nd ^ cost[v]};
}
vector<VI> changes;
int Union(int a, int b) {
  PII fa = Find(a);
  PII fb = Find(b);
  a = fa.st;
  b = fb.st;
  if (a == b) {
    if (fa.nd == fb.nd) {
      return -1;
    }
    return 0;
  }
  if (sz[a] < sz[b]) {
    swap(a, b);
    swap(fa, fb);
  }
  changes.PB({a, b, sz[a], rep[b], cost[b]});
  rep[b] = a;
  cost[b] = fa.nd ^ fb.nd ^ 1;
  sz[a] += sz[b];
  return 1;
}
  
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m, k;
  cin>>n>>m>>k;
  RE (i, n) {
    rep[i] = i;
    sz[i] = 1;
  }
  //VVI by_grp(k + 2);
  VI wh_grp(n + 2);
  RE (i, n) {
    int c;
    cin>>c;
    //by_grp[c].PB(c);
    wh_grp[i] = c;
  }
  vector<VPII> within(k + 2);
  map<PII, VPII> between;
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    int a_gr = wh_grp[a];
    int b_gr = wh_grp[b];
    if (a_gr > b_gr) {
      swap(a_gr, b_gr);
    }
    if (a_gr == b_gr) {
      within[a_gr].PB({a, b});
    } else {
      between[{a_gr, b_gr}].PB({a, b});
    }
  }
  VI is_good(k + 2);
  int cnt_good = 0;
  RE (i, k) {
    int fail = 0;
    for (auto e : within[i]) {
      int heh = Union(e.st, e.nd);
      if (heh == -1) {
        fail = 1;
        break;
      }
    }
    debug(i, fail);
    if (!fail) {
      cnt_good++;
      is_good[i]++;
    }
  }
  changes.clear();
  debug(cnt_good);
  int res = cnt_good * (cnt_good - 1) / 2;
  for (auto p : between) {
    auto para = p.st;
    auto es = p.nd;
    int g1 = para.st;
    int g2 = para.nd;
    if (!is_good[g1] || !is_good[g2]) {
      continue;
    }
    int fail = 0;
    //  changes.PB({a, b, sz[a], rep[b], cost[b]});
    for (auto e : es) {
      int heh = Union(e.st, e.nd);
      if (heh == -1) {
        fail = 1;
        break;
      }
    }
    if (fail) {
      res--;
    }
    while (!changes.empty()) {
      auto change = changes.back();
      sz[change[0]] = change[2];
      rep[change[1]] = change[3];
      cost[change[1]] = change[4];
      changes.pop_back();
    }
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}