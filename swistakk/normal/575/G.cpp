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
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
using namespace std;
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
const int N = 1e5 + 2;
int dis[N][2];
VPII slo[N];
const int kInf = 1e9 + 5;
VI res;
int vis[N];
int par[N];
int good[N];
void Dfsuj0(int v) {
  vis[v] = 1;
  for (auto e : slo[v]) {
    int nei = e.st;
    if (!vis[nei] && !e.nd) {
      par[nei] = v;
      Dfsuj0(nei);
    }
  }
}
VI lay[N];
VPII up[N];
int zers[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  RE (i, m) {
    make3(int, a, b, c);
    slo[a].PB({b, c});
    slo[b].PB({a, c});
  }
  Dfsuj0(n - 1);
  REP (i, n) {
    zers[i] = kInf;
  }
  zers[n - 1] = 0;
  set<PII> dupa;
  REP (i, n) {
    dupa.insert({zers[i], i});
  }
  while (!dupa.empty()) {
    auto p = *dupa.begin();
    dupa.erase(dupa.begin());
    int v = p.nd;
    for (auto e : slo[v]) {
      int nei = e.st;
      if (e.nd) { continue; }
      int cand = zers[v] + 1;
      if (zers[nei] > cand) {
        dupa.erase({zers[nei], nei});
        par[nei] = v;
        zers[nei] = cand;
        dupa.insert({zers[nei], nei});
      }
    }
  }
  
  
  REP (tr, 2) {
    REP (i, n) {
      if ((tr == 0 && i == 0) || (tr && vis[i])) {
        dis[i][tr] = 0;
      } else {
        dis[i][tr] = kInf;
      }
    }
    set<PII> secik;
    REP (i, n) {
      secik.insert({dis[i][tr], i});
    }
    while (!secik.empty()) {
      auto p = *secik.begin();
      secik.erase(secik.begin());
      int v = p.nd;
      for (auto e : slo[v]) {
        int nei = e.st;
        int cand = p.st + 1;
        if (dis[nei][tr] > cand) {
          secik.erase(MP(dis[nei][tr], nei));
          dis[nei][tr] = cand;
          secik.insert(MP(dis[nei][tr], nei));
        }
      }
    }
  }
  REP (i, n) {
    for (auto e : slo[i]) {
      int nei = e.st;
      if (dis[nei][0] + 1 + dis[i][1] == dis[0][1]) {
        up[i].PB({nei, e.nd});
        cerr<<"edge: "<<i<<" "<<nei<<endl;
      }
    }
    if (dis[i][1] < kInf) {
      lay[dis[i][1]].PB(i);
    }
  }
  
  for (auto x : lay[0]) {
    good[x] = zers[x] + 1;
  }
  cerr<<"zersy: ";
  REP (i, n) {
    cerr<<zers[i]<<" ";
  }
  cerr<<endl;
  debugv(lay[0]);
  REP (layer, dis[0][1]) {
    int best = 10;
    for (int v : lay[layer]) {
      if (!good[v]) { continue; }
      for (auto e : up[v]) {
        mini(best, e.nd);
      }
    }
    cout<<best;
    for (int v : lay[layer]) {
      if (!good[v]) { continue; }
      for (auto e : up[v]) {
        if (e.nd == best) {
          if (good[e.st] == 0 || good[e.st] > good[v]) {
            good[e.st] = good[v];
            cerr<<e.st<<" ";
            par[e.st] = v;
          }
        }
      }
    }
    cerr<<endl;
  }
  
  assert(good[0]);
  if (vis[0]) {
    cout<<0;
  }
  VI stack;
  int cur = 0;
  while (cur != n - 1) {
    stack.PB(cur);
    cur = par[cur];
  }
  stack.PB(n - 1);
  cout<<endl<<SZ(stack)<<endl;
  for (auto x : stack) {
    cout<<x<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}