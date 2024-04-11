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

template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

const int N = 1e6 + 5;
VPII slo1[N];
VI slo2[N];
const int kInf = 1e18;
int dis[N];
int indeg[N];
int block[N];
VI trans[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m, s;
  cin>>n>>m>>s;
  RE (i, m) {
    int a, b, w;
    cin>>a>>b>>w;
    slo1[a].PB({b, w});
    slo1[b].PB({a, w});
  }
  RE (i, n) {
    dis[i] = kInf;
  }
  dis[s] = 0;
  set<PII> que;
  
  que.insert({0, s});
  while (SZ(que)) {
    auto it = que.begin();
    auto p = *it;
    debug(p);
    que.erase(it);
    int v = p.nd;
    int d = p.st;
    for (auto e : slo1[v]) {
      int nei = e.st;
      int cand = d + e.nd;
      debug(nei, cand);
      if (cand < dis[nei]) {
        que.erase({dis[nei], nei});
        dis[nei] = cand;
        que.insert({dis[nei], nei});
      }
    }
  }
  RE (i, n) {
    for (auto e : slo1[i]) {
      int nei = e.st;
      int d = e.nd;
      if (dis[nei] == dis[i] + d) {
        slo2[i].PB(nei);
        trans[nei].PB(i);
        indeg[nei]++;
      }
    }
  }
  VI que2;
  RE (i, n) {
    if (dis[i] < kInf) {
      debug(i, slo2[i]);
    }
    if (dis[i] < kInf && indeg[i] == 0) {
      que2.PB(i);
    }
  }
  map<int, int> cnt;
  block[s] = s;
  for (int ii = 0; ii < SZ(que2); ii++) {
    int v = que2[ii];
    block[v] = v;
    if (v != s) {
      int ziom = -1;
      for (auto pre : trans[v]) {
        if (ziom == -1) {
          ziom = block[pre];
        } else if (ziom != block[pre]) {
          ziom = -2;
        }
      }
      if (ziom >= 0 && ziom != s) {
        block[v] = ziom;
      }
      cnt[block[v]]++;
    }
    debug(v, block[v]);
    
    for (auto nei : slo2[v]) {
      indeg[nei]--;
      if (indeg[nei] == 0) {
        que2.PB(nei);
      }
    }
  }
  debug(que2);
  debug(cnt);
  int res = 0;
  for (auto p : cnt) {
    maxi(res, p.nd);
  }
  cout<<res<<endl;
    

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}