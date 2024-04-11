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

const int N = 2e5 + 5;
int vis1[N], vis2[N], deg[N];
set<int> slo[N];
int root;
int cut[N];
void Exit() {
  cout<<"-1\n";
  exit(0);
}
//~ int Dfs(int v) {
  //~ vis2[v] = 1;
  //~ set<int> hehs;
  //~ for (auto nei : slo[v]) {
    //~ if (vis2[nei]) { continue; }
    //~ hehs.insert(Dfs(nei) + 1);
  //~ }
  //~ if (v == root) {
    //~ if (SZ(hehs) == 1) {
      //~ cout<<2 * *(hehs.begin())<<endl;
      //~ exit(0);
    //~ } else if (SZ(hehs) == 2) {
      //~ cout<<*(hehs.begin()) + *(hehs.rbegin())<<endl;
      //~ exit(0);
    //~ }
  //~ }
  //~ if (SZ(hehs) > 1) {
    //~ Exit();
  //~ }
  //~ if (SZ(hehs)) {
    //~ return *(hehs.begin());
  //~ }
  //~ return 0;
//~ }
set<int> dynda[N];
int Zium(int a) {
  if (a % 2 == 1) {
    return a;
  }
  return Zium(a / 2);
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  vector<int> leaves;
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].insert(b);
    slo[b].insert(a);
    deg[a]++;
    deg[b]++;
  }
  //int internal = 0;
  RE (i, n) {
    if (SZ(slo[i]) == 1) {
      leaves.PB(i);
    }
  }
  if (SZ(leaves) == 2) {
    int ans = n - 1;
    cout<<Zium(ans)<<endl;
    return 0;
  }
    
  set<PII> que;
  //int shortest = n + 1;
  function<int(int, int)> GoUp = [&](int leaf, int add) {
    int cur = leaf;
    int cnt = 0;
    int prv = -1;
    debug(leaf, add);
    while (2 <3 /* heart on valentine's day! yay! */) {
      vis1[cur] = 1;
      //debug(cur);
      for (auto nei : slo[cur]) {
        if (deg[nei] >= 3 && !cut[nei]) {
          prv = cur;
          cur = nei;
          cnt++;
          goto A;
        }
        if (vis1[nei]) {
          continue;
        }
        cnt++;
        cur = nei;
      }
    }
    A: ;
    dynda[cur].insert(cnt + add);
    slo[cur].erase(prv);
    debug(cur, cnt + add);
    return cur;
  };
  
  
  VI lols;
  for (auto leaf : leaves) {
    lols.PB(GoUp(leaf, 0));
  }
  for (int ii = 0; ii < SZ(lols); ii++) {
    int v = lols[ii];
    debug(v);
    if (cut[v]) { continue; }
    if (SZ(slo[v]) == 1 && SZ(dynda[v]) == 1) {
      cut[v] = 1;
      lols.PB(GoUp(v, *(dynda[v].begin())));
    }
  }
  VI notcut;
  RE (i, n) {
    if (deg[i] >= 3 && !cut[i]) {
      notcut.PB(i);
    }
  }
  if (SZ(notcut) > 1) {
    Exit();
  }
  int v = notcut[0];
  if (SZ(dynda[v]) > 2) {
    Exit();
  }
  int ans = *(dynda[v].begin()) + *(dynda[v].rbegin());
  while (ans % 2 == 0) {
    ans /= 2;
  }
  cout<<ans<<endl;
  return 0;
      
  
  //~ RE (i, n) {
    //~ debug(i, dynda[i]);
    //~ if (dynda[i].empty()) { continue; }
    //~ que.insert({*(dynda[i].begin()), i});
  //~ }
  //~ VI roots;
  //~ while (!que.empty()) {
    //~ auto P = *(que.begin());
    //~ int v = P.nd;
    //~ debug(v, P.st);
    //~ que.erase(que.begin());
    //~ if (que.empty()) {
      //~ if (SZ(slo[v]) == 0) {
        //~ roots.PB(v);
        //~ continue;
      //~ }
    //~ }
    //~ if (SZ(dynda[v]) > 1) {
      //~ roots.PB(v);
      //~ continue;
      //~ Exit();
    //~ }
    //~ int guy;
    //~ if (SZ(dynda[v]) == 0) {
      //~ guy = GoUp(v, 0);
    //~ } else {
      //~ guy = GoUp(v, P.st);
    //~ }
    //~ if (SZ(slo[guy]) == 1) {
      //~ que.insert({*(dynda[guy].begin()), guy});
    //~ }
  //~ }
  //~ if (SZ(roots) != 1) {
    //~ Exit();
  //~ }
  //~ int v = roots[0]; 
  //~ if (SZ(dynda[v]) > 2) {
    //~ Exit();
  //~ }
  //~ int ans = *(dynda[v].begin()) + *(dynda[v].rbegin());
  //~ while (ans % 2 == 0) {
    //~ ans /= 2;
  //~ }
  //~ cout<<ans<<endl;
  //~ return 0;
  //~ 
  //~ 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}