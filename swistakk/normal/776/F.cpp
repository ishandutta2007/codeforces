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

const int N = 1e6 + 5;

struct CentDecomp {
  
  /* Start of general part */
  VVI slo;
  int n;
  VI sz, dis;
  struct Info {
    int cent, dist, subtr;
  };
  vector<vector<Info>> cents;
  vector<int> wei;
  VI col;
  CentDecomp(VVI& slo_, int n_) {
    slo = slo_;
    n = n_;
    sz.resize(n + 2);
    dis.resize(n + 2);
    cents.resize(n + 2);
    wei.resize(n + 2);
    col.resize(n + 2);
    Rec(1, n, 1);
  }
  
  void Rec(int v, int size, int layer) {
    v = CntSzCent(v, size, -1, 0, 0);
    debug(v, size, layer);
    dis[v] = 0;
    col[v] = layer;
    assert(layer <= 20);
    CntSzCent(v, size, -1, v, SZ(slo[v]));
    for (int i = 0; i < SZ(slo[v]); i++) {
      int nei = slo[v][i];
      DelEdge(nei, v);
      Rec(nei, sz[nei], layer + 1);
    }
  }

  int CntSzCent(int v, int size, int par, int root, int subtr) {
    sz[v] = 1;
    if (root) {
      cents[v].PB({root, dis[v], subtr});
    }
    int ret = 0;
    for (int i = 0; i < SZ(slo[v]); i++) {
      int nei = slo[v][i];
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
      if (slo[v][i] == nei) {
        swap(slo[v][i], slo[v].back());
        slo[v].pop_back();
        return;
      }
    }
  }
  /* End of general part */
  
};VI slo1[N];
int nei[N];
int n;
int nxt[N];
int on_left[N];

//~ int Dis(int a, int b) {
  //~ if (a < b) {
    //~ return b - a;
  //~ }
  //~ return b - a + n;
//~ }
VI imp[N];
VVI slo2;
int ord[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int m;
  cin>>n>>m;
  if (m == 0) {
    cout<<1<<endl;
    return 0;
  }
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    slo1[a].PB(2 * i - 1);
    slo1[b].PB(2 * i);
    nei[2 * i - 1] = b;
    nei[2 * i] = a;
  }
  RE (i, n) {
    int a = i;
    int b = i + 1;
    if (i == n) {
      b = 1;
    }
    int ind = i + m;
    slo1[a].PB(2 * ind - 1);
    slo1[b].PB(2 * ind);
    nei[2 * ind - 1] = b;
    nei[2 * ind] = a;
  }
  RE (i, n) {
    sort(ALL(slo1[i]), [&](int a, int b) {
                        return nei[a] < nei[b];
                      });
    slo1[i].PB(slo1[i][0]);
    debug(i, slo1[i]);
    for (int ii = 0; ii < SZ(slo1[i]) - 1; ii++) {
      int heh = slo1[i][ii];
      if (heh % 2) {
        heh++;
      } else {
        heh--;
      }
      nxt[heh] = slo1[i][ii + 1];
    }
  }
  RE (i, 2 * (n + m)) {
    debug(i, nxt[i]);
  }
  int k = 0;
  RE (i, 2 * m) {
    if (on_left[i]) { continue; }
    k++;
    int cur = i;
    do {
      imp[k].PB(nei[cur]);
      on_left[cur] = k;
      cur = nxt[cur];
      debug(k, cur);
    } while (cur != i);
    sort(ALL(imp[k]), greater<int>());
  }
  slo2.resize(k + 2);
  RE (i, m) {
    int L = on_left[2 * i], R = on_left[2 * i - 1];
    assert(L && R);
    slo2[L].PB(R);
    slo2[R].PB(L);
  }
  assert(k - 1 == m);
  RE (i, k) {
    debug(slo2[i], imp[i]);
  }
  CentDecomp decomp(slo2, k);
  RE (i, k) {
    ord[i] = i;
  }
  sort(ord + 1, ord + k + 1, [&](int a, int b) {
                            return imp[a] < imp[b];
                            for (int ii = 0; ii < SZ(imp[a]); ii++) {
                              if (imp[a][ii] != imp[b][ii]) {
                                return imp[a][ii] < imp[b][ii];
                              }
                            }
                          });
  RE (i, k) {
    debug(i, ord[i], imp[ord[i]]);
    if (i != k) {
      debug(imp[ord[i]] < imp[ord[i + 1]]);
    }
  }
  RE (i, k) {
    //debug(ord[i]);
    cout<<decomp.col[ord[i]]<<" ";
  }
  cout<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}