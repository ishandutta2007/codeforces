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

const int N = 2e3 + 5;
bitset<N> prefs[N];
int cnt[N];
bitset<N> row[N], neg[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  REP (i, N) {
    RE (j, i) {
      prefs[i][j] = 1;
    }
  }
  
  int n, m, q;
  cin>>n>>m>>q;
  set<PII> by_cnt;
  RE (i, n) {
    RE (j, m) {
      neg[i][j] = 1;
    }
    by_cnt.insert({0, i});
  }
  map<PII, PII> anses;
  auto Remove = [&](int a, int b) {
    if (a > b) { swap(a, b); }
    anses.erase({a, b});
  };
  auto Add = [&](int a, int b) {
    if (a > b) { swap(a, b); }
    int x = (row[a] & neg[b])._Find_first();
    if (x == N) { return; }
    int y = (neg[a] & row[b])._Find_first();
    if (y == N) { return; }
    if (x > y) {
      swap(x, y);
    }
    anses[{a, b}] = {x, y};
  };
  RE (i, q) {
    int a, l, r;
    cin>>a>>l>>r;
    int prv_cnt = cnt[a];
    row[a] ^= prefs[r];
    row[a] ^= prefs[l - 1];
    neg[a] ^= prefs[r];
    neg[a] ^= prefs[l - 1];
    auto it = by_cnt.find({prv_cnt, a});
    if (it != by_cnt.begin()) {
      Remove(a, prev(it)->nd);
    }
    assert(it != by_cnt.end());
    if (next(it) != by_cnt.end()) {
      Remove(a, next(it)->nd);
    }
    if (it != by_cnt.begin() && next(it) != by_cnt.end()) {
      Add(prev(it)->nd, next(it)->nd);
    }
    by_cnt.erase(it);
    cnt[a] = row[a].count();
    it = by_cnt.insert({cnt[a], a}).st;
    if (it != by_cnt.begin()) {
      Add(a, prev(it)->nd);
    }
    if (next(it) != by_cnt.end()) {
      Add(a, next(it)->nd);
    }
    if (it != by_cnt.begin() && next(it) != by_cnt.end()) {
      Remove(prev(it)->nd, next(it)->nd);
    }
    if (anses.empty()) {
      cout<<"-1\n";
    } else {
      auto p = anses.begin();
      cout<<p->st.st<<" "<<p->nd.st<<" "<<p->st.nd<<" "<<p->nd.nd<<"\n";
    }
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}