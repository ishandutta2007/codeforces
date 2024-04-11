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
typedef long long LL;
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

typedef unordered_map<int, int> M;
int m;
LL gcd(LL a, LL b, LL& x, LL& y) {
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

int Inv10;
int res;
struct CentDecomp {
  
  /* Start of general part */
  vector<VPII> slo;
  int n;
  VI sz, dis;
  struct Info {
    int cent, dist, subtr;
  };
  vector<vector<Info>> cents;
//   vector<M> summed_pref, summed_suf;
//   vector<vector<M>> branch_pref, branch_suf;
  vector<int> wei;
  CentDecomp(vector<VPII>& slo_, int n_) {
    slo = slo_;
    n = n_;/*
    summed.resize(n + 2);
    branch.resize(n + 2);*/
    sz.resize(n + 2);
    dis.resize(n + 2);
    cents.resize(n + 2);
    wei.resize(n + 2);
    Rec(0, n);
  }
  
  void Dfs(int v, int pref, int suf, int pot10, int potInv10, int par, M& prefs_added, M& sufs_added, VI& prefs_to_add, VI& sufs_to_add) {
    res = (res + prefs_added[(m - suf) % m]);
    res = (res + sufs_added[pref]);
    prefs_to_add.PB(pref);
    sufs_to_add.PB((m - suf) % m);
    pot10 = (10 * pot10) % m;
    potInv10 = (potInv10 * Inv10) % m; 
    for (auto& e : slo[v]) {
      if (e.st == par) { continue; }
      Dfs(e.st, (pot10 * e.nd + pref) % m, (suf + e.nd * potInv10) % m, pot10, potInv10, v, prefs_added, sufs_added, prefs_to_add, sufs_to_add);
    }
  }
  
  void Rec(int v, int size) {
    v = CntSzCent(v, size, -1, 0, 0);
    dis[v] = 0;
    CntSzCent(v, size, -1, v, SZ(slo[v]));
    M prefs_added, sufs_added;
    prefs_added[0] = 1;
    sufs_added[0] = 1;
    VI prefs_to_add;
    VI sufs_to_add;
    VI neis;
    debug(slo[v]);
    for (int i = 0; i < SZ(slo[v]); i++) {
      int res_bef = res;
      //branch_pref[i].clear();
      int nei = slo[v][i].st;
      DelEdge(nei, v);
      sufs_to_add.clear();
      prefs_to_add.clear();
      Dfs(nei, slo[v][i].nd % m, slo[v][i].nd * Inv10 % m, 1, Inv10, v, prefs_added, sufs_added, prefs_to_add, sufs_to_add);
      for (auto x : prefs_to_add) {
        prefs_added[x]++;
      }
      for (auto x : sufs_to_add) {
        sufs_added[x]++;
      }
      neis.PB(nei);
      debug(v, nei, res_bef, res);
      //branch[v].PB(Tree(sz[nei] + 1));
      
      //Rec(nei, sz[nei]);
    }
    //debug(v, res_bef, res);
    for (auto nei : neis) {
      Rec(nei, sz[nei]);
    }
//     branch[v].PB(Tree(2));
//     summed[v] = Tree(sz[v]);
  }

  int CntSzCent(int v, int size, int par, int root, int subtr) {
    sz[v] = 1;
    if (root) {
      cents[v].PB({root, dis[v], subtr});
    }
    int ret = 0;
    for (int i = 0; i < SZ(slo[v]); i++) {
      int nei = slo[v][i].st;
      if (v == root) {
        subtr = i;
      }
      if (par == nei) { continue; }
      dis[nei] = dis[v] + 1;
      int cnt_rec = CntSzCent(nei, size, v, root, subtr);
      sz[v] += sz[nei];
      if (cnt_rec) {
        ret = cnt_rec;
      }
    }
    if (ret == 0) {
      if (sz[v] >= size / 2) {
        return v;
      } else {
        return 0;
      }
    } else {
      return ret;
    }
  }
  
  void DelEdge(int v, int nei) {
    for (int i = 0; i < SZ(slo[v]); i++) {
      if (slo[v][i].st == nei) {
        swap(slo[v][i], slo[v].back());
        slo[v].pop_back();
        return;
      }
    }
  }
  /* End of general part */
//   void Change(int v, int x) {
//     int dif = x - wei[v];
//     wei[v] = x;
//     for (auto tr : cents[v]) {
//       branch[tr.cent][tr.subtr].Upd(tr.dist, dif);
//       summed[tr.cent].Upd(tr.dist, dif);
//     }
//   }
//   
//   int Query(int v, int d) {
//     int res = wei[v];
//     for (auto tr : cents[v]) {
//       int rem_dis = d - tr.dist;
//       if (rem_dis < 0) {
//         continue;
//       }
//       res += summed[tr.cent].Read(rem_dis);
//       res -= branch[tr.cent][tr.subtr].Read(rem_dis);
//     }
//     return res;
//   }
};
    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n>>m;
  int x;
  gcd(m, 10, x, Inv10);
  Inv10 = (Inv10 % m + m) % m;
  debug(Inv10);
  
  vector<VPII> slo(n);
  RE (i, n - 1) {
    int a, b, c;
    cin>>a>>b>>c;
    slo[a].PB({b, c});
    slo[b].PB({a, c});
  }
  CentDecomp decomp(slo, n);
  
  
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}