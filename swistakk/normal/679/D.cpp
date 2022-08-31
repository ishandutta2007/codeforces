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
typedef double LD;
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

const int N = 414;
int dis[N][N];
VI slo[N];
VI rel[N][N];
LD cnt[N];
const LD kEps = 1e-9;
LD cnt_dis[N], max_on_dis[N];
bool vis[N], vis_dis[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  RE (i, n) {
    RE (j, n) {
      dis[i][j] = n + 2;
      //rel[i][j].resize(3);
    }
    dis[i][i] = 0;
  }
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
    dis[a][b] = 1;
    dis[b][a] = 1;
  }
  RE (k, n) {
    RE (i, n) {
      RE (j, n) {
        mini(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
//   RE (i, n) {
//     RE (j, n) {
//       for (auto v : slo[i]) {
//         rel[j][i][dis[j][v] - dis[j][i] + 1]++;
//       }
//     }
//   }
  
  
      VI touched;
        VI touched_dis;
  LD best_outer = 0;
  RE (fir, n) {
    VVI by_dis(n + 2);
    RE (sec, n) {
      by_dis[dis[fir][sec]].PB(sec);
    }
    LD cand_sum = 0;
    for (auto vec : by_dis) {
      if (vec.empty()) { continue; }
      touched.clear();
      debug(fir, vec);
      RE (i, n) {
        cnt[i] = 0;
      }
      LD best_inner = 1. / SZ(vec);
      for (auto v : vec) {
        for (auto nei : slo[v]) {
          if (!vis[nei]) {
            touched.PB(nei);
            vis[nei] = 1;
          }
          cnt[nei] += 1. / SZ(slo[v]) / SZ(vec);
        }
      }
      RE (sec, n) {
        touched_dis.clear();
        LD cand_here = 0;
        for (auto vv : touched) {
          int D = dis[sec][vv];
          if (!vis_dis[D]) {
            vis_dis[D] = 1;
            touched_dis.PB(D);
          }
          maxi(max_on_dis[D], cnt[vv]);
        }
        for (auto D : touched_dis) {
          cand_here += (LD) max_on_dis[D] /*/ cnt_dis[D]*/;
          max_on_dis[D] = 0;
          vis_dis[D] = 0;
        }
        debug(sec, cand_here);
        maxi(best_inner, cand_here);
      }
      debug(best_inner);
      for (auto v : touched) {
        cnt[v] = 0;
        vis[v] = 0;
      }
      cand_sum += best_inner * SZ(vec) / n;
    }
    maxi(best_outer, cand_sum);
  }
  cout<<best_outer<<endl;
        
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}