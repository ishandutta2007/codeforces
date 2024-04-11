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
const int N = 3e5 +5;
int got[N];
VPII where[N];
int res[N];
int vis1[N];
int vis2[N];
vector<PII> slo[N];
int Get(int var, int cl) {
  int w = 0;
  if (SZ(where[var]) == 2 && where[var][1].st == cl) {
    w = 1;
  }
  return where[var][w].nd;
}
void dfs1(int v) {
  vis1[v] = 1;
  for (auto p : slo[v]) {
    int nei = p.st;
    int wh_var = p.nd;
    got[nei] = 1;
    if (vis1[nei]) { continue; }
    res[wh_var] = Get(wh_var, nei);
    dfs1(nei);
  }
}
void del(int v, int var) {
  for (int i = 0; i < SZ(slo[v]); i++) {
    if (slo[v][i].nd == var) {
      swap(slo[v][i], slo[v].back());
      slo[v].pop_back();
      return;
    }
  }
  assert(false);
}
void dfs2(int v, int e) {
  vis2[v] = 1;
  for (auto p : slo[v]) {
    int nei = p.st;
    int wh_var = p.nd;
    if (vis2[nei] && e != wh_var) {
      got[nei] = 1;
      res[wh_var] = Get(wh_var, nei);
      del(nei, wh_var);
      del(v, wh_var);
      throw nei;
    }
    if (vis2[nei] && e == wh_var) { continue; }
    dfs2(nei, wh_var);
  }
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, cl, var);
  RE (i, cl) {
    make(int, l);
    RE (j, l) {
      make(int, hehs);
      where[abs(hehs)].PB(MP(i, hehs > 0));
    }
  }
  RE (j, var) {
    if (SZ(where[j]) == 1 || (SZ(where[j]) == 2 && where[j][0].nd == where[j][1].nd)) {
      for (auto p : where[j]) {
        got[p.st] = 1;
      }
      res[j] = where[j][0].nd;
    } else if (SZ(where[j]) == 2) {
      slo[where[j][0].st].PB({where[j][1].st, j});
      slo[where[j][1].st].PB({where[j][0].st, j});
    }
  }
  RE (j, cl) {
    if (got[j] && !vis1[j]) {
      dfs1(j);
    }
  }
  RE (j, cl) {
    if (got[j] == 0) {
      int c = 0;
      try {
        dfs2(j, -1);
      } catch (int x) {
        c = x;
      }
      if (c == 0) {
        cout<<"NO\n";
        return 0;
      }
      dfs1(c);
    }
  }
//   int anduj = 1;
//   RE (j, cl) {
//     anduj &= got[j];
//   }
//   if (anduj) {
    cout<<"YES\n";
    RE (j, var) {
      cout<<res[j];
    }
    cout<<"\n";
//   } else {
//     cout<<"NO\n";
//   }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}