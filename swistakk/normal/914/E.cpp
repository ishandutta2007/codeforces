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
typedef long long LL;
int let[N];
LL ans[N];
LL sumuj[N];
int glob[1 << 20];
int heura[1 << 20][20];
typedef unordered_map<int, int> Map; 
struct CentDecomp {
  
  
  /* Start of general part */
  VVI slo;
  int n;
  VI sz, dis;
  CentDecomp(VVI& slo_, int n_) {
    slo = slo_;
    n = n_;
    sz.resize(n + 2);
    dis.resize(n + 2);

    Rec(1, n);
  }
  void Ciagnij(int v, vector<PII>& guys, int mask, int p) {
    mask ^= (1 << let[v]);
    guys.PB({v, mask});
    for (auto nei : slo[v]) {
      if (nei == p) { continue; }
      Ciagnij(nei, guys, mask, v);
    }
  }
  void Sumuj(int v, int p) {
    for (auto nei : slo[v]) {
      if (nei == p) { continue; }
      Sumuj(nei, v);
      sumuj[v] += sumuj[nei];
    }
  }
    
  void Rec(int v, int size) {
    v = CntSzCent(v, size, -1);
    dis[v] = 0;
    CntSzCent(v, size, -1);
    vector<vector<PII>> guys(SZ(slo[v]));
    vector<Map> maps(SZ(slo[v]));
    int heurz = (SZ(slo[v]) <= 20);
    
    LL S = 0;
    REP (i, SZ(slo[v])) {
      int nei = slo[v][i];
      DelEdge(nei, v);
      Ciagnij(nei, guys[i], 0, -1);
      for (auto& p : guys[i]) {
        if (heurz) {
          heura[p.nd][i]++;
          glob[p.nd]++;
        } else {
          maps[i][p.nd]++;
        }
        int xorr = p.nd ^ (1 << let[v]);
        if (xorr == 0 || (xorr & (xorr - 1)) == 0) {
          S++;
        }
      }
    }
    debug(v);
    REP (i, SZ(slo[v])) {
      debug(i, slo[v][i], guys[i]);
    }
//     guys.PB({{v, 0}});
//     Map mapka;
//     mapka[0] = 1;
//     maps.PB(mapka);
    Map summed;
    
    if (!heurz) {
      for (auto& mapa : maps) {
        for (auto& p : mapa) {
          glob[p.st] += p.nd;
  //         REP (bit, 21) {
  //           int ziomus = 1 << bit;
  //           if (bit == 20) {
  //             ziomus = 0;
  //           }
  //           int cand = (1 << let[v]) ^ ziomus ^ p.st;
  //           if (cand == 0) {
  //             debug(bit, p.st);
  //             S += p.nd;
  //           }
  //         }
          //summed[p.st] += p.nd;
        }
      }
    }
    debug(S, "bef");
    glob[0]++;
    REP (i, SZ(slo[v])) {
      auto& G = guys[i];
      for (auto& p : G) {
        REP (bit, 21) {
          int ziomus = 1 << bit;
          if (bit == 20) {
            ziomus = 0;
          }
          int cand = p.nd ^ (1 << let[v]) ^ ziomus;
          int heh = 0;
          if (heurz) {
            heh = heura[cand][i];
          } else {
            heh = maps[i][cand];
          }
          int val = glob[cand] - heh;
          sumuj[p.st] += val;
          S += val;
        }
        debug(p.st, sumuj[p.st]);
      }
      Sumuj(slo[v][i], -1);
      for (auto& p : G) {
        ans[p.st] += sumuj[p.st];
        sumuj[p.st] = 0;
      }
    }
    if (!heurz) {
      for (auto& mapa : maps) {
        for (auto& p : mapa) {
          glob[p.st] = 0;
          //summed[p.st] += p.nd;
        }
      }
    } else {
      REP (i, SZ(slo[v])) {
        for (auto& p : guys[i]) {
          heura[p.nd][i] = 0;
          glob[p.nd] = 0;
        }
      }
    }
    glob[0] = 0;
    
    debug(S, "aft");
    assert(S % 2 == 0);
    ans[v] += S / 2;
    for (int i = 0; i < SZ(slo[v]); i++) {
      int nei = slo[v][i];
      //branch[v].PB(Tree(sz[nei] + 1));
      Rec(nei, sz[nei]);
    }
  }

  int CntSzCent(int v, int size, int par) {
    sz[v] = 1;
    int ret = 0;
    for (int i = 0; i < SZ(slo[v]); i++) {
      int nei = slo[v][i];
      if (par == nei) { continue; }
      dis[nei] = dis[v] + 1;
      int cnt_rec = CntSzCent(nei, size, v);
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
      if (slo[v][i] == nei) {
        swap(slo[v][i], slo[v].back());
        slo[v].pop_back();
        return;
      }
    }
  }
};



int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  vector<vector<int>> slo(n + 1);
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  RE (i, n) {
    char c;
    cin>>c;
    let[i] = c - 'a';
  }
  
  CentDecomp cent_decomp(slo, n);
  
  RE (i, n) {
    cout<<ans[i] + 1<<" ";
  }
  cout<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}